// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _VECTOR2_
#define _VECTOR2_
#include <GLOBAL/GLINCLUDES.h>

#include <intrin.h>
namespace UPRISE_ENGINE {
    /// <summary>
/// vector 2 class
/// </summary>
    class UPRISE_CORE_API Vector2 {
    private:
        /// <summary>
        /// data
        /// </summary>
        __m128 Data;
    public:
#pragma region constructor
#pragma region NonConst
        /// <summary>
        /// default constructor
        /// </summary>
        Vector2() = default;
        /// <summary>
        /// cosntructor with x and y values
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        Vector2(float x, float y) {
            Data = _mm_setr_ps(x, y, x, y);
        }
        /// <summary>
        /// constructor with __m128 ref
        /// </summary>
        /// <param name="other"></param>
        Vector2(__m128& other) :Data(other) {}
        /// <summary>
        /// constructor that accepts a __m128
        /// </summary>
        /// <param name="other"></param>
        Vector2(__m128 other) :Data(other) {}
        /// <summary>
        /// constructor tha accepts a Vector2 ref
        /// </summary>
        /// <param name="other"></param>
        Vector2(Vector2& other) :Data(other.Data) {}
        /// <summary>
        /// constructor that accepts a glm::vec2 ref
        /// </summary>
        /// <param name="other"></param>
        Vector2(glm::vec2& other) { Data = _mm_setr_ps(other.x, other.y, other.x, other.y); }

#pragma endregion
#pragma region const
        //Vector2(const float x, const float y) {
        //	Data = _mm_setr_ps(x, y, x, y);
        //}
        //Vector2(const __m128& other) :Data(other) {	}
        //Vector2(const Vector2& other) :Data(other.Data) {}
        //Vector2(const glm::vec2& other) { Data = _mm_setr_ps(other.x, other.y, other.x, other.y); }

#pragma endregion


#pragma endregion


#pragma region getter
    /// <summary>
    /// geter for x
    /// returns a non const ref to x
    /// </summary>
    /// <returns></returns>
        __inline  float& x() const {
            return ((float*)&Data)[0];
        }
        /// <summary>
        /// getter for y
        /// returns a non const ref to y
        /// </summary>
        /// <returns></returns>
        __inline  float& y() const {
            return ((float*)&Data)[1];

        }
        /// <summary>
        /// getter for xx
        /// returns a non const ref to xx
        /// xx is a usualy a mirror of x
        /// </summary>
        /// returns></returns>
        __inline  float& xx() const {
            return ((float*)&Data)[2];

        }
        /// <summary>
    /// getter for yy
    /// returns a non const ref to yy
    /// yy is a usualy a mirror of y
    /// </summary>
    ///     <returns></returns>
        __inline  float& yy() const {
            return ((float*)&Data)[3];

        }
#pragma endregion
#pragma region setter
        //set vals

