#pragma once

#include <intrin.h>
#include <array>
#include "VECTOR4.h"
#include "QUATERNION.h"
#include <stdexcept>
#include "MAT.h"

namespace UPRISE_ENGINE::DATATYPES {
    template<>
    class Matrix<float, 4> {
        std::array<__m128, 4> data = {
            {_mm_setr_ps(1.0F, 0.0F, 0.0F, 0.0F),
            _mm_setr_ps(0.0F, 1.0F, 0.0F, 0.0F),
            _mm_setr_ps(0.0F, 0.0F, 1.0F, 0.0F),
            _mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F)}
        };
    public:
        Matrix()noexcept = default;

        /// <summary>
        /// constructor that sets all values to 0 except diagonal that is s
        /// </summary>
        /// <param name="s"></param>
        __inline explicit Matrix(float s) : data({
            {_mm_setr_ps(s, 0.0F, 0.0F, 0.0F),
            _mm_setr_ps(0.0F, s, 0.0F, 0.0F),
            _mm_setr_ps(0.0F, 0.0F, s, 0.0F),
            _mm_setr_ps(0.0F, 0.0F, 0.0F, s)}
}) {}

        /// <summary>
        /// constructor that accepts a quaternion and creates a Matrix from it
        /// </summary>
        /// <param name="quat"></param>
        __inline explicit Matrix(UPRISE_ENGINE::Quaterion quat) {
            __m128 quatData = _mm_load_ps(reinterpret_cast<float*>(&quat));//NOSONAR

            __m128 componentProducts1 = _mm_mul_ps(_mm_shuffle_ps(quatData, quatData, _MM_SHUFFLE(0, 2, 1, 0)), _mm_shuffle_ps(quatData, quatData, _MM_SHUFFLE(2, 2, 1, 0))); //T qxx qyy qzz qxz
            __m128 componentProducts2 = _mm_mul_ps(_mm_shuffle_ps(quatData, quatData, _MM_SHUFFLE(3, 3, 1, 0)), _mm_shuffle_ps(quatData, quatData, _MM_SHUFFLE(1, 0, 2, 1))); //T qxy qyz qwx qwy
            __m256 combinedProducts = _mm256_set_m128(componentProducts2, componentProducts1);
            componentProducts1.m128_f32[0] = quat.w() * quat.z();
            __m128 signFlips = _mm_setr_ps(-1.0F, 1.0F, 1.0F, 1.0F);

            __m256 permutedProducts = _mm256_set_m128(componentProducts2, componentProducts1);
            permutedProducts = _mm256_permutevar8x32_ps(permutedProducts, _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0)); //-V112

            data[0] = _mm_add_ps(
                _mm_setr_ps(1.0F, 0.0F, 0.0F, 0.0F),
                _mm_mul_ps(
                    _mm_add_ps(
                        _mm256_extractf128_ps(_mm256_shuffle_ps(permutedProducts, permutedProducts, _MM_SHUFFLE(0, 2, 3, 0)), 0),
                        _mm_mul_ps(
                            _mm256_extractf128_ps(_mm256_permutevar8x32_ps(permutedProducts, _mm256_setr_epi32(1, 7, 6, 0, 0, 0, 0, 0)), 0),
                            _mm_setr_ps(1.0F, -1.0F, 1.0F, 1.0F)
                        )
                    ),
                    _mm_setr_ps(-2.0F, 2.0F, 2.0F, 0.0F)
                )
            );

            data[1] = _mm_add_ps(
                _mm_setr_ps(0.0F, 1.0F, 0.0F, 0.0F),
                _mm_mul_ps(
                    _mm_add_ps(
                        _mm256_extractf128_ps(_mm256_permutevar8x32_ps(combinedProducts, _mm256_setr_epi32(4, 0, 5, 0, 0, 0, 0, 0)), 0), //-V112
                        _mm_mul_ps(
                            _mm256_extractf128_ps(_mm256_permutevar8x32_ps(permutedProducts, _mm256_setr_epi32(7, 1, 5, 0, 0, 0, 0, 0)), 0),
                            _mm_setr_ps(1.0F, 1.0F, -1.0F, 1.0F)
                        )
                    ),
                    _mm_setr_ps(2.0F, -2.0F, 2.0F, 0.0F)
                )
            );

            data[2] = _mm_add_ps(
                _mm_setr_ps(0.0F, 0.0F, 1.0F, 0.0F),
                _mm_mul_ps(
                    _mm_add_ps(
                        _mm256_extractf128_ps(_mm256_permutevar8x32_ps(combinedProducts, _mm256_setr_epi32(3, 5, 0, 0, 0, 0, 0, 0)), 0),
                        _mm_mul_ps(
                            _mm256_extractf128_ps(_mm256_permutevar8x32_ps(permutedProducts, _mm256_setr_epi32(6, 5, 0, 0, 0, 0, 0, 0)), 0),
                            _mm_setr_ps(-1.0F, 1.0F, 1.0F, 1.0F)
                        )
                    ),
                    _mm_setr_ps(2.0F, 2.0F, -2.0F, 0.0F)
                )
            );

