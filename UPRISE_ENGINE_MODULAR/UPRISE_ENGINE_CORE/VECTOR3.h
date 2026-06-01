#pragma once

#include <intrin.h>
#include <string>
#include <utility>
#include <format>
#include "VECTOR.h"
#include <ABI.h>
#include "ANOTATIONS.h"
#include "UTILITIES.h"

namespace UPRISE_ENGINE::DATATYPES {
    enum class Vector3Index : uint8_t {
        X = 0,
        Y = 1,
        Z = 2
    };
	template<>
	class Vector<float, 3> {
		__m128 Data;
	public:
		//reference acces to simd data is not allowed
		NODISCARD float& operator[](size_t index) = delete;
		float at(size_t index) const noexcept {
			ASSERT_MSG(index < 3, "index out of range");
			return Data.m128_f32[index];
		}

		Vector()noexcept :Data(_mm_setr_ps(0.0F, 0.0F, 0.0F, 0.0F)) {}
		explicit Vector(float x, float y, float z)noexcept :Data(_mm_setr_ps(x, y, z, 0.0F)) {}
		explicit Vector(__m128 data)noexcept :Data(data) {}
		void Set(float x, float y, float z)noexcept {
			Data = _mm_setr_ps(x, y, z, 0.0F);
		}
		void SetAt(size_t index, float value) noexcept {
			ASSERT_MSG(index < 3, "index out of range");
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
            __m128 dp = _mm_dp_ps(Data, Data, 0b01110001);
            __m128 mag = _mm_sqrt_ps(dp);
            return _mm_cvtss_f32(mag);
        }
        NODISCARD Vector SIMD_CALL CrossProduct(Vector other) {
            constexpr auto mask1 = _MM_SHUFFLE(3, 0, 2, 1);
            constexpr auto mask2 = _MM_SHUFFLE(3, 1, 0, 2);
            return Vector(
                _mm_fnmadd_ps(
                    _mm_shuffle_ps(
                        Data,
                        Data,
                        mask2
                    ),
                    _mm_shuffle_ps(
                        other.Data,
                        other.Data,
                        mask1
                    ),
                    _mm_mul_ps(
                        _mm_shuffle_ps(
                            Data,
                            Data,
                            mask1
                        ),
                        _mm_shuffle_ps(
                            other.Data,
                            other.Data,
                            mask2
                        )
                    )
                )
            );
        }
        NODISCARD float SIMD_CALL DotProduct(Vector other) const {
            __m128 dp = _mm_dp_ps(Data, other.Data, 0b01110001);
            return _mm_cvtss_f32(dp);
        }
        NODISCARD Vector SIMD_CALL Normalize() const {
            float mag = Magnitude();
            return Vector(_mm_div_ps(Data, _mm_set_ps1(mag)));
        }
	};
    using Vector3 = Vector<float, 3>;
}
namespace std {
    std::string to_string(UPRISE_ENGINE::DATATYPES::Vector3 val) {
        return format("Vector3({} {} {})", val.at(0), val.at(1), val.at(3));
    }
    template<>
    struct hash<UPRISE_ENGINE::DATATYPES::Vector3> {
        std::size_t operator()(const UPRISE_ENGINE::DATATYPES::Vector3& v) const
        {
            uint64_t hash = 0;
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(0)));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(1)));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(2)));
            return hash;
        }
    };
}




