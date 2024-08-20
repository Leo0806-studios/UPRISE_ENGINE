#pragma once
#ifndef _QUATERIONS_
#define _QUATERIONS_

#include "pch.h"
#include "HeaderE/DATATYPES/D_TS_P_VECTOR3.h"
namespace DATATYPES {
	struct Quaternion {
	public:
		float x, y, z, w;
		Quaternion() : w(1), x(0), y(0), z(0) {}
		Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

		

		static Quaternion FromEulerAngles(DATATYPES::TSPVector3 vec);


		Quaternion operator*(const Quaternion& other) const;
		
		DATATYPES::TSPVector3 ToRotationVector() const;
		TSPVector3 operator*(DATATYPES::TSPVector3 vec);

		DATATYPES::TSPVector3 Rotate(const DATATYPES::TSPVector3& v) const {
			Quaternion qv(0, v.x, v.y, v.z);
			Quaternion qconj(w, -x, -y, -z);
			Quaternion result = (*this) * qv * qconj;
			auto a = DATATYPES::TSPVector3(result.x, result.y, result.z);
			return a;
		}
		glm::mat4 ToMat4() const {
			return glm::mat4_cast(glm::quat(w, x, y, z));
		}

	};

};

#endif // !_QUATERIONS_
