#pragma once
#ifndef _RAYCAST_
#define _RAYCAST_
#include "MODULE_IMPORTS.h"
#include "HeaderE/DATATYPES/D_RAY.h"
#include "HeaderE/DATATYPES/D_TAG_LAYERS.h"
namespace PHYSICS {

	void RayCast(Ray ray);
	void RayCast(Ray ray,Tag tag);
	void RayCast(Ray ray,Layer layer);
}
#endif // !_RAYCAST_

