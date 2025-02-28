// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#ifndef UE_QUATERION_
#define UE_QUATERION_

#include <GLOBAL/GLINCLUDES.h>
#include <intrin.h>
#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#pragma warning(push)
#pragma warning(disable: 4514)

namespace UPRISE_ENGINE {
#pragma region Quaterion
    /// <summary>
    /// stores a quaternion in a __m128
    /// </summary>
    class  UPRISE_CORE_API Quaternion {
        /// <summary>
        /// data
        /// </summary>
        __m128 Data;
    public:
#pragma region getter
        /// <summary>
        /// getter for x
        /// </summary>
        /// <returns></returns>
        __inline  float x() const {
            return Data.m128_f32[0];
        }
        /// <summary>
        /// getter for y
        /// </summary>
        /// <returns></returns>
        __inline  float y() const {
            return Data.m128_f32[1];

        }
        /// <summary>
        /// getter for z
        /// /// </summary>
        /// <returns></returns>
        __inline  float z() const {
            return Data.m128_f32[2];

        }
        /// <summary>
        /// getter for w
        /// </summary>
        /// <returns></returns>
        __inline  float w() const {
            return Data.m128_f32[3];

        }
#pragma endregion
#pragma region setter
        //set vals

        /// <summary>
        /// setter for x
        /// sets x to the value of x
        /// returns the new value of x
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        __inline  float x(const float x) {
            reinterpret_cast<float*>(&Data)[0] = x;
            return x;
        }
        /// <summary>
        /// setter for y
        /// sets y to the value of y
        /// returns the new value of y
        /// </summary>
        /// /// <param name="y"></param>
        /// <returns></returns>
        __inline  float y(const float y) {
            reinterpret_cast<float*>(&Data)[1] = y;
            return y;

        }
        /// <summary>
        /// setter for z
        /// sets z to the value of z
        /// returns the new value of z
        /// </summary>
        /// <param name="z"></param>
        /// <returns></returns>
        /// 
        __inline  float z(const float z) {
            reinterpret_cast<float*>(&Data)[2] = z;
            return z;


        }
        /// <summary>
    /// setter for w
    /// sets w to the value of w
    /// returns the new value of w
    /// </summary>
    /// <param name="w"></param>
    /// <returns></returns>
        __inline  float w(const float w) {
            reinterpret_cast<float*>(&Data)[3] = w;
            return w;

        }
#pragma endregion


#pragma region Constructor
        /// <summary>
        /// constructor for identity quaterion 
        /// x = 0
        /// y = 0
        /// z = 0
        /// w = 1
        /// </summary>

        Quaternion() {
            Data = _mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F);
            //	w(1); x(0); y(0); z(0);
        }
        /// <summary>
        /// constructor for quaterion with values
        /// w = w
        /// x = x
        /// y = y
        /// z = z
        /// </summary>
        /// <param name="w"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="z"></param>
        Quaternion(float w, float x, float y, float z) {
            Data = _mm_setr_ps(x, y, z, w);
            /// this->w(w); this->x(x); this->y(y); this->z(z); 

        }
        /// <summary>
        /// constructor that takes a __m128
        /// </summary>
        /// <param name="other"></param>
        Quaternion(__m128 other) {
            this->Data = other;

        }
#pragma endregion
#pragma region operator
#pragma region nonConst

#pragma endregion
#pragma region Const

#pragma endregion


#pragma endregion





#pragma region Funcs

#pragma endregion


        /// <summary>
        /// static function that returns a quaternion from a vector 3
        /// </summary>
        /// <param name="vec"></param>
        /// <returns></returns>
        static __inline  Quaternion FromEulerAngles(Vector3 vec) {

            __m128 coss = _mm_cos_ps(_mm_mul_ps(vec.operator __m128(), _mm_set_ps1(0.5)));
            __m128 sinn = _mm_sin_ps(_mm_mul_ps(vec.operator __m128(), _mm_set_ps1(0.5)));
            __m128 vals = _mm_addsub_ps(
                _mm_mul_ps(
                    _mm_insert_ps(_mm_broadcastss_ps(coss), sinn, 0b01100000),
                    _mm_mul_ps(
                        _mm_insert_ps(_mm_shuffle_ps(coss, coss, _MM_SHUFFLE(2, 2, 2, 2)), sinn, 0b11110000),
                        _mm_insert_ps(_mm_shuffle_ps(coss, coss, _MM_SHUFFLE(1, 1, 1, 1)), sinn, 0b10100000)
                    )
                ),
                _mm_mul_ps(
                    _mm_insert_ps(_mm_broadcastss_ps(sinn), coss, 0b01100000),
                    _mm_mul_ps(
                        _mm_insert_ps(_mm_shuffle_ps(sinn, sinn, _MM_SHUFFLE(2, 2, 2, 2)), coss, 0b11110000),
                        _mm_insert_ps(_mm_shuffle_ps(sinn, sinn, _MM_SHUFFLE(1, 1, 1, 1)), coss, 0b10100000)
                    )
                )
            );
            return Quaternion(vals);

        }

