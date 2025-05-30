#pragma once
#pragma once
#ifndef UE_VECTOR2_INTERNAL_
#define UE_VECTOR2_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <intrin.h>
#endif
namespace UPRISE_ENGINE {
    class Vector2 {
    private:
        /// <summary>
        /// data
        /// </summary>
        __m128 Data;
    public:
        Vector2() noexcept :Data() {}//NOSONAR
        Vector2(float x, float y) noexcept :Data(_mm_setr_ps(x, y, x, y)) {}
        explicit Vector2(const __m128& other) noexcept :Data(other) {}
        Vector2(const Vector2& other) noexcept :Data(other.Data) {}//NOSONAR
        __inline float& x() noexcept {
            return Data.m128_f32[0];
        }
        __inline float xC() const noexcept {
            return Data.m128_f32[0];
        }
        __inline float& y() noexcept {
            return Data.m128_f32[1];
        }
        __inline float yC() const noexcept {
            return Data.m128_f32[1];
        }
        __inline float& xx() noexcept {
            return Data.m128_f32[2];
        }
        __inline float xxC() const noexcept {
            return Data.m128_f32[2];
        }
        __inline float& yy() noexcept {
            return Data.m128_f32[3];
        }
        __inline float yyC() const noexcept {
            return Data.m128_f32[3];
        }
        __inline  Vector2& __vectorcall operator=(const Vector2 other) {
            this->Data = other.Data;
            return *this;
        }
        __inline Vector2 __vectorcall operator+(const Vector2 other) const noexcept {//NOSONAR
            return Vector2(_mm_add_ps(this->Data, other.Data));
        }
        __inline Vector2 __vectorcall  operator+(const __m128 other) const noexcept {//NOSONAR
            return Vector2(_mm_add_ps(this->Data, other));
        }
        __inline Vector2 __vectorcall operator-(const Vector2 other) const noexcept {//NOSONAR
            return Vector2(_mm_sub_ps(this->Data, other.Data));
        }
        __inline Vector2 __vectorcall operator-(const __m128 other) const noexcept {//NOSONAR
            return Vector2(_mm_sub_ps(this->Data, other));
        }
        __inline Vector2 __vectorcall operator*(const Vector2 other) const noexcept {//NOSONAR
            return Vector2(_mm_mul_ps(this->Data, other.Data));
        }
        __inline Vector2 __vectorcall operator*(const __m128 other) const noexcept {//NOSONAR
            return Vector2(_mm_mul_ps(this->Data, other));
        }
        __inline Vector2 __vectorcall operator*(const float f) const noexcept {//NOSONAR
            return Vector2(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
        }
        __inline Vector2 __vectorcall operator/(const Vector2 other) const noexcept {//NOSONAR
            return Vector2(_mm_div_ps(this->Data, other.Data));
        }
        __inline Vector2 __vectorcall operator/(const __m128 other) const noexcept {//NOSONAR
            return Vector2(_mm_div_ps(this->Data, other));
        }
        __inline Vector2 __vectorcall operator/(const float f) const noexcept {//NOSONAR
            return Vector2(_mm_div_ps(this->Data, _mm_set_ps1(f)));
        }
        __inline Vector2 __vectorcall CrossProduct(const Vector2 b) const noexcept {
            constexpr auto mask1 = _MM_SHUFFLE(3, 0, 2, 1);
            constexpr auto mask2 = _MM_SHUFFLE(3, 1, 0, 2);
            return Vector2(
                _mm_fnmadd_ps(
                    _mm_shuffle_ps(
                        Data,
                        Data,
                        mask2
                    ),
                    _mm_shuffle_ps(
                        b.Data,
                        b.Data,
                        mask1
                    ),
                    _mm_mul_ps(
                        _mm_shuffle_ps(
                            Data,
                            Data,
                            mask1
                        ),
                        _mm_shuffle_ps(
                            b.Data,
                            b.Data,
                            mask2
                        )
                    )
                )
            );
        }

        __inline  float Magnitude() const noexcept {
            __m128 val2 = Data;
            __m128 shuf = _mm_movehdup_ps(val2);
            val2 = _mm_fmadd_ps(val2, val2, shuf);
            shuf = _mm_movehl_ps(shuf, val2);
            val2 = _mm_add_ss(val2, shuf);
            val2 = _mm_sqrt_ps(val2);

            return _mm_cvtss_f32(val2);
        }


        __inline float __vectorcall DotProduct(const Vector2 other) const noexcept {
            __m128 val2 = _mm_mul_ps(this->Data, other.Data);
            __m128 shuf = _mm_movehdup_ps(val2);
            val2 = _mm_add_ss(val2, shuf);
            shuf = _mm_movehl_ps(shuf, val2);
            val2 = _mm_add_ss(val2, shuf);
            return _mm_cvtss_f32(val2);
        }
    };

}


#endif