#pragma once

#ifndef _QUATERION_
#define _QUATERION_

#include "GLOBAL/GLINCLUDES.h"
#include <intrin.h>
#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h";


#pragma region Quaterion
/// <summary>
/// stores a quaternion in a __m128
/// </summary>
 class  UPRISE_CORE_API Quaternion {
	/// <summary>
	/// data
	/// </summary>
	__m128 Data;
public:
#pragma region getter
	/// <summary>
	/// getter for x
    /// returns a non const reference to the x value
	/// </summary>
	/// <returns></returns>
	__inline  float& x() const {
		return ((float*)&Data)[0];
	}
	/// <summary>
    /// getter for y
    /// returns a non const reference to the y value
	/// </summary>
	/// <returns></returns>
	__inline  float& y() const {
		return ((float*)&Data)[1];

	}
    /// <summary>
    /// getter for z
    /// returns a non const reference to the z value
    /// /// </summary>
	/// <returns></returns>
	__inline  float& z() const {
		return ((float*)&Data)[2];

	}
    /// <summary>
    /// getter for w
    /// returns a non const reference to the w value
    /// </summary>
    /// <returns></returns>
	__inline  float& w() const {
		return ((float*)&Data)[3];

	}
#pragma endregion
#pragma region setter
	//set vals

	/// <summary>
    /// setter for x
    /// returns a non const reference to the x value
    /// sets x to the value of x
    /// returns the new value of x
	/// </summary>
	/// <param name="x"></param>
	/// <returns></returns>
	__inline  float& x(const float& x) {
		return (((float*)&Data)[0] = x);

	}
    /// <summary>
    /// setter for y
    /// returns a non const reference to the y value
    /// sets y to the value of y
    /// returns the new value of y
    /// </summary>
    /// /// <param name="y"></param>
	/// <returns></returns>
	__inline  float& y(const float& y) {
		return (((float*)&Data)[1] = y);

	}
    /// <summary>
    /// setter for z
    /// returns a non const reference to the z value
    /// sets z to the value of z
    /// returns the new value of z
    /// </summary>
    /// <param name="z"></param>
    /// <returns></returns>
    /// 
	__inline  float& z(const float& z) {
		return (((float*)&Data)[2] = z);


	}
    /// <summary>
/// setter for w
/// returns a non const reference to the w value
/// sets w to the value of w
/// returns the new value of w
/// </summary>
/// <param name="w"></param>
/// <returns></returns>
	__inline  float& w(const float& w) {
		return (((float*)this)[3] = w);

	}
#pragma endregion


#pragma region Constructor
	/// <summary>
	/// constructor for identity quaterion 
    /// x = 0
    /// y = 0
    /// z = 0
    /// w = 1
	/// </summary>
	Quaternion() {
		w(1); x(0); y(0); z(0);
	}
	/// <summary>
    /// constructor for quaterion with values
    /// w = w
    /// x = x
    /// y = y
    /// z = z
	/// </summary>
	/// <param name="w"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	Quaternion(float w, float x, float y, float z) { this->w(w); this->x(x); this->y(y); this->z(z); }
	/// <summary>
    /// constructor that takes a __m128
	/// </summary>
	/// <param name="other"></param>
	Quaternion(__m128 other) {
		this->Data = other;

	}
#pragma endregion
#pragma region operator
#pragma region nonConst

#pragma endregion
#pragma region Const

#pragma endregion


#pragma endregion




	
#pragma region Funcs

#pragma endregion


	/// <summary>
    /// static function that returns a quaternion from a vector 3
	/// </summary>
	/// <param name="vec"></param>
	/// <returns></returns>
	static __inline  Quaternion FromEulerAngles(Vector3 vec) {

		__m128 coss = _mm_cos_ps(_mm_mul_ps(vec, _mm_set_ps1(0.5)));
		__m128 sinn = _mm_sin_ps(_mm_mul_ps(vec, _mm_set_ps1(0.5)));
		__m128 vals = _mm_addsub_ps(
			_mm_mul_ps(
				_mm_insert_ps(_mm_broadcastss_ps(coss), sinn, 0b01100000),
				_mm_mul_ps(
					_mm_insert_ps(_mm_shuffle_ps(coss, coss, _MM_SHUFFLE(2, 2, 2, 2)), sinn, 0b11110000),
					_mm_insert_ps(_mm_shuffle_ps(coss, coss, _MM_SHUFFLE(1, 1, 1, 1)), sinn, 0b10100000)
				)
			),
			_mm_mul_ps(
				_mm_insert_ps(_mm_broadcastss_ps(sinn),coss , 0b01100000),
				_mm_mul_ps(
					_mm_insert_ps(_mm_shuffle_ps(sinn, sinn, _MM_SHUFFLE(2, 2, 2, 2)), coss, 0b11110000),
					_mm_insert_ps(_mm_shuffle_ps(sinn, sinn, _MM_SHUFFLE(1, 1, 1, 1)), coss, 0b10100000)
				)
			)
		);
		return Quaternion(vals);

	}

	/// <summary>
    /// operator that multiplies two quaternions
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	__inline  Quaternion operator*(const Quaternion& other) const {
		return Quaternion(
			w() * other.w() - x() * other.x() - y() * other.y() - z() * other.z(),
			w() * other.x() + x() * other.w() + y() * other.z() - z() * other.y(),
			w() * other.y() - x() * other.z() + y() * other.w() + z() * other.x(),
			w() * other.z() + x() * other.y() - y() * other.x() + z() * other.w()
		);
	}

	/// <summary>
    /// transforms a quaternion to a vector3 
	/// </summary>
	/// <returns></returns>
	__inline  Vector3 ToRotationVector() const {



		float length = std::sqrt(w() * w() + x() * x() + y() * y() + z() * z());
		float nw = w() / length;
		float nx = x() / length;
		float ny = y() / length;
		float nz = z() / length;

		// Compute the angle
		float angle = 2.0f * std::acos(nw);

		// Compute the axis
		float s = std::sqrt(1.0f - nw * nw);
		if (s < 0.0001f) {
			// If s is close to zero, return the axis as (1, 0, 0)
			return Vector3(1, 0, 0) * angle;
		}
		else {
			return Vector3(nx / s, ny / s, nz / s) * angle;
		}
	}


/// <summary>
/// multiply a quaternion with a vector3
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
__inline 	Vector3 operator*(Vector3 vec) {
		float num = x() * 2;
		float num2 = y() * 2;
		float num3 = z() * 2;
		float num4 = x() * num;
		float num5 = y() * num2;
		float num6 = z() * num3;
		float num7 = x() * num2;
		float num8 = x() * num3;
		float num9 = y() * num3;
		float num10 = w() * num;
		float num11 = w() * num2;
		float num12 = w() * num3;
       return Vector3 { (1 - (num5 + num6)) * vec.x() + (num7 - num12) * vec.y() + (num8 + num11) * vec.z() ,
            (num7 + num12) * vec.x() + (1 - (num4 + num6)) * vec.y() + (num9 - num10) * vec.z() ,
        (num8 - num11)* vec.x() + (num9 + num10) * vec.y() + (1 - (num4 + num5)) * vec.z()
        };
		//result.x() = (1 - (num5 + num6)) * vec.x() + (num7 - num12) * vec.y() + (num8 + num11) * vec.z();
		//result.y() = (num7 + num12) * vec.x() + (1 - (num4 + num6)) * vec.y() + (num9 - num10) * vec.z();
		//result.z() = (num8 - num11) * vec.x() + (num9 + num10) * vec.y() + (1 - (num4 + num5)) * vec.z();
		//return result;
	}

	/// <summary>
    /// rotate the quaterion with a vector3
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	__inline  Vector3 Rotate(const Vector3& v) const {
		Quaternion qv(0, v.x(), v.y(), v.z());
		Quaternion qconj(w(), -x(), -y(), -z());
		Quaternion result = (*this) * qv * qconj;
		auto a = Vector3(result.x(), result.y(), result.z());
		return a;
	}
	/// <summary>
    /// casts the quaternion to a mat4 with glm::mat4_cast(glm::quat(w(), x(), y(), z()));
	/// </summary>
	/// <returns></returns>
	__inline  glm::mat4 ToMat4() const {
		return glm::mat4_cast(glm::quat(w(), x(), y(), z()));
	}

};
#pragma endregion
#endif // !_QUATERION_

