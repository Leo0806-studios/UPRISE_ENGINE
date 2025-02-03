// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "Header/DATATYPES/D_TS_P_QUATERION.h"
#define _USE_MATH_DEFINES
#include "math.h"

 DATATYPES::Quaternion DATATYPES::Quaternion::FromEulerAngles(DATATYPES::TSPVector3 vec) {
	 float cy = std::cos(vec.y * 0.5);
	 float sy = std::sin(vec.y * 0.5);
	 float cp = std::cos(vec.z* 0.5);
	 float sp = std::sin(vec.z * 0.5);
	 float cr = std::cos(vec.x * 0.5);
	 float sr = std::sin(vec.x * 0.5);
	 return Quaternion(
		 cr * cp * cy + sr * sp * sy,
		 sr * cp * cy - cr * sp * sy,
		 cr * sp * cy + sr * cp * sy,
		 cr * cp * sy - sr * sp * cy

		//  cr * cp * cy + sr * sp * sy,
	 //sr * cp * cy - cr * sp * sy,
	 // cr * sp * cy + sr * cp * sy,
	 //cr * cp * sy - sr * sp * cy
	 );
}


DATATYPES:: Quaternion DATATYPES::Quaternion::operator*(const Quaternion& other) const
 {
	return Quaternion(
		w * other.w - x * other.x - y * other.y - z * other.z,
		w * other.x + x * other.w + y * other.z - z * other.y,
		w * other.y - x * other.z + y * other.w + z * other.x,
		w * other.z + x * other.y - y * other.x + z * other.w
	);
 }

 DATATYPES::TSPVector3 DATATYPES::Quaternion::ToRotationVector() const {
	 //DATATYPES::TS_P_Vector3 ot;
	 //double sinr_cosp = 2 * (w * x + y * z);
	 //double cosr_cosp = 1 - 2 * (x * x + y * y);
	 //ot.x = std::atan2(sinr_cosp, cosr_cosp);

	 //// pitch (y-axis rotation)
	 //double sinp = std::sqrt(1 + 2 * (w * y - x * z));
	 //double cosp = std::sqrt(1 - 2 * (w * y - x * z));
	 //ot.z = 2 * std::atan2(sinp, cosp) - M_PI / 2;

	 //// yaw (z-axis rotation)
	 //double siny_cosp = 2 * (w *z + x * y);
	 //double cosy_cosp = 1 - 2 * (y * y + z * z);
	 //ot.z = std::atan2(siny_cosp, cosy_cosp);
	 //return ot;
	 
	 // Normalize the quaternion


	 float length = std::sqrt(w * w + x * x + y * y + z * z);
	 float nw = w / length;
	 float nx = x / length;
	 float ny = y / length;
	 float nz = z / length;

	 // Compute the angle
	 float angle = 2.0F * std::acos(nw);

	 // Compute the axis
	 float s = std::sqrt(1.0F - nw * nw);
	 if (s < 0.0001f) {
		 // If s is close to zero, return the axis as (1, 0, 0)
		 return DATATYPES::TSPVector3(1, 0, 0) * angle;
	 }
	 else {
		 return DATATYPES::TSPVector3(nx / s, ny / s, nz / s) * angle;
	 }
 }
 DATATYPES::TSPVector3 DATATYPES::Quaternion::operator*(DATATYPES::TSPVector3 vec)
 {
	 float num = x * 2;
	 float num2 = y * 2;
	 float num3 = z * 2;
	 float num4 = x * num;
	 float num5 = y * num2;
	 float num6 = z * num3;
	 float num7 = x * num2;
	 float num8 = x * num3;
	 float num9 = y * num3;
	 float num10 = w * num;
	 float num11 = w * num2;
	 float num12 = w * num3;
	 DATATYPES::TSPVector3 result;
	 result.x = (1 - (num5 + num6)) * vec.x + (num7 - num12) * vec.y + (num8 + num11) * vec.z;
	 result.y = (num7 + num12) * vec.x + (1 - (num4 + num6)) * vec.y + (num9 - num10) * vec.z;
	 result.z = (num8 - num11) * vec.x + (num9 + num10) * vec.y + (1 - (num4 + num5)) * vec.z;
	 return result;
 }
