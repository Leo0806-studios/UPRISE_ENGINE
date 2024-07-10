#pragma once
#ifndef _PHYSICS_MANAGER_
#define _PHYSICS_MANAGER_
#include "pch.h"
namespace PHYSICS {

	class Physics {
	public :
		static std::vector < std::shared_ptr<PHYSICS::Physics>> physicsobjects;

		virtual void UpdatePhysics() = 0;
		static void UpdateAllPhysics();
	};
}

#endif // !_PHYSICS_MANAGER_
