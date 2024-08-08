#pragma once
#ifndef _RAY_
#define _RAY_
#include "pch.h"
#include "Header/DATATYPES/D_TS_P_VECTOR3.h"
class GameObject;
class Ray {
public:
	Ray(DATATYPES::TS_P_Vector3 origin,DATATYPES::TS_P_Vector3 direction);
	DATATYPES::TS_P_Vector3 Origin, Direction;
	std::shared_ptr<GameObject> hit;

};
#endif // !_RAY_
