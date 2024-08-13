#pragma once
#ifndef _TS_P_VECTOR2_
#define _TS_P_VECTOR2_
#include "pch.h"


struct TS_P_Vector2 {
	float x;
	float y;
	float pad1, pad2;
	TS_P_Vector2();
	TS_P_Vector2(float x, float y);
	TS_P_Vector2(const TS_P_Vector2& other) = default;
	//TS_P_Vector2(glm::vec3 vec);

	//TS_P_Vector2(aiVector3D vec);
	TS_P_Vector2& operator=(const TS_P_Vector2& other) = default;
	//TS_P_Vector2& operator=(const aiVector3D& other);;
	operator __m128()const;
	//operator aiVector3D() const;
	//operator glm::vec3()const;

	float magnitude();
	TS_P_Vector2 Normalized();

	float point(TS_P_Vector2 a);

	TS_P_Vector2 operator /(const float b);
	TS_P_Vector2 operator/(const TS_P_Vector2 b);
	TS_P_Vector2 operator *(const float b);
	TS_P_Vector2 operator*(const TS_P_Vector2 b);
	TS_P_Vector2 operator -(const TS_P_Vector2 b);
	TS_P_Vector2 operator+(const TS_P_Vector2 b);
};
#endif // !_TS_P_VECTOR2_
