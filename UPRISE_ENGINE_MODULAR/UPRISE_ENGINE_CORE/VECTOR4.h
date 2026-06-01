#pragma once

#include <intrin.h>
#include <string>
#include <format>
#include <utility>
#include "VECTOR.h"
#include <ABI.h>
#include "ANOTATIONS.h"

namespace UPRISE_ENGINE::DATATYPES {
    template <>
    class Vector<float, 4> {
        __m128 Data;
    public:
        //reference acces to simd data is not allowed
        NODISCARD float& operator[](size_t index) = delete;
        float at(size_t index) const noexcept {
            ASSERT_MSG(index < 4, "index out of range");
            return Data.m128_f32[index];
        }
        Vector()noexcept :Data(_mm_setr_ps(0.0F, 0.0F, 0.0F, 0.0F)) {}
        explicit Vector(float x, float y, float z, float w)noexcept :Data(_mm_setr_ps(x, y, z, w)) {}
        explicit Vector(__m128 data)noexcept :Data(data) {}
        void Set(float x, float y, float z, float w)noexcept {
            Data = _mm_setr_ps(x, y, z, w);
        }
        void SetAt(size_t index, float value) noexcept {
            ASSERT_MSG(index < 4, "index out of range");
            Data.m128_f32[index] = value;
        }
        NODISCARD Vector& SIMD_CALL operator+(const Vector& other) noexcept {
            Data = _mm_add_ps(this->Data, other.Data);
            return *this;
        }
        NODISCARD Vector& SIMD_CALL operator-(const Vector& other) noexcept {
            Data = _mm_sub_ps(this->Data, other.Data);
            return *this;
        }
        NODISCARD Vector& SIMD_CALL operator*(const Vector& other) noexcept {
            Data = _mm_mul_ps(this->Data, other.Data);
            return *this;
        }
        NODISCARD Vector& SIMD_CALL operator/(const Vector& other) noexcept {
            Data = _mm_div_ps(this->Data, other.Data);
            return *this;
        }
        NODISCARD Vector& SIMD_CALL operator*(const float f) noexcept {
            Data = _mm_mul_ps(this->Data, _mm_set_ps1(f));
            return *this;
        }
        NODISCARD Vector& SIMD_CALL operator/(const float f) noexcept {
            Data = _mm_div_ps(this->Data, _mm_set_ps1(f));
            return *this;
        }
        NODISCARD explicit operator __m128() const noexcept {
            return this->Data;
        }
        NODISCARD float Magnitude() const noexcept {
            __m128 mul = _mm_mul_ps(this->Data, this->Data);
            __m128 shuf = _mm_shuffle_ps(mul, mul, _MM_SHUFFLE(2, 3, 0, 1));
            __m128 sums = _mm_add_ps(mul, shuf);
            shuf = _mm_movehl_ps(shuf, sums);
            sums = _mm_add_ss(sums, shuf);
            return sqrtf(sums.m128_f32[0]);
        }
        NODISCARD Vector SIMD_CALL CrossProduct(Vector other) {
            __m128 shuf1 = _mm_shuffle_ps(this->Data, this->Data, _MM_SHUFFLE(3, 0, 2, 1));
            __m128 shuf2 = _mm_shuffle_ps(other.Data, other.Data, _MM_SHUFFLE(3, 0, 2, 1));
            __m128 mul1 = _mm_mul_ps(shuf1, other.Data);
            __m128 mul2 = _mm_mul_ps(this->Data, shuf2);
            return Vector(_mm_sub_ps(mul1, mul2));
        }
        NODISCARD Vector SIMD_CALL DotProduct(Vector other) {
            __m128 mul = _mm_mul_ps(this->Data, other.Data);
            __m128 shuf = _mm_shuffle_ps(mul, mul, _MM_SHUFFLE(2, 3, 0, 1));
            __m128 sums = _mm_add_ps(mul, shuf);
            shuf = _mm_movehl_ps(shuf, sums);
            sums = _mm_add_ss(sums, shuf);
            return Vector(_mm_shuffle_ps(sums, sums, _MM_SHUFFLE(0, 0, 0, 0)));
        }
        NODISCARD Vector SIMD_CALL Normalize() {
            if (float mag = this->Magnitude(); mag > 0.0f) {
                return *this / mag;
            }
            return *this;
        }
    };
    using Vector4 = Vector<float, 4>;
}
namespace std {
    string to_string(UPRISE_ENGINE::DATATYPES::Vector4 val) {
        return format("Vactor4({} {} {} {})", val.at(0), val.at(1), val.at(2), val.at(3));
    }
    template<>
    struct hash<UPRISE_ENGINE::DATATYPES::Vector4> {
        std::size_t operator()(const UPRISE_ENGINE::DATATYPES::Vector4& v) const
        {
            uint64_t hash = 0;
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(0)));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(1)));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(2)));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(3)));
            return hash;
        }
    };
}
