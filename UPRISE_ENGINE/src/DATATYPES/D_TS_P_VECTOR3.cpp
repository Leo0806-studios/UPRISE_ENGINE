// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "HeaderE/DATATYPES/D_TS_P_VECTOR3.h"
#include "GLINCLUDES.h"
#include "pch.h"
using namespace DATATYPES;


 DATATYPES::TSPVector3::TSPVector3() : x(0), y(0), z(0), pad(0) {}



 DATATYPES::TSPVector3::TSPVector3(glm::vec3 vec) {
	x = vec.x; y = vec.y; z = vec.z; pad = 0;

}

 DATATYPES::TSPVector3::TSPVector3(aiVector3D vec) {
	x = vec.x; y = vec.y; z = vec.z; pad = 0;
 }

 TSPVector3& DATATYPES::TSPVector3::operator=(const aiVector3D& other) { TrPr(ctx, __func__) x = other.x; y = other.y; z = other.z; pad = 0;TrPrE(ctx) return *this; }

 DATATYPES::TSPVector3::operator __m128() const {
	 TrPr(ctx, __func__)
	__m128 tmp = _mm_setr_ps(x, y, z, pad);
	 TrPrE(ctx)
	 return tmp;
}

// DATATYPES::TS_P_Vector3::operator aiVector3D() const {
//
//}

 DATATYPES::TSPVector3::operator glm::vec3() const {
	 return glm::vec3(x, y, z);
}

 //float DATATYPES::TSPVector3::magnitude() 

 //TSPVector3 DATATYPES::TSPVector3::Normalized()


 //float DATATYPES::TSPVector3::point(TSPVector3 a) 

 TSPVector3 DATATYPES::TSPVector3::operator/(const float b) {

	 TrPr(ctx, __func__)
		 TSPVector3 _tmp;
	__m128 val = _mm_setr_ps(x, y, z, pad);

	_mm_store_ps(&_tmp.x, _mm_div_ps(val, _mm_set_ps1(b)));
	TrPrE(ctx)
		return _tmp;

}

 TSPVector3 DATATYPES::TSPVector3::operator/(const TSPVector3 b) {
	 TrPr(ctx, __func__)
		 TSPVector3 _tmp;
	__m128 val = _mm_setr_ps(x, y, z, pad);
	__m128 val1 = _mm_setr_ps(b.x, b.y, b.z, b.pad);

	_mm_store_ps(&_tmp.x, _mm_div_ps(val, val1));
	TrPrE(ctx)
		return _tmp;
}

 TSPVector3 DATATYPES::TSPVector3::operator*(const float b) {
	 TrPr(ctx, __func__)
		 TSPVector3 _tmp;
	__m128 val = _mm_setr_ps(x, y, z, pad);

	_mm_store_ps(&_tmp.x, _mm_mul_ps(val, _mm_set_ps1(b)));
	TrPrE(ctx)
		return _tmp;

}

 //TSPVector3 DATATYPES::TSPVector3::operator*(const TSPVector3 b) 

// TSPVector3 DATATYPES::TSPVector3::operator-(const TSPVector3 b) 

 //TSPVector3 DATATYPES::TSPVector3::operator+(const TSPVector3 b)



