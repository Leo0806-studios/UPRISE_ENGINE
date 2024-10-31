#pragma once




#ifndef _VECTOR3_
#define _VECTOR3_

#include "GLOBAL/GLINCLUDES.h"

#include <intrin.h>


/// <summary>
/// Vector3
/// stores data in a __m128
/// </summary>
 class Vector3 {
private:
	/// <summary>
	/// Data
	/// </summary>
	__m128 Data;
public:
#pragma region constructor
#pragma region NonConst
	/// <summary>
    /// default constructor
	/// </summary>
	Vector3() = default;

	/// <summary>
    /// copy consturctor that accepts a Vector3
	/// </summary>
	/// <param name="other"></param>
	Vector3(Vector3& other) :Data(other.Data) {}
	/// <summary>
    /// constructor that accepts a glm::vec3
	/// </summary>
	/// <param name="other"></param>
	Vector3(glm::vec3& other) { Data = _mm_setr_ps(other.x, other.y, other.z, 0); }
	/// <summary>
    /// constructor that accepts a aiVector3D
	/// </summary>
	/// <param name="other"></param>
	Vector3(aiVector3D& other) {
		Data=_mm_setr_ps(other.x, other.y, other.z, 0);
	}
#pragma endregion
#pragma region const
	/// <summary>
	/// constructor that accepts 3 floats
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	Vector3(const float x, const float y, const float z) {
		Data = _mm_setr_ps(x, y, z, 0);
	}
	/// <summary>
    /// constructor that accepts a __m128
	/// </summary>
	/// <param name="other"></param>
	Vector3(const __m128& other) :Data(other) {	}
	/// <summary>
    /// constructor that accepts a Vector3
	/// </summary>
	/// <param name="other"></param>
	Vector3(const Vector3& other) :Data(other.Data) {}
	/// <summary>
    /// constructor that accepts a glm::vec3
	/// </summary>
	/// <param name="other"></param>
	Vector3(const glm::vec3& other) { Data = _mm_setr_ps(other.x, other.y, other.z, 0); }
	/// <summary>
    /// constructor that accepts a aiVector3D
	/// </summary>
	/// <param name="other"></param>
	Vector3(const aiVector3D& other) {
		Data = _mm_setr_ps(other.x, other.y, other.z, 0);
	}
#pragma endregion


#pragma endregion


#pragma region getter
	/// <summary>
	/// getter for x
    /// returns a non const reference to the x value
	/// </summary>
	/// <returns></returns>
	__inline UPRISE_CORE_API float& x() const{
		return ((float*)&Data)[0];
	}
	/// <summary>
    /// getter for y
    /// returns a non const reference to the y value
	/// </summary>
	/// <returns></returns>
	__inline UPRISE_CORE_API float& y() const {
		return ((float*)&Data)[1];

	}
    /// <summary>
    /// getter for z
    /// returns a non const reference to the z value
    ///<summary>
    /// <returns></returns>
	__inline UPRISE_CORE_API float& z() const {
		return ((float*)&Data)[2];

	}
	/// <summary>
    /// getter for pad  
    /// returns a non const reference to the pad value
	/// </summary>
	/// <returns></returns>
	__inline UPRISE_CORE_API float& pad() const {
		return ((float*)&Data)[3];

	}
#pragma endregion
#pragma region setter
	//set vals

	/// <summary>
	/// setter for x
    /// returns a non const reference to the x value
    /// sets x to the value of x
    /// retruns the new value of x
	/// </summary>
	/// <param name="x"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API float& x(const float& x) {
		return (((float*)&Data)[0] = x);

	}
	/// <summary>
    /// setter for y
    /// returns a non const reference to the y value
    /// sets y to the value of y
    /// retruns the new value of y
	/// </summary>
	/// <param name="y"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API float& y(const float& y) {
		return (((float*)&Data)[1]=y);

	}
	/// <summary>
    /// setter for z
    /// returns a non const reference to the z value
    /// sets z to the value of z
    /// retruns the new value of z
	/// </summary>
	/// <param name="z"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API float& z(const float& z) {
		return (((float*)&Data)[2]=z);


	}
    /// <summary>
    /// setter for pad
    /// returns a non const reference to the pad value
    /// sets pad to the value of pad
    /// retruns the new value of pad
    /// </summary>
    /// <param name="pad"></param>
    /// <returns></returns>
	__inline UPRISE_CORE_API float& pad(const float& pad) {
		return (((float*)this)[3]=pad);

	}
