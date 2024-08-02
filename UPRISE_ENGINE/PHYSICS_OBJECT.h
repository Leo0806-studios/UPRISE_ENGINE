#pragma once
#ifndef _PHYSICS_OBJECT_
#define _PHYSICS_OBJECT_

#include "CORE.h"
//#include "PARRALEL_UPDATE.h"

//#include "PHYSICS_MANAGER.h"
#include "TS_P_VECTOR3.h"


namespace PHYSICS {
	class Physics;

}
 struct  TS_P_Collider_box
{
	bool isTrigger;
	TS_P_Vector3 Origin;
	TS_P_Vector3 bounds;
	TS_P_Vector3 a;
	TS_P_Vector3 b;
	TS_P_Vector3 c;
	TS_P_Vector3 d;
	TS_P_Vector3 e;
	TS_P_Vector3 f;
	TS_P_Vector3 g;
	TS_P_Vector3 h;
	// sides : ABCD, A; ABFE, A; BCGF, B; CDHG, C; DAEH, D; EFGH, E
	// plane: (x-p)°n=0
	// line: P=l+Id
	// plane : (x-A)°(ABxAE)=0
	// line p=A+x*(OriginA)
	// intesect: ((x=(p-l)*n)/l*n






};
//class Physics_Object :public Parallel_Update,public PHYSICS::Physics{
//public:
//
//	bool DrawCollider;
//	bool disabledSkipp;
//	bool isStatic;
//	bool haschanged;
//	bool isKinematic;
//	int ID;
//	int Compid;
//	TS_P_Collider_box Collider_Boxes;
//
//
//	 void ParallelUpdate()override;
//	 void ParallelStart()override {
//	 }
//	 void ParallelAwake() override {
//	 }
//	 void UpdatePhysics()override{
//	 }
//
//};

#endif // !_PHYSICS_OBJECT_
