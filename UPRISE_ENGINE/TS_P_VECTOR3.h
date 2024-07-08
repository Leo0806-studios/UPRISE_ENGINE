#ifndef _TS_P_VECTOR3_

#define _TS_P_VECTOR3_
#include "GLINCLUDES.h"
namespace DATATYPES {


	struct TS_P_Vector3 {
	public:float x;
	public:float y;
	public:float z;
	public:float pad;
	public :
		  TS_P_Vector3();
		  TS_P_Vector3(float x, float y, float z);
		  TS_P_Vector3(const TS_P_Vector3& other) = default;
		   TS_P_Vector3(glm::vec3 vec);

		   TS_P_Vector3(aiVector3D vec);
		  TS_P_Vector3& operator=(const TS_P_Vector3& other) = default;
		  TS_P_Vector3& operator=(const aiVector3D& other);;
		  operator __m128()const;
		  //operator aiVector3D() const;
		  operator glm::vec3()const;

		  float magnitude();

		  float point(TS_P_Vector3 a);

		  TS_P_Vector3 operator /(const float b);
		  TS_P_Vector3 operator/(const TS_P_Vector3 b);
		  TS_P_Vector3 operator *(const float b);
		  TS_P_Vector3 operator*(const TS_P_Vector3 b);
		  TS_P_Vector3 operator -(const TS_P_Vector3 b);




	};
}


#endif // !_TS_P_VECTOR3_
