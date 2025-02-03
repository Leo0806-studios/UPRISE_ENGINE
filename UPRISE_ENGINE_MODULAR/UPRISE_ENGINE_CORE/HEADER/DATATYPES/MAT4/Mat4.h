// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Mat4_
#define UE_Mat4_

#include "GLOBAL/GLINCLUDES.h"
#include "DATATYPES/VECTOR/VECTOR4/VECTOR4.h";
#include "intrin.h"
#include "DATATYPES/QUTERION/QUATERION.h";

import REF_WRAPPER; //-V3549 //-V2575
import std; //-V3549 //-V2575
namespace UPRISE_ENGINE {
    /// <summary>
/// Mat4 is a 4x4 matrix class that is used for transformations in 3D space
/// strores its data in 4 __m128 vectors
/// as rows
/// </summary>
    class UPRISE_CORE_API Mat4 {

    public:
        /// <summary>
        /// data of the matrix
        /// </summary>
        __m128 row0, row1, row2, row3;
        /// <summary>
        /// constructor that sets all values to 0 exept a diagonal that is s
        /// </summary>
        /// <param name="s"></param>
        __inline Mat4(float s) :row0(_mm_setr_ps(s, 0.0F, 0.0F, 0.0F)), row1(_mm_setr_ps(0.0F, s, 0.0F, 0.0F)), row2(_mm_setr_ps(0.0F, 0.0F, s, 0.0F)), row3(_mm_setr_ps(0.0F, 0.0F, 0.0F, s)) {}
        /// <summary>
        /// constructor that accsepts a quaterion and creates a MAt4 from it
        /// </summary>
        /// <param name="quat"></param>
        __inline Mat4(Quaternion quat) {
            __m128 One = _mm_load_ps(reinterpret_cast<float*>(&quat));


            __m128 Two = _mm_mul_ps(_mm_shuffle_ps(One, One, _MM_SHUFFLE(0, 2, 1, 0)), _mm_shuffle_ps(One, One, _MM_SHUFFLE(2, 2, 1, 0))); //T qxx qyy qzz qxz
            __m128 Three = _mm_mul_ps(_mm_shuffle_ps(One, One, _MM_SHUFFLE(3, 3, 1, 0)), _mm_shuffle_ps(One, One, _MM_SHUFFLE(1, 0, 2, 1))); //T qxy qyz qwx qwy
            __m256 Four = _mm256_set_m128(Three, Two);
            Two.m128_f32[0] = quat.w() * quat.z();
            //Two = _mm_shuffle_ps(Two, Two, _MM_SHUFFLE(0, 3, 2, 1));
            __m128 Five = _mm_setr_ps(-1.0F, 1.0F, 1.0F, 1.0F);

            __m256 Six = _mm256_set_m128(Three, Two);
            Six = _mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0));



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
                        _mm256_extractf128_ps(_mm256_permutevar8x32_ps(Four, _mm256_setr_epi32(4, 0, 5, 0, 0, 0, 0, 0)), 0),
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

        __inline static  Mat4 Look_At(Vector3 eye, Vector3 center, Vector3 up) {
            //TrPr(ctx,__func__)
            center = (center - eye).Normalized();
            center.pad(-(center.Point(eye))) ;
            up = (up ^ center).Normalized();
            up.pad(-(up.Point(eye)));
            Vector3 u((center ^ up));
            u.pad(-(u.Point(eye))) ;
            Mat4 result(1);
            result[0] = _mm_load_ps(reinterpret_cast<float*>( & up));
            result[1] = _mm_load_ps(reinterpret_cast<float*>(&u));
            result[2] = _mm_load_ps(reinterpret_cast<float*>(&center));

            //TrPrE(ctx)
            return result;
        }
        /// <summary>
        /// static function that computes a look at matrix from the given parameters
        /// eye is the position of the camera
        /// center is the point the camera is looking at
        /// up is the up vector of the camera
        /// directly returns a glm::mat4
        /// </summary>
        /// <param name="eye"></param>
        /// <param name="center"></param>
        /// <param name="up"></param>
        /// <returns></returns>

        __forceinline static  glm::mat4 Look_At_GLM(Vector3 eye, Vector3 center, Vector3 up) {
            //TrPr(ctx,__func__)
            center = (center - eye).Normalized();
            center.pad(-(center.Point(eye)))  ;
            up = (up ^ center).Normalized();
            up.pad(-(up.Point(eye)))  ;
            Vector3 u((center ^ up));
            u.pad(-(u.Point(eye)))  ;
            __m256i suffle = _mm256_setr_epi32(0, 1, 4, 5, 2, 3, 6, 7);
            __m256 mlti = _mm256_set_ps(1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F);

            __m128 row3(_mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F));

            __m256 One = _mm256_set_m128(_mm_unpacklo_ps(center, row3), _mm_unpacklo_ps(up, u));