            data[3] = _mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F);
        }

        /// <summary>
        /// constructor that initializes matrix from four __m128 rows
        /// </summary>
        __inline Matrix(__m128 row0, __m128 row1, __m128 row2, __m128 row3)noexcept 
            : data({row0, row1, row2, row3}) {} //-V2537 //-V3523

        /// <summary>
        /// static function that computes a look at matrix from the given parameters
        /// eye is the position of the camera
        /// center is the point the camera is looking at
        /// up is the up vector of the camera
        /// </summary>
        /// <param name="eye"></param>
        /// <param name="center"></param>
        /// <param name="up"></param>
        /// <returns></returns>
        __inline static Matrix __vectorcall Look_At(Vector3 eye, Vector3 center, Vector3 up) {
            center = (center - eye).Normalize();
            center.SetAt(3, -(center.DotProduct(eye)));
            up = (up.CrossProduct(center)).Normalize();
            up.SetAt(3, -(up.DotProduct(eye)));
            Vector3 right((center.CrossProduct(up)));
            right.SetAt(3, -(right.DotProduct(eye)));
            Matrix result(1.0F);
            result[0] = _mm_load_ps(reinterpret_cast<float*>(&eye));//NOSONAR
            result[1] = _mm_load_ps(reinterpret_cast<float*>(&right));//NOSONAR
            result[2] = _mm_load_ps(reinterpret_cast<float*>(&center));//NOSONAR

            return result;
        }

        /// <summary>
        /// creates a perspective matrix from the given parameters
        /// fov is the field of view in degrees
        /// aspect is the aspect ratio of the screen
        /// zNear is the near clipping plane
        /// zFar is the far clipping plane
        /// </summary>
        /// <param name="fov"></param>
        /// <param name="aspect"></param>
        /// <param name="zNear"></param>
        /// <param name="zFar"></param>
        /// <returns></returns>
        __inline static Matrix __vectorcall Perspective(float fov, float aspect, float zNear, float zFar) {
            Matrix result(0.0F);

            float zMz = zFar - zNear;

            float tanhalffov = static_cast<float>(std::tan(((fov * 0.01745329251994329576923690768489)) / 2.0F));
            __m128 perspectiveDivisors = _mm_setr_ps(tanhalffov, zMz, 1.0F, zMz);

            __m128 perspectiveMatrixValues = _mm_mul_ps(_mm_setr_ps(1.0F, -1.0F, -1.0F, -1.0F), (_mm_div_ps(_mm_setr_ps(1.0F, zFar + zNear, 1.0F, 2.0F * zFar * zNear), perspectiveDivisors)));
            result(0, 0) = 1.0F / (aspect * tanhalffov);
            result(1, 1) = perspectiveMatrixValues.m128_f32[0];
            result(2, 2) = perspectiveMatrixValues.m128_f32[1];
            result(3, 2) = perspectiveMatrixValues.m128_f32[2];
            result(2, 3) = perspectiveMatrixValues.m128_f32[3];
            return result;
        }

        /// <summary>
        /// returns a matrix whose data members contains the columns instead of the rows
        /// data[0] is col0 and such
        /// </summary>
        __inline Matrix __vectorcall RowsToCols() const {
            __m128 unpackedRow01Lo = _mm_unpacklo_ps(data[0], data[1]); // [r0.x, r1.x, r0.y, r1.y]
            __m128 unpackedRow01Hi = _mm_unpackhi_ps(data[0], data[1]); // [r0.z, r1.z, r0.w, r1.w]
            __m128 unpackedRow23Lo = _mm_unpacklo_ps(data[2], data[3]); // [r2.x, r3.x, r2.y, r3.y]
            __m128 unpackedRow23Hi = _mm_unpackhi_ps(data[2], data[3]); // [r2.z, r3.z, r2.w, r3.w]

            return Matrix(_mm_movelh_ps(unpackedRow01Lo, unpackedRow23Lo), _mm_movehl_ps(unpackedRow23Lo, unpackedRow01Lo), _mm_movelh_ps(unpackedRow01Hi, unpackedRow23Hi), _mm_movehl_ps(unpackedRow23Hi, unpackedRow01Hi));
        }

        /// <summary>
        /// operator to access the rows of the matrix
        /// provides (bad) bounds checking
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        __inline __m128& operator[](size_t i) {
            switch (i)
            {
            case 0:
                return data[0];
            case 1:
                return data[1];
            case 2:
                return data[2];
            case 3:
                return data[3];
            default:
                throw std::out_of_range("index out of range. must be smaller than 4");
            }
        }

        /// <summary>
        /// operator that accesses the elements of the matrix
        /// provides (bad) bounds checking
        /// r is the row
        /// c is the column
        /// </summary>
        /// <param name="r"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        __inline float& operator()(size_t r, size_t c) {
            return (this->operator[](r)).m128_f32[c];
        }
    };
    using Mat4 = Matrix<float, 4>;

}








