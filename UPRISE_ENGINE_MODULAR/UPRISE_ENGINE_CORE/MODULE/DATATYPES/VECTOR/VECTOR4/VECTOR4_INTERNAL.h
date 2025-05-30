#pragma once
#ifndef UE_VECTOR4_INTERNAL_
#define UE_VECTOR4_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif

#ifdef __INTELLISENSE__
#include <intrin.h>
#endif
namespace UPRISE_ENGINE {
    class Vector4 {
    private:
        /// <summary>
        /// data
        /// </summary>
        __m128 Data;
    public:
        Vector4()noexcept :Data(_mm_setr_ps(0.0F, 0.0F, 0.0F, 0.0F)) {}
        constexpr  Vector4(const Vector4& other)noexcept :Data(other.Data) {}//NOSONAR
        __inline Vector4(const float x, const float y, const float z, const float w)noexcept :Data(_mm_setr_ps(x, y, z, w)) {}
        explicit constexpr  Vector4(const __m128 other)noexcept :Data(other) {}
         constexpr float& x()  noexcept {
            return Data.m128_f32[0];
        }
        constexpr float xC() const noexcept {
            return Data.m128_f32[0];
        }
        constexpr float& y()  noexcept {
            return Data.m128_f32[1];
        }
        constexpr float yC() const noexcept {
            return Data.m128_f32[1];
        }
        constexpr float& z()  noexcept {
            return Data.m128_f32[2];
        }
        constexpr float zC() const noexcept {
            return Data.m128_f32[2];
        }
        constexpr float& w()  noexcept {
            return Data.m128_f32[3];
        }
        constexpr float wC() const noexcept {
            return Data.m128_f32[3];
        }
        __inline Vector4& __vectorcall operator=(const Vector4& other) noexcept {
            this->Data = other.Data;
            return *this;
        }
        __inline Vector4 __vectorcall operator+(const Vector4& other) const noexcept {//NOSONAR
            return Vector4(_mm_add_ps(this->Data, other.Data));
        }
        __inline Vector4 __vectorcall operator+(const __m128 other) const noexcept {//NOSONAR
            return Vector4(_mm_add_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator-(const Vector4& other)const noexcept {//NOSONAR
            return Vector4(_mm_sub_ps(this->Data, other.Data));
        }
        __inline Vector4 __vectorcall operator-(const __m128 other)const noexcept {//NOSONAR
            return Vector4(_mm_sub_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator*(const Vector4& other)const noexcept {//NOSONAR
            return  Vector4(_mm_mul_ps(this->Data, other.Data));
        }
        __inline Vector4 __vectorcall operator*(const __m128 other) const noexcept {//NOSONAR
            return  Vector4(_mm_mul_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator*(const float f) const noexcept {//NOSONAR
            return Vector4(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
        }
        __inline Vector4 __vectorcall operator/(const Vector4& other)const noexcept {//NOSONAR
            return Vector4(_mm_div_ps(this->Data, other.Data));
        }
        __inline  Vector4 __vectorcall  operator/(const __m128 other) const noexcept {//NOSONAR
            return  Vector4(_mm_div_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator/(const float f) const noexcept {//NOSONAR
            return Vector4(_mm_div_ps(this->Data, _mm_set_ps1(f)));
        }
    };
}

#endif