        /// <summary>
        /// setter for x
        /// returns a non const ref to x
        /// sets x to x
        /// returns the new val of x
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        __inline  float& x(const float& x) {
            return (((float*)&Data)[0] = x);

        }
        /// <summary>
        /// setter for y
        /// returns a non const ref to y
        /// sets y to y
        /// returns the new val of y
        /// </summary>
        /// <param name="y"></param>
        /// <returns></returns>
        __inline  float& y(const float& y) {
            return (((float*)&Data)[1] = y);

        }
        /// <summary>
        /// setter for xx
        /// returns a non const ref to xx
        /// sets xx to xx
        /// returns the new val of xx
        /// </summary>
        /// <param name="xx"></param>
        /// <returns></returns>
        __inline  float& xx(const float& xx) {
            return (((float*)&Data)[2] = xx);


        }
        /// <summary>
        /// setter for yy
        /// returns a non const ref to yy
        /// sets yy to yy
        /// returns the new val of yy
        /// </summary>
        /// <param name="yy"></param>
        /// <returns></returns>
        __inline  float& yy(const float& yy) {
            return (((float*)this)[3] = yy);

        }
#pragma endregion
#pragma region Operator
#pragma region NonConst
        /// <summary>
        /// assingmet operator that accepts a vector2
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator=(const Vector2& other) {
            this->Data = other.Data;
            return *this;
        }
        /// <summary>
        /// assingmet operator that accepts a __m128
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator=(const __m128& other) {
            this->Data = other;
            return *this;
        }
        /// <summary>
        /// addition operator that accepts a vector2
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator+(Vector2 other) {
            other.Data = _mm_add_ps(this->Data, other.Data);
            return other;
        }
        /// <summary>
        /// addition operator that accepts a __m128
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator+(__m128 other) {
            return Vector2(_mm_add_ps(this->Data, other));
        }
        /// <summary>
        /// subtraction operator that accepts a vector2
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator-(Vector2 other) {
            other.Data = _mm_sub_ps(this->Data, other.Data);
            return other;
        }
        /// <summary>
        /// subtraction operator that accepts a __m128
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator-(__m128 other) {
            return Vector2(_mm_sub_ps(this->Data, other));
        }
        /// <summary>
        /// multiplication operator that accepts a vector2
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator*(Vector2 other) {
            other.Data = _mm_mul_ps(this->Data, other.Data);
            return  other;
        }
        /// <summary>
    /// multiplication operator that accepts a __m128
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
        __inline  Vector2 operator*(__m128 other) {
            return  Vector2(_mm_mul_ps(this->Data, other));
        }
        /// <summary>
        /// multiplication operator that accepts a float
        /// </summary>
        /// <param name="f"></param>
        /// <returns></returns>
        __inline  Vector2 operator*(float f) {
            return Vector2(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
        }
        /// <summary>
        /// division operator that accepts a vector2
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator/(Vector2 other) {
            other.Data = _mm_div_ps(this->Data, other.Data);
            return  other;
        }
        /// <summary>
        /// division operator that accepts a __m128
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        __inline  Vector2 operator/(__m128 other) {
            return  Vector2(_mm_div_ps(this->Data, other));
        }
        /// <summary>
        /// division operator that accepts a float
        /// </summary>
        /// <param name="f"></param>
        /// <returns></returns>
        __inline  Vector2 operator/(float f) {
            return Vector2(_mm_div_ps(this->Data, _mm_set_ps1(f)));
        }




        /// <summary>
    /// Cross Product
    /// Returns Vector orthogonal to both
    /// </summary>
    /// <param name="b"></param>
    /// <returns>Cross Product</returns>
        __forceinline  Vector2 operator^(Vector2 b) {
            return _mm_fnmadd_ps(_mm_shuffle_ps(Data, Data, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(b.Data, b.Data, _MM_SHUFFLE(3, 0, 2, 1)), _mm_mul_ps(_mm_shuffle_ps(Data, Data, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(b.Data, b.Data, _MM_SHUFFLE(3, 1, 0, 2))));
            // b;
        }
#pragma endregion
#pragma region  Const
        //__inline UPRISE_CORE_API Vector2 operator+(const Vector2& other) const {

        //	return Vector2(_mm_add_ps(this->Data, other.Data));
        //}
        //__inline UPRISE_CORE_API Vector2 operator+(const __m128& other) const {
        //	return Vector2(_mm_add_ps(this->Data, other));
        //}
        //__inline UPRISE_CORE_API Vector2 operator-(const Vector2& other)const {

        //	return Vector2(_mm_sub_ps(this->Data, other.Data));
        //}
        //__inline UPRISE_CORE_API Vector2 operator-(const __m128& other)const {
        //	return Vector2(_mm_sub_ps(this->Data, other));
        //}
        //__inline UPRISE_CORE_API Vector2 operator*(const Vector2& other)const {
        //	return  Vector2(_mm_mul_ps(this->Data, other.Data));
        //}
        //__inline UPRISE_CORE_API Vector2 operator*(const __m128& other) const {
        //	return  Vector2(_mm_mul_ps(this->Data, other));
        //}
        //__inline UPRISE_CORE_API Vector2 operator*(const float f) const {
        //	return Vector2(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
        //}
        //__inline UPRISE_CORE_API Vector2 operator/(const Vector2& other)const {
        //	return  Vector2(_mm_div_ps(this->Data, other.Data));
        //}
        //__inline UPRISE_CORE_API Vector2 operator/(const __m128& other) const {
        //	return  Vector2(_mm_div_ps(this->Data, other));
        //}
        //__inline UPRISE_CORE_API Vector2 operator/(const float f) const {
        //	return Vector2(_mm_div_ps(this->Data, _mm_set_ps1(f)));
        //}
#pragma endregion



#pragma endregion

#pragma region Funcs
    /// <summary>
    /// computes the magnitude (length) of the vector
    /// </summary>
    /// <returns></returns>
        __forceinline  float Magnitude() const {
            __m128 val2 = Data;
            val2 = _mm_mul_ps(val2, val2);
            __m128 shuf = _mm_movehdup_ps(val2);        // broadcast elements 3,1 to 2,0
            val2 = _mm_add_ps(val2, shuf);
            shuf = _mm_movehl_ps(shuf, val2);
            val2 = _mm_add_ss(val2, shuf);
            val2 = _mm_sqrt_ps(val2);

            return _mm_cvtss_f32(val2);
        }


        /// <summary>
        /// returns the normalized version of the vector
        /// </summary>
        /// <returns></returns>
        __forceinline  Vector2 Normalized() const {
            float mag = this->Magnitude();
            Vector2 tmp{};
            _mm_store_ps(&tmp.x(), _mm_div_ps(Data, _mm_load_ps1(&mag)));
            return tmp;
        }
        /// <summary>
        /// computes the dot/point product of the two Vector2's
        /// </summary>
        /// <param name="a"></param>
        /// <returns></returns>
        __inline  float Point(Vector2 a) const {
            __m128 val = Data;

            val = _mm_mul_ps(val, a.Data);
            a.Data = _mm_movehdup_ps(val);        // broadcast elements 3,1 to 2,0
            val = _mm_add_ps(val, a.Data);
            a.Data = _mm_movehl_ps(a.Data, val); // high half -> low half
            val = _mm_add_ss(val, a.Data);

            return _mm_cvtss_f32(val);
        }

#pragma endregion
    };
}

#endif // !1
