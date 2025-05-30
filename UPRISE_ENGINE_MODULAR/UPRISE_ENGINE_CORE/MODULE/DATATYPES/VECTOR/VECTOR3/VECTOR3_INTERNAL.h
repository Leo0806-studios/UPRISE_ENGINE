#pragma once
#pragma once
#ifndef UE_VECTOR3_INTERNAL_
#define UE_VECTOR3_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <intrin.h>
#endif // __INTELLISENSE__
namespace UPRISE_ENGINE {
    /// <summary>
    /// SIMD optimized Vector 3.
    /// uses __vectorcall for most methods
    /// </summary>
    class Vector3 {
    private:
        /// <summary>
        /// Data
        /// </summary>
        __m128 Data;

    public:
        Vector3()noexcept :Data(_mm_setr_ps(0.0F, 0.0F, 0.0F, 0.0F)) {}
        constexpr Vector3(const Vector3& other)noexcept :Data(other.Data) {}//NOSONAR
        Vector3(const float x, const float y, const float z)noexcept :Data(_mm_setr_ps(x, y, z, 0.0F)) {}
        explicit constexpr Vector3(const __m128 other)noexcept :Data(other) {}

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
        constexpr float& pad()  noexcept {
            return Data.m128_f32[3];
        }
        constexpr float padC() const noexcept {
            return Data.m128_f32[3];
        }
        __inline Vector3& __vectorcall operator=(const Vector3 other) noexcept {
            this->Data = other.Data;
            return *this;
        }
        __inline Vector3 __vectorcall operator+(const Vector3 other) const noexcept {//NOSONAR
            return Vector3(_mm_add_ps(this->Data, other.Data));
        }
        __inline Vector3 __vectorcall operator+(const __m128 other) const noexcept {//NOSONAR
            return Vector3(_mm_add_ps(this->Data, other));
        }
        __inline Vector3 __vectorcall operator-(const Vector3 other)const noexcept {//NOSONAR
            return Vector3(_mm_sub_ps(this->Data, other.Data));
        }
        __inline Vector3 __vectorcall operator-(const __m128 other)const noexcept {//NOSONAR
            return Vector3(_mm_sub_ps(this->Data, other));
        }
        __inline Vector3 __vectorcall operator*(const Vector3 other)const noexcept {//NOSONAR
            return  Vector3(_mm_mul_ps(this->Data, other.Data));
        }
        __inline Vector3 __vectorcall operator*(const __m128 other) const noexcept {//NOSONAR
            return  Vector3(_mm_mul_ps(this->Data, other));
        }
        __inline Vector3 __vectorcall operator*(const float f) const noexcept {//NOSONAR
            return Vector3(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
        }
        __inline Vector3 __vectorcall operator/(const Vector3 other)const noexcept {//NOSONAR
            return  Vector3(_mm_div_ps(this->Data, other.Data));
        }
        __inline Vector3 __vectorcall operator/(const __m128 other) const noexcept {//NOSONAR
            return  Vector3(_mm_div_ps(this->Data, other));
        }
        __inline Vector3 __vectorcall operator/(const float f) const noexcept {//NOSONAR
            return Vector3(_mm_div_ps(this->Data, _mm_set_ps1(f)));
        }
        __inline explicit operator __m128() noexcept {
            return this->Data;
        }

        __inline Vector3 __vectorcall CrossProduct(Vector3 b) const noexcept {
            constexpr auto mask1 = _MM_SHUFFLE(3, 0, 2, 1);
            constexpr auto mask2 = _MM_SHUFFLE(3, 1, 0, 2);
            return Vector3(
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
        __inline  Vector3 Normalize() const noexcept {
            const float mag = Magnitude();
            return Vector3(_mm_div_ps(Data, _mm_set_ps1(mag)));
        }
        __inline float __vectorcall DotProduct(Vector3 a)const noexcept {
            __m128 val = Data;

            val = _mm_mul_ps(val, a.Data);
            a.Data = _mm_movehdup_ps(val);        // broadcast elements 3,1 to 2,0
            val = _mm_add_ps(val, a.Data);
            a.Data = _mm_movehl_ps(a.Data, val); // high half -> low half
            val = _mm_add_ss(val, a.Data);

            return _mm_cvtss_f32(val);
            //return _mm_cvtss_f32(_mm_dp_ps(Data, a.Data, 0xFFFFFFF0));//Dot product. mask expludes Pad(W) from the calculation
            //TODO Verify this
        }
    };
}



#endif