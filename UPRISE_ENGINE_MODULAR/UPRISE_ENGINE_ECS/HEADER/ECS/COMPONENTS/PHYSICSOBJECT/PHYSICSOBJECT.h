#pragma once
#ifndef _PhysicsObject_
#define _PhysicsObject_
#include "BEHAVIOUR/BEHAVIOUR.h"
import REF_WRAPPER;
namespace PHYSICS {
	class PhysicsObjectInternal;
}
class PhysicsObject : public CORE::Behaviour {
private:
	RefWrapper< PHYSICS::PhysicsObjectInternal, true> object;
public:
	PhysicsObject() = default;
	~PhysicsObject(){}
	UPRISE_ECS_API void Awake()override;
	UPRISE_ECS_API void Update()override;
	UPRISE_ECS_API void Start()override;
};
#endif // !_PhysicsObject_