            __m256 Two = _mm256_set_m128(_mm_unpackhi_ps(center, row3), _mm_unpackhi_ps(up, u));
            One = _mm256_mul_ps(One, mlti);
            Two = _mm256_mul_ps(Two, mlti);
            One = _mm256_permutevar8x32_ps(One, suffle);
            Two = _mm256_permutevar8x32_ps(Two, suffle);
            glm::mat4 ret{};
            ret;
            _mm256_store_ps(&ret[0].x, One);
            _mm256_store_ps(&ret[2].x, Two);

            //alignas(32) glm::vec4 col0[2];
            //alignas(32) glm::vec4 col1[2];
            //_mm256_store_ps(&col0[0].x, One);
            //_mm256_store_ps(&col1[0].x, Two);

            return ret;//glm::mat4(col0[0], col0[1], col1[0], col1[1]);;
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
        __inline static Mat4 Perspective(float fov, float aspect, float zNear, float zFar) {
            TrPr(ctx, __func__)
                Mat4 result(0);

            float zMz = zFar - zNear;

            float tanhalffov = tan(((fov * 0.01745329251994329576923690768489)) / 2.0F);
            __m128 tst = _mm_setr_ps(tanhalffov, zMz, 1.0F, zMz);


            __m128 bottom3 = _mm_mul_ps(_mm_setr_ps(1.0F, -1.0F, -1.0F, -1.0F), (_mm_div_ps(_mm_setr_ps(1.0F, zFar + zNear, 1.0F, 2.0F * zFar * zNear), tst)));
            result(0, 0) = 1.0F / (aspect * tanhalffov);
            result(1, 1) = bottom3.m128_f32[0];
            result(2, 2) = bottom3.m128_f32[1];
            result(3, 2) = bottom3.m128_f32[2];
            result(2, 3) = bottom3.m128_f32[3];
            TrPrE(ctx)
                return result;

        }
        /// <summary>
        /// transposes the Mat4 to a glm::mat4 using _MM_TRANSPOSE4_PS and then returns the glm::mat4
        /// </summary>
        /// <returns></returns>
        __inline glm::mat4 ToMat4glm() {
            _MM_TRANSPOSE4_PS(row0, row1, row2, row3);


            return glm::mat4(Vector4(row0).operator glm::vec<4, float, glm::packed_highp>(),
                Vector4(row1).operator glm::vec<4, float, glm::packed_highp>(),
                Vector4(row1).operator glm::vec<4, float, glm::packed_highp>(),
                Vector4(row1).operator glm::vec<4, float, glm::packed_highp>());
        }
        /// <summary>
        /// opperator that implicitly converts a Mat4 to a glm::mat4
        /// usis a slitgtly differebt method than ToMat4glm
        /// </summary>
        __inline operator glm::mat4() {
            TrPr(ctx, __func__)

                __m128 tmp0 = _mm_unpacklo_ps(row0, row1); // [r0.x, r1.x, r0.y, r1.y]
            __m128 tmp1 = _mm_unpackhi_ps(row0, row1); // [r0.z, r1.z, r0.w, r1.w]
            __m128 tmp2 = _mm_unpacklo_ps(row2, row3); // [r2.x, r3.x, r2.y, r3.y]
            __m128 tmp3 = _mm_unpackhi_ps(row2, row3); // [r2.z, r3.z, r2.w, r3.w]

            // Step 2: Unpack and interleave to get the final column vectors
            glm::vec4 col0;
            glm::vec4 col1;
            glm::vec4 col2;
            glm::vec4 col3;
            _mm_store_ps(&col0.x, _mm_movelh_ps(tmp0, tmp2)); // [r0.x, r1.x	 r2.x, r3.x]
            _mm_store_ps(&col1.x, _mm_movehl_ps(tmp2, tmp0)); // [r0.y, r1.y, r2.y, r3.y]
            _mm_store_ps(&col2.x, _mm_movelh_ps(tmp1, tmp3)); // [r0.z, r1.z, r2.z, r3.z]
            _mm_store_ps(&col3.x, _mm_movehl_ps(tmp3, tmp1)); // [r0.w, r1.w, r2.w, r3.w]
            TrPrE(ctx)

                return glm::mat4(col0, col1, col2, col3);
        }

        /// <summary>
        /// operator tj accses the rows of the matrix
        /// provides (bad)  bounds checking
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        __inline __m128& operator[](Index i) {

            if (i > 3)
            {
                //Log << "OUT Of RANGE!\n" << "trying to accses memory at: " << &(((__m128*)this)[i]) << "wich is outside the bounds of the mat4" << "\n";
                int i = *static_cast<int*>(nullptr); //throw error

            }
          return  reinterpret_cast<__m128*>(this)[i];
            //return (((__m128*)this)[i]);
        }
        /// <summary>
        /// operator that accses the elements of the matrix
        /// provides (bad) bounds checking
        /// r is the row
        /// c is the collumn
        /// </summary>
        /// <param name="r"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        __inline float& operator()(Index r, int c) {
            return (this->operator[](r)).m128_f32[c];

        }
    };
}

#endif // !_Mat4_
