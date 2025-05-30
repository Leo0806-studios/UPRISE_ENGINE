#pragma once
#ifndef UE_QUATERNION_INTERNAL_
#define UE_QUATERNION_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <intrin.h>
#include "VECTOR/VECTOR3/VECTOR3_INTERNAL.h"
#include <cmath> // Add this include at the top of the file to resolve the std::acos issue.

#endif // __INTELLISENSE__



namespace UPRISE_ENGINE {
    class Quaterion {

        __m128 Data;
    public:
        __inline float& x(void)noexcept {
            return Data.m128_f32[0];
        }
        __inline float xC(void) const noexcept {
            return Data.m128_f32[0];
        }

        __inline float& y(void)noexcept {
            return Data.m128_f32[1];
        }
        __inline float yC(void)const noexcept {
            return Data.m128_f32[1];
        }


        __inline float& z(void)noexcept {
            return Data.m128_f32[2];
        }
        __inline float zC(void)const noexcept {
            return Data.m128_f32[2];
        }


        __inline float& w(void)noexcept {
            return Data.m128_f32[3];
        }
        __inline float wC(void)const noexcept {
            return Data.m128_f32[3];
        }

        __inline void __vectorcall SetAll(float x, float y, float z, float w)noexcept {
            Data = _mm_setr_ps(x, y, z, w);
        }
        __inline void __vectorcall SetAll(__m128 data)noexcept {
            Data = data;
        }
        __inline Quaterion()noexcept :Data(_mm_setr_ps(0.0F, 0.0F, 0.0F, 1.0F)) {}
        __inline Quaterion(float w, float x, float y, float z)noexcept :Data(_mm_setr_ps(x, y, z, w)) {}
        __inline explicit Quaterion(__m128 data)noexcept :Data(data) {}

        static __inline Quaterion __vectorcall FromEulerAngles(Vector3 vec) {

            constexpr auto mask1 = _MM_SHUFFLE(1, 1, 1, 1);
            constexpr auto mask2 = _MM_SHUFFLE(2, 2, 2, 2);
            const __m128 vecData = vec.operator __m128();
            const __m128 coss = _mm_cos_ps(_mm_mul_ps(vecData, _mm_set_ps1(0.5)));
            const  __m128 sinn = _mm_sin_ps(_mm_mul_ps(vecData, _mm_set_ps1(0.5)));
            const __m128 vals = _mm_addsub_ps(
                _mm_mul_ps(
                    _mm_insert_ps(_mm_broadcastss_ps(coss), sinn, 0b01100000),
                    _mm_mul_ps(
                        _mm_insert_ps(_mm_shuffle_ps(coss, coss, mask2), sinn, 0b11110000),
                        _mm_insert_ps(_mm_shuffle_ps(coss, coss, mask1), sinn, 0b10100000)
                    )
                ),
                _mm_mul_ps(
                    _mm_insert_ps(_mm_broadcastss_ps(sinn), coss, 0b01100000),
                    _mm_mul_ps(
                        _mm_insert_ps(_mm_shuffle_ps(sinn, sinn, mask2), coss, 0b11110000),
                        _mm_insert_ps(_mm_shuffle_ps(sinn, sinn, mask1), coss, 0b10100000)
                    )
                )
            );

            return Quaterion(vals);
        }
        __inline Quaterion __vectorcall operator*(const Quaterion& other) const {//NOSONAR
            return Quaterion(
                wC() * other.wC() - xC() * other.xC() - yC() * other.yC() - zC() * other.zC(),
                wC() * other.xC() + xC() * other.wC() + yC() * other.zC() - zC() * other.yC(),
                wC() * other.yC() - xC() * other.zC() + yC() * other.wC() + zC() * other.xC(),
                wC() * other.zC() + xC() * other.yC() - yC() * other.xC() + zC() * other.wC()
            );
        }

#pragma warning(push)
#pragma warning (disable:5045)

        __inline  Vector3 __vectorcall ToRotationVector() const {



            float length = std::sqrt(wC() * wC() + xC() * xC() + yC() * yC() + zC() * zC());
            float nw = wC() / length;


            // Compute the angle
            float angle = 2.0F * std::acos(nw);

            // Compute the axis
            float s = std::sqrt(1.0F - nw * nw);
            Vector3 result{ 0,0,0 };

            if (s < 0.0001F) {
                // If s is close to zero, return the axis as (1, 0, 0)
                result = Vector3(1.0F, 0.0F, 0.0F) * angle;
            }

            else {
                float nx = xC() / length;
                float ny = yC() / length;
                float nz = zC() / length;
                result = Vector3(nx / s, ny / s, nz / s) * angle;
            }
            return result;
        }
#pragma warning(pop)
        __inline 	Vector3 __vectorcall operator*(Vector3 vec) {//NOSONAR
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

        }


        __inline  Vector3 __vectorcall Rotate(const Vector3& v) const {
            Quaterion qv(0, v.xC(), v.yC(), v.zC());
            Quaterion qconj(wC(), -xC(), -yC(), -zC());
            Quaterion result = (*this) * qv * qconj;
            auto a = Vector3(result.x(), result.y(), result.z());
            return a;
        }
    };

}
#endif