#pragma endregion
#pragma region Operator
#pragma region NonConst
	/// <summary>
    /// assingment operator 
    /// accepts a Vector3
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator=(const Vector3& other) {
		this->Data = other.Data;
		return *this;
	}
	/// <summary>
    /// assingment operator 
    /// accepts a __m128
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator=(const __m128& other) {
		this->Data = other;
		return *this;
	}
	/// <summary>
    /// addition operator of twot vector3
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator+(Vector3 other) {
		other.Data = _mm_add_ps(this->Data, other.Data);
		return other;
	}
	/// <summary>
	/// addition opperator of a vector 3 and a __m128
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator+(__m128 other) {
		return Vector3(_mm_add_ps(this->Data, other));
	}
	/// <summary>
	/// substraction opperator of two vector3
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator-(Vector3 other) {
		other.Data = _mm_sub_ps(this->Data, other.Data);
		return other;
	}
	/// <summary>
	/// substaraction opperator of a vector 3 and a __m128
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator-(__m128 other) {
		return Vector3(_mm_sub_ps(this->Data, other));
	}
	/// <summary>
    /// multiplication opperator of two vector3
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator*(Vector3 other) {
		other.Data = _mm_mul_ps(this->Data, other.Data);
		return  other;
	}
	/// <summary>
    /// multiplication opperator of a vector 3 and a __m128
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator*(__m128 other) {
		return  Vector3(_mm_mul_ps(this->Data, other));
	}
    /// <summary>
    /// multiplication opperator of a vector 3 and a float
    /// </summary>
    /// <param name="f"></param>
    /// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator*(float f) {
		return Vector3(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
    }
    /// <summary>
    /// division opperator of two vector3
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator/(Vector3 other) {
		other.Data = _mm_div_ps(this->Data, other.Data);
		return  other;
    }
    /// <summary>
    /// division opperator of a vector 3 and a __m128
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator/(__m128 other) {
		return  Vector3(_mm_div_ps(this->Data, other));
    }
    /// <summary>
    /// division opperator of a vector 3 and a float
    /// </summary>
    /// <param name="f"></param>
    /// <returns></returns>
	__inline UPRISE_CORE_API Vector3 operator/(float f) {
		return Vector3(_mm_div_ps(this->Data, _mm_set_ps1(f)));
	}
	/// <summary>
    /// opperator for casting to __m128
	/// </summary>
	__inline UPRISE_CORE_API operator __m128() {
		return this->Data;
	}



	/// <summary>
/// Cross Product
/// Returns Vector orthogonal to both
/// </summary>
/// <param name="b"></param>
/// <returns>Cross Product</returns>
	__forceinline UPRISE_CORE_API Vector3 operator^(Vector3 b) {
		return _mm_fnmadd_ps(_mm_shuffle_ps(Data, Data, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(b.Data, b.Data, _MM_SHUFFLE(3, 0, 2, 1)), _mm_mul_ps(_mm_shuffle_ps(Data, Data, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(b.Data, b.Data, _MM_SHUFFLE(3, 1, 0, 2))));
		// b;
	}
#pragma endregion
#pragma region  Const
	__inline UPRISE_CORE_API Vector3 operator+(const Vector3& other) const {

		return Vector3(_mm_add_ps(this->Data, other.Data));
	}
	__inline UPRISE_CORE_API Vector3 operator+(const __m128& other) const {
		return Vector3(_mm_add_ps(this->Data, other));
	}
	__inline UPRISE_CORE_API Vector3 operator-(const Vector3& other)const {
		
		return Vector3(_mm_sub_ps(this->Data, other.Data));
	}
	__inline UPRISE_CORE_API Vector3 operator-(const __m128& other)const {
		return Vector3(_mm_sub_ps(this->Data, other));
	}
	__inline UPRISE_CORE_API Vector3 operator*(const Vector3& other)const {
		return  Vector3(_mm_mul_ps(this->Data, other.Data));
	}
	__inline UPRISE_CORE_API Vector3 operator*(const __m128& other) const{
		return  Vector3(_mm_mul_ps(this->Data, other));
	}
	__inline UPRISE_CORE_API Vector3 operator*(const float f) const{
		return Vector3(_mm_mul_ps(this->Data, _mm_set_ps1(f)));
	}
	__inline UPRISE_CORE_API Vector3 operator/(const Vector3& other)const {
		return  Vector3(_mm_div_ps(this->Data, other.Data));
	}
	__inline UPRISE_CORE_API Vector3 operator/(const __m128& other) const {
		return  Vector3(_mm_div_ps(this->Data, other));
	}
	__inline UPRISE_CORE_API Vector3 operator/(const float f) const {
		return Vector3(_mm_div_ps(this->Data, _mm_set_ps1(f)));
	}
#pragma endregion



#pragma endregion

#pragma region Funcs
	/// <summary>
	/// computes the magnitude (length) of the vector
	/// </summary>
	/// <returns></returns>
	__forceinline UPRISE_CORE_API float Magnitude() {
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
	__forceinline UPRISE_CORE_API Vector3 Normalized() {
		float mag = this->Magnitude();
		Vector3 tmp;
		_mm_store_ps(&tmp.x(), _mm_div_ps(Data, _mm_load_ps1(&mag)));
		return tmp;
	}
	/// <summary>
	/// computes the dot/point product of the two Vector3's
	/// </summary>
	/// <param name="a"></param>
	/// <returns></returns>
	__inline UPRISE_CORE_API float Point(Vector3 a) {
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
#endif

