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
        std::array<__m128, 4> data = { {_mm_setzero_ps(),_mm_setzero_ps(),_mm_setzero_ps(),_mm_setzero_ps()} };
    public:
        Matrix()noexcept = default;
    };
    using Mat4 = Matrix<float, 4>;
}

namespace UPRISE_ENGINE {

    class  Mat4 {

    public:
        Mat4()noexcept {
            row0 = _mm_setr_ps(1.0F, 0.0F, 0.0F, 0.0F);
            row1 = _mm_setr_ps(0.0F, 1.0F, 0.0F, 0.0F);
            row2 = _mm_setr_ps(0.0F, 0.0F, 1.0F, 0.0F);
            row3 = _mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F);
        }
        /// <summary>
        /// data of the matrix
        /// </summary>
        __m128 row0, row1, row2, row3;//NOSONAR
        /// <summary>
        /// constructor that sets all values to 0 exept a diagonal that is s
        /// </summary>
        /// <param name="s"></param>
        __inline explicit Mat4(float s) :row0(_mm_setr_ps(s, 0.0F, 0.0F, 0.0F)), row1(_mm_setr_ps(0.0F, s, 0.0F, 0.0F)), row2(_mm_setr_ps(0.0F, 0.0F, s, 0.0F)), row3(_mm_setr_ps(0.0F, 0.0F, 0.0F, s)) {} //-V2537 //-V3523
        /// <summary>
        /// constructor that accsepts a quaterion and creates a MAt4 from it
        /// </summary>
        /// <param name="quat"></param>
        __inline explicit Mat4(Quaterion quat) {
            __m128 One = _mm_load_ps(reinterpret_cast<float*>(&quat));//NOSONAR


            __m128 Two = _mm_mul_ps(_mm_shuffle_ps(One, One, _MM_SHUFFLE(0, 2, 1, 0)), _mm_shuffle_ps(One, One, _MM_SHUFFLE(2, 2, 1, 0))); //T qxx qyy qzz qxz
            __m128 Three = _mm_mul_ps(_mm_shuffle_ps(One, One, _MM_SHUFFLE(3, 3, 1, 0)), _mm_shuffle_ps(One, One, _MM_SHUFFLE(1, 0, 2, 1))); //T qxy qyz qwx qwy
            __m256 Four = _mm256_set_m128(Three, Two);
            Two.m128_f32[0] = quat.w() * quat.z();
            //Two = _mm_shuffle_ps(Two, Two, _MM_SHUFFLE(0, 3, 2, 1));
            __m128 Five = _mm_setr_ps(-1.0F, 1.0F, 1.0F, 1.0F);

            __m256 Six = _mm256_set_m128(Three, Two);
            Six = _mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0)); //-V112



            row0 = _mm_add_ps(
                _mm_setr_ps(1.0F, 0.0F, 0.0F, 0.0F),
                _mm_mul_ps(
                    _mm_add_ps(
                        _mm256_extractf128_ps(_mm256_shuffle_ps(Six, Six, _MM_SHUFFLE(0, 2, 3, 0)), 0),
                        _mm_mul_ps(
                            _mm256_extractf128_ps(_mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(1, 7, 6, 0, 0, 0, 0, 0)), 0),
                            //_mm_shuffle_ps(Five, Five,_MM_SHUFFLE(3,2,0,1))
                            _mm_setr_ps(1.0F, -1.0F, 1.0F, 1.0F)
                        )
                    ),
                    _mm_setr_ps(-2.0F, 2.0F, 2.0F, 0.0F)
                )
            );

            row1 = _mm_add_ps(
                _mm_setr_ps(0.0F, 1.0F, 0.0F, 0.0F),
                _mm_mul_ps(
                    _mm_add_ps(
                        _mm256_extractf128_ps(_mm256_permutevar8x32_ps(Four, _mm256_setr_epi32(4, 0, 5, 0, 0, 0, 0, 0)), 0), //-V112
                        _mm_mul_ps(
                            _mm256_extractf128_ps(_mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(7, 1, 5, 0, 0, 0, 0, 0)), 0),
                            //_mm_shuffle_ps(Five, Five, _MM_SHUFFLE(3, 0, 2, 1))

                            _mm_setr_ps(1.0F, 1.0F, -1.0F, 1.0F)
                        )
                    ),
                    _mm_setr_ps(2.0F, -2.0F, 2.0F, 0.0F)
                )
            );


            //
            row2 = _mm_add_ps(
                _mm_setr_ps(0.0F, 0.0F, 1.0F, 0.0F),
                _mm_mul_ps(
                    _mm_add_ps(
                        _mm256_extractf128_ps(_mm256_permutevar8x32_ps(Four, _mm256_setr_epi32(3, 5, 0, 0, 0, 0, 0, 0)), 0),
                        _mm_mul_ps(
                            _mm256_extractf128_ps(_mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(6, 5, 0, 0, 0, 0, 0, 0)), 0),
                            //_mm_shuffle_ps(Five, Five, _MM_SHUFFLE(0, 3, 2, 1))

                            _mm_setr_ps(-1.0F, 1.0F, 1.0F, 1.0F)
                        )
                    ),
                    _mm_setr_ps(2.0F, 2.0F, -2.0F, 0.0F)
                )
            );


            row3 = _mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F);
        }


        __inline Mat4(__m128 row1, __m128 row2, __m128 row3, __m128 row4)noexcept :row0(row1), row1(row2), row2(row3), row3(row4) {} //-V2537 //-V3523
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

        __inline static  Mat4 __vectorcall Look_At(Vector3 eye, Vector3 center, Vector3 up) {
            center = (center - eye).Normalize();
            center.pad() = -(center.DotProduct(eye));
            up = (up.CrossProduct(center)).Normalize();
            up.pad() = -(up.DotProduct(eye));
            Vector3 u((center.CrossProduct(up)));
            u.pad() = -(u.DotProduct(eye));
            Mat4 result(1);
            result[0] = _mm_load_ps(reinterpret_cast<float*>(&up));//NOSONAR
            result[1] = _mm_load_ps(reinterpret_cast<float*>(&u));//NOSONAR
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
        __inline static Mat4 __vectorcall Perspective(float fov, float aspect, float zNear, float zFar) {
            Mat4 result(0);

            float zMz = zFar - zNear;

            float tanhalffov = static_cast<float>(std::tan(((fov * 0.01745329251994329576923690768489)) / 2.0F));
            __m128 tst = _mm_setr_ps(tanhalffov, zMz, 1.0F, zMz);

            __m128 bottom3 = _mm_mul_ps(_mm_setr_ps(1.0F, -1.0F, -1.0F, -1.0F), (_mm_div_ps(_mm_setr_ps(1.0F, zFar + zNear, 1.0F, 2.0F * zFar * zNear), tst)));
            result(0, 0) = 1.0F / (aspect * tanhalffov);
            result(1, 1) = bottom3.m128_f32[0];
            result(2, 2) = bottom3.m128_f32[1];
            result(3, 2) = bottom3.m128_f32[2];
            result(2, 3) = bottom3.m128_f32[3];
            return result;

        }

        /// <summary>
        /// retruns a mat4 whos datamebers contains the collums insted of the rows
        /// row0 is coll0 and such
        /// </summary>
        __inline Mat4 __vectorcall RowsToCols() const {

            __m128 tmp0 = _mm_unpacklo_ps(row0, row1); // [r0.x, r1.x, r0.y, r1.y]
            __m128 tmp1 = _mm_unpackhi_ps(row0, row1); // [r0.z, r1.z, r0.w, r1.w]
            __m128 tmp2 = _mm_unpacklo_ps(row2, row3); // [r2.x, r3.x, r2.y, r3.y]
            __m128 tmp3 = _mm_unpackhi_ps(row2, row3); // [r2.z, r3.z, r2.w, r3.w]




            return Mat4(_mm_movelh_ps(tmp0, tmp2), _mm_movehl_ps(tmp2, tmp0), _mm_movelh_ps(tmp1, tmp3), _mm_movehl_ps(tmp3, tmp1));
        }

        /// <summary>
        /// operator tj accses the rows of the matrix
        /// provides (bad)  bounds checking
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        __inline __m128& operator[](Index i) {

            switch (i)
            {
            case 0:
                return row0;
                break;
            case 1:
                return row1;
                break;
            case 2:
                return row2;
                break;
            case 3:
                return row3;
                break;
            default:
                throw std::out_of_range("index out of range. must be smaler than 4");
                break;
            }

        }
        /// <summary>
        /// operator that accses the elements of the matrix
        /// provides (bad) bounds checking
        /// r is the row
        /// c is the collumn
        /// </summary>
        /// <param   name="r"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        __inline float& operator()(Index r, Index c) {
            return (this->operator[](r)).m128_f32[c];

        }
    };

}



