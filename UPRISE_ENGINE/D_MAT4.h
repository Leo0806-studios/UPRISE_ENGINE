#pragma once
#ifndef _MAT4_
#define _MAT4_
#include "GLINCLUDES.h"
#include "pch.h"
#include "D_TS_P_VECTOR4.h"
#include"HeaderE/DATATYPES/D_TS_P_VECTOR3.h"
class Mat4 {

public:
	__m128 row0,row1, row2, row3;
	__inline Mat4(float s) :row0(_mm_setr_ps(s, 0, 0, 0)), row1(_mm_setr_ps(0, s, 0, 0)), row2(_mm_setr_ps(0, 0, s, 0)), row3(_mm_setr_ps(0, 0, 0, s)) {}
	__inline operator glm::mat4() { return glm::mat4(TSPVector4(row0), TSPVector4(row1), TSPVector4(row2), TSPVector4(row3)); }
	__inline Mat4 Look_At(DATATYPES::TSPVector3 eye, DATATYPES::TSPVector3 center, DATATYPES::TSPVector3 up) {


	}
	__inline __m128 operator[](int i) {

		if (i > 3)
		{
			Log << "OUT Of RANGE!\n" << "trying to accses memory at: " << &(((__m128*)this)[i]) << "wich is outside the bounds of the mat4" << "\n"; 
			int i = *(int*)(nullptr); //throw error
			
		}
		return (((__m128*)this)[i]);
	}
	__inline float operator()(int r ,int c){
		return(this->operator[](r)).m128_f32[c];
	
	}
};
#endif // !_MAT4_
