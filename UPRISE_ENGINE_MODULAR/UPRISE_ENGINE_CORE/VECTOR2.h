#pragma once

#include <intrin.h>
#include "VECTOR.h"
#include <cmath>
#include <format>
#include <string>
#include <utility>

namespace UPRISE_ENGINE::DATATYPES {
    template<>
    class Vector<float, 2> {
        float x;
        float y;
    public:
        float& operator[](size_t index)noexcept {
            ASSERT_MSG(index < 2, "index out of range");
            return index == 0 ? x : y;
        }
        const float& at(size_t index) const noexcept {
            ASSERT_MSG(index < 2, "index out of range");
            return index == 0 ? x : y;
        }
        Vector() noexcept :x(0), y(0) {}
        Vector(float x, float y) noexcept :x(x), y(y) {}
        
        float& X() noexcept {
            return x;
        }
        float& Y() noexcept {
            return y;
        }
        Vector operator+(const Vector& other) const noexcept {
            return Vector<float, 2>{ x + other.x, y + other.y };
        }
        Vector operator-(const Vector& other) const noexcept {
            return Vector<float, 2>{ x - other.x, y - other.y };
        }
        Vector operator*(const Vector& other) const noexcept {
            return Vector<float, 2>{ x* other.x, y* other.y };
        }
        Vector operator/(const Vector& other) const noexcept {
            return Vector<float, 2>{ x / other.x, y / other.y };
        }
        Vector operator*(const float f) const noexcept {
            return Vector<float, 2>{ x* f, y* f };
        }
        Vector operator/(const float f) const noexcept {
            return Vector<float, 2>{ x / f, y / f };
        }
        Vector CrossProduct(const Vector b) const noexcept {
            return Vector<float, 2>{ 0, x* b.y - y * b.x };
        }
        Vector operator-() const noexcept {
            return Vector<float, 2>{ -x, -y };
        }
        Vector operator+() const noexcept {
            return *this;
        }
        float Magnitude() const noexcept {
            return std::sqrt(x * x + y * y);
        }
        float DotProduct(const Vector other) const noexcept {
            return x * other.x + y * other.y;
        }
        float Normalize() noexcept {
            float mag = Magnitude();
            if (mag > 0) {
                x /= mag;
                y /= mag;
            }
            return mag;
        }
    };
    using Vector2 = Vector<float, 2>;
}
namespace std {
    string to_string(UPRISE_ENGINE::DATATYPES::Vector2 v) {
        return std::format("Vector2({}, {})", v.X(), v.Y());
    }
    template<>
    struct hash<UPRISE_ENGINE::DATATYPES::Vector2>
    {
        std::size_t operator()(const UPRISE_ENGINE::DATATYPES::Vector2& v) const
        {
            uint64_t hash = 0;
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(0)));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<float>{}(v.at(1)));
            return hash;
        }
    };
 }