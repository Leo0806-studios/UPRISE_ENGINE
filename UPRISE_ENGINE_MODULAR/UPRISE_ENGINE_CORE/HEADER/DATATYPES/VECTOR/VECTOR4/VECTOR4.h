// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_T_S_P_VECTOR4
#define UE_T_S_P_VECTOR4

//#include <glm/fwd.hpp>
#include <intrin.h>
#include <GLOBAL/GLINCLUDES.h>

import std;
#pragma warning(push)
#pragma warning (disable :4514)
namespace UPRISE_ENGINE {
    /// <summary>
/// Vector 4
/// stores data in a __m128
/// </summary>
    class UPRISE_CORE_API Vector4 {
        /// <summary>
        /// data
        /// </summary>
        __m128 Data;

    public:
#pragma region Constructor
        /// <summary>
        /// constructs a vector4 from a __m128
        /// </summary>
        /// <param name="in"></param>
        __inline  Vector4(__m128 in) :Data(in) {}
        /// <summary>
        /// default constructor
        /// </summary>
        __inline    Vector4() = default;
        /// <summary>
        /// constructs a vector4 from 4 floats
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="z"></param>
        /// <param name="w"></param>
        __inline   Vector4(float x, float y, float z, float w) :Data(_mm_setr_ps(x, y, z, w)) {};
#pragma endregion

#pragma region getter
        /// <summary>
        /// getter for x
        /// </summary>
        /// <returns></returns>
        __inline   float x() const {
            return Data.m128_f32[0];
        }
        /// <summary>
    /// getter for y
    /// </summary>
    /// <returns></returns>
        __inline   float y() const {
            return Data.m128_f32[1];

        }
        /// <summary>
    /// getter for z
    /// </summary>
    /// <returns></returns>
        __inline   float z() const {
            return Data.m128_f32[2];

        }
        /// <summary>
    /// getter for w
    /// </summary>
    /// <returns></returns>
        __inline   float w() const {
            return Data.m128_f32[3];

        }
#pragma endregion
#pragma region setter
        //set vals

        /// <summary>
        /// setter for x
        /// sets x to x
        /// returns the new x value
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        __inline   float x(const float x) {
            reinterpret_cast<float*>(&Data)[0] = x;
            return x;

        }
        /// <summary>
    /// setter for y
    /// sets y to y
    /// returns the new y value
    /// </summary>
    /// <param name="y"></param>
    /// <returns></returns>
        __inline   float y(const float y) {
            reinterpret_cast<float*>(&Data)[1] = y;
            return y;

        }
        /// <summary>
    /// setter for z
    /// sets z to z
    /// returns the new z value
    /// </summary>
    /// <param name="z"></param>
    /// <returns></returns>
        __inline   float z(const float z) {
            reinterpret_cast<float*>(&Data)[2] = z;
            return z;


        }
        /// <summary>
    /// setter for w
    /// sets w to w
    /// returns the new w value
    /// </summary>
    /// <param name="w"></param>
    /// <returns></returns>
        __inline   float w(const float w) {
            reinterpret_cast<float*>(&Data)[3] = w;
            return w;

        }
#pragma endregion
        /// <summary>
        /// operator for casting to a glm::vec4
        /// uses the getters of x,y,z,w
        /// </summary>
        __inline   operator glm::vec4() { return glm::vec4(x(), y(), z(), w()); }
        __inline Vector4 operator+(Vector4 other)const noexcept {
            return Vector4(_mm_add_ps(Data, other.Data));
        }
        __inline Vector4 operator-(Vector4 other)const noexcept {
            return Vector4(_mm_sub_ps(Data, other.Data));
        }
        __inline Vector4 operator*(Vector4 other)const noexcept {
            return Vector4(_mm_mul_ps(Data, other.Data));
        }
        __inline Vector4 operator/(Vector4 other)const noexcept {
            return Vector4(_mm_div_ps(Data, other.Data));
        }
    };
}


#pragma warning(pop)
#endif // !_T_S_P_VECTOR4