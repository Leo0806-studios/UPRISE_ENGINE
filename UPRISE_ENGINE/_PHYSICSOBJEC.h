#pragma once
#include "BEHAVIOUR.h"
PHYSICS::Physics_Object;
class _PhysicsObject :public CORE::Behaviour {
public:
	PHYSICS::Physics_Object object;
	void Awake()override;
	void Update()override;
	void Start()override;
};