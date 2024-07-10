#pragma once
#ifndef _PHYSICS_OBJECT_
#define _PHYSICS_OBJECT_

#include "CORE.h"
#include "PARRALEL_UPDATE.h"

#include "PHYSICS_MANAGER.h"


namespace PHYSICS {
	class Physics;
}
class Physics_Object :public Parallel_Update,public PHYSICS::Physics{
public:

	bool DrawCollider;
	bool disabledSkipp;
	bool isStatic;
	bool haschanged;
	bool isKinematic;
	int ID;
	int Compid;

	 void ParallelUpdate()override{
		 auto a = transf;
	 }
	 void ParallelStart()override {
	 }
	 void ParallelAwake() override {
	 }
	 void UpdatePhysics()override{
	 }
};

#endif // !_PHYSICS_OBJECT_
