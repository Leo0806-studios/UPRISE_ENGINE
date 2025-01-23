// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _T_S_P_VECTOR4
#define _T_S_P_VECTOR4

//#include <glm/fwd.hpp>
#include "intrin.h"
#include "GLOBAL/GLINCLUDES.h"
#
import std;

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
    __inline  Vector4(__m128 in) :Data(in) { }
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
    /// returns a non const refference to the x value
    /// </summary>
    /// <returns></returns>
    __inline   float& x() const {
        return ((float*)&Data)[0];
    }
    /// <summary>
/// getter for y
/// returns a non const refference to the y value
/// </summary>
/// <returns></returns>
    __inline   float& y() const {
        return ((float*)&Data)[1];

    }
    /// <summary>
/// getter for z
/// returns a non const refference to the z value
/// </summary>
/// <returns></returns>
    __inline   float& z() const {
        return ((float*)&Data)[2];

    }
    /// <summary>
/// getter for w
/// returns a non const refference to the w value
/// </summary>
/// <returns></returns>
    __inline   float& w() const {
        return ((float*)&Data)[3];

    }
#pragma endregion
#pragma region setter
    //set vals

    /// <summary>
    /// setter for x
    /// returns a non const refference to the x value
    /// sets x to x
    /// returns the new x value
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    __inline   float& x(const float& x) {
        return (((float*)&Data)[0] = x);

    }
    /// <summary>
/// setter for y
/// returns a non const refference to the y value
/// sets y to y
/// returns the new y value
/// </summary>
/// <param name="y"></param>
/// <returns></returns>
    __inline   float& y(const float& y) {
        return (((float*)&Data)[1] = y);

    }
    /// <summary>
/// setter for z
/// returns a non const refference to the z value
/// sets z to z
/// returns the new z value
/// </summary>
/// <param name="z"></param>
/// <returns></returns>
    __inline   float& z(const float& z) {
        return (((float*)&Data)[2] = z);


    }
    /// <summary>
/// setter for w
/// returns a non const refference to the w value
/// sets w to w
/// returns the new w value
/// </summary>
/// <param name="w"></param>
/// <returns></returns>
    __inline   float& w(const float& w) {
        return (((float*)this)[3] = w);

    }
#pragma endregion
    /// <summary>
    /// operator for casting to a glm::vec4
    /// uses the getters of x,y,z,w
    /// </summary>
    __inline   operator glm::vec4() { return glm::vec4(x(), y(), z(), w()); }
};

#endif // !_T_S_P_VECTOR4