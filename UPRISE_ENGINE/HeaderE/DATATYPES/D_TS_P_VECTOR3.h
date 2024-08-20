#ifndef _TS_P_VECTOR3_

#define _TS_P_VECTOR3_
#include "GLINCLUDES.h"
#include "pch.h"
namespace DATATYPES {


	struct TSPVector3 {
	public:  float x;
	public:  float y;
	public: float z;
	public: float pad;
	public :
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
		  TSPVector3 operator/(const __m128 b){}
		  TSPVector3 operator*(const __m128 b){}
		  TSPVector3 operator -(const __m128 b){}
		  __inline TSPVector3 operator+(__m128 b) {
		  }
		    TSPVector3 operator /(const float b);
		    TSPVector3 operator/(const TSPVector3 b);
		   TSPVector3 operator *(const float b);
		   TSPVector3 operator*(const TSPVector3 b);
		    TSPVector3 operator -(const TSPVector3 b);
		 __inline TSPVector3 operator+( TSPVector3 b) {
			 TrPr(ctx, __func__)
				 //TSPVector3 tmp;
			 //__m128 this3 = _mm_setr_ps(x, y, z, pad);
			 //__m128 be = _mm_setr_ps(b.x, b.y, b.z, b.pad);
			 //_mm_store_ps(&b.x, _mm_add_ps(this3, be));
			 _mm_store_ps(&b.x, _mm_add_ps(_mm_load_ps(&this->x) , _mm_load_ps(&b.x)));
			 TrPrE(ctx)
				 return b ;
		 }





	};
}


#endif // !_TS_P_VECTOR3_
