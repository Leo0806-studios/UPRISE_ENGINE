#ifndef _TS_P_VECTOR3_

#define _TS_P_VECTOR3_
#include "GLINCLUDES.h"
namespace DATATYPES {


	struct TSPVector3 {
	public:float x;
	public:float y;
	public:float z;
	public:float pad;
	public:
		TSPVector3();
		TSPVector3(float x, float y, float z);
		TSPVector3(const TSPVector3& other) = default;
		TSPVector3(glm::vec3 vec);

		TSPVector3(aiVector3D vec);
		TSPVector3& operator=(const TSPVector3& other) = default;
		TSPVector3& operator=(const aiVector3D& other);;
		operator __m128()const;
		//operator aiVector3D() const;
		operator glm::vec3()const;

		float magnitude();
		TSPVector3 Normalized();

		float point(TSPVector3 a);

		TSPVector3 operator /(const float b);
		TSPVector3 operator/(const TSPVector3 b);
		TSPVector3 operator *(const float b);
		TSPVector3 operator*(const TSPVector3 b);
		TSPVector3 operator -(const TSPVector3 b);
		TSPVector3 operator+(const TSPVector3 b);




	};
}


#endif // !_TS_P_VECTOR3_
