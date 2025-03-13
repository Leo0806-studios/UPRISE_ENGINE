module;
#include <intrin.h>
export module UPRISE_ENGINE_CORE:VECTOR4;

export namespace UPRISE_ENGINE {
    class Vector4 {
    private:
        /// <summary>
        /// data
        /// </summary>
        __m128 Data;
    public:
        Vector4()noexcept :Data(_mm_setr_ps(0.0F, 0.0F, 0.0F, 0.0F)) {}
        constexpr __inline Vector4(const Vector4& other)noexcept :Data(other.Data) {}
        __inline Vector4(const float x, const float y, const float z, const float w)noexcept :Data(_mm_setr_ps(x, y, z, w)) {}
        explicit constexpr __inline Vector4(const __m128 other)noexcept :Data(other) {}
        __inline constexpr float& x()  noexcept {
            return Data.m128_f32[0];
        }
        __inline constexpr float xC() const noexcept {
            return Data.m128_f32[0];
        }
        __inline constexpr float& y()  noexcept {
            return Data.m128_f32[1];
        }
        __inline constexpr float yC() const noexcept {
            return Data.m128_f32[1];
        }
        __inline constexpr float& z()  noexcept {
            return Data.m128_f32[2];
        }
        __inline constexpr float zC() const noexcept {
            return Data.m128_f32[2];
        }
        __inline constexpr float& w()  noexcept {
            return Data.m128_f32[3];
        }
        __inline constexpr float wC() const noexcept {
            return Data.m128_f32[3];
        }
        __inline Vector4& __vectorcall operator=(const Vector4& other) noexcept {
            this->Data = other.Data;
            return *this;
        }
        __inline Vector4 __vectorcall operator+(const Vector4& other) const noexcept {
            return Vector4(_mm_add_ps(this->Data, other.Data));
        }
        __inline Vector4 __vectorcall operator+(const __m128 other) const noexcept {
            return Vector4(_mm_add_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator-(const Vector4& other)const noexcept {
            return Vector4(_mm_sub_ps(this->Data, other.Data));
        }
        __inline Vector4 __vectorcall operator-(const __m128 other)const noexcept {
            return Vector4(_mm_sub_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator*(const Vector4& other)const noexcept {
            return  Vector4(_mm_mul_ps(this->Data, other.Data));
        }
        __inline Vector4 __vectorcall operator*(const __m128 other) const noexcept {
            return  Vector4(_mm_mul_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator*(const float f) const noexcept {
            return Vector4(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
        }
        __inline Vector4 __vectorcall operator/(const Vector4& other)const noexcept {
            return Vector4(_mm_div_ps(this->Data, other.Data));
        }
         __inline  Vector4 __vectorcall  operator/(const __m128 other) const noexcept {
            return  Vector4(_mm_div_ps(this->Data, other));
        }
        __inline Vector4 __vectorcall operator/(const float f) const noexcept {
            return Vector4(_mm_div_ps(this->Data, _mm_set_ps1(f)));
        }
    };
}