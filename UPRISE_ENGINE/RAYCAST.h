#pragma once
#ifndef _RAYCAST_
#define _RAYCAST_
#include "RAY.h"
#include "TAG_LAYERS.h"
namespace PHYSICS {

	void RayCast(Ray ray);
	void RayCast(Ray ray,Tag tag);
	void RayCast(Ray ray,Layer layer);
}
#endif // !_RAYCAST_