        /// <summary>
        /// operator that multiplies two quaternions
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Quaternion operator*(const Quaternion& other) const {
            return Quaternion(
                w() * other.w() - x() * other.x() - y() * other.y() - z() * other.z(),
                w() * other.x() + x() * other.w() + y() * other.z() - z() * other.y(),
                w() * other.y() - x() * other.z() + y() * other.w() + z() * other.x(),
                w() * other.z() + x() * other.y() - y() * other.x() + z() * other.w()
            );
        }
#pragma warning (push)
#pragma warning (disable:5045)

        /// <summary>
        /// transforms a quaternion to a vector3 
        /// </summary>
        /// <returns></returns>
        __inline  Vector3 ToRotationVector() const {



            float length = std::sqrt(w() * w() + x() * x() + y() * y() + z() * z());
            float nw = w() / length;


            // Compute the angle
            float angle = 2.0F * std::acos(nw);

            // Compute the axis
            float s = std::sqrt(1.0F - nw * nw);
            Vector3 result{};

            if (s < 0.0001F) {
                // If s is close to zero, return the axis as (1, 0, 0)
                result= Vector3(1.0F, 0.0F, 0.0F) * angle;
            }

            else {
                float nx = x() / length;
                float ny = y() / length;
                float nz = z() / length;
                result= Vector3(nx / s, ny / s, nz / s) * angle;
            }
            return result;
        }

#pragma warning (pop)

        /// <summary>
        /// multiply a quaternion with a vector3
        /// </summary>
        /// <param name="vec"></param>
        /// <returns></returns>
        __inline 	Vector3 operator*(Vector3 vec) {
            float num = x() * 2.0F;
            float num2 = y() * 2.0F;
            float num3 = z() * 2.0F;
            float num4 = x() * num;
            float num5 = y() * num2;
            float num6 = z() * num3;
            float num7 = x() * num2;
            float num8 = x() * num3;
            float num9 = y() * num3;
            float num10 = w() * num;
            float num11 = w() * num2;
            float num12 = w() * num3;
            return Vector3{ (1.0F - (num5 + num6)) * vec.x() + (num7 - num12) * vec.y() + (num8 + num11) * vec.z() ,
                 (num7 + num12) * vec.x() + (1.0F - (num4 + num6)) * vec.y() + (num9 - num10) * vec.z() ,
             (num8 - num11) * vec.x() + (num9 + num10) * vec.y() + (1.0F - (num4 + num5)) * vec.z()
            };
            //result.x() = (1 - (num5 + num6)) * vec.x() + (num7 - num12) * vec.y() + (num8 + num11) * vec.z();
            //result.y() = (num7 + num12) * vec.x() + (1 - (num4 + num6)) * vec.y() + (num9 - num10) * vec.z();
            //result.z() = (num8 - num11) * vec.x() + (num9 + num10) * vec.y() + (1 - (num4 + num5)) * vec.z();
            //return result;
        }

        /// <summary>
        /// rotate the quaterion with a vector3
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        __inline  Vector3 Rotate(const Vector3& v) const {
            Quaternion qv(0, v.x(), v.y(), v.z());
            Quaternion qconj(w(), -x(), -y(), -z());
            Quaternion result = (*this) * qv * qconj;
            auto a = Vector3(result.x(), result.y(), result.z());
            return a;
        }
        /// <summary>
        /// casts the quaternion to a mat4 with glm::mat4_cast(glm::quat(w(), x(), y(), z()));
        /// </summary>
        /// <returns></returns>
        __inline  glm::mat4 ToMat4() const {
            return glm::mat4_cast(glm::quat(w(), x(), y(), z()));
        }

    };
#pragma endregion
}
#pragma warning(pop)
#endif // !_QUATERION_

