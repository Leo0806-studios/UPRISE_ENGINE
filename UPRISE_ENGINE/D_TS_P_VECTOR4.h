#pragma once
#ifndef _T_S_P_VECTOR4
#define _T_S_P_VECTOR4
#include "GLINCLUDES.h"
#include "pch.h"
#include "MODULE_IMPORTS.h"
class TSPVector4 {

public:
	
	float x, y, z, w;
	__inline TSPVector4(__m128 in) { _mm_store_ps(&this->x, in); }
	__inline TSPVector4() = default;
	__inline TSPVector4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {};
	__inline operator glm::vec4() { return glm::vec4(x, y, z, w); }
};
#endif // !_T_S_P_VECTOR4
