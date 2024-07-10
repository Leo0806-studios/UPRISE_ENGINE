

#include "PHYSICS_MANAGER.h"
#include "PHYSICS_OBJECT.h"
#include "THREADING.h"

std::vector < std::shared_ptr<PHYSICS::Physics>> PHYSICS::Physics::physicsobjects;
void PHYSICS::Physics::UpdateAllPhysics()
{
	std::vector<int> posses;
	posses.reserve(physicsobjects.size());
	int i = physicsobjects.size()-1;

	for (; i >= 0; i--) {
		auto a = physicsobjects[i];

		auto aa = CORE::Thread_Manager::CreateThread([a]() { a->UpdatePhysics(); });
		CORE::Thread_Manager::Threads.push_back(&aa);
		//auto o =std::function<void>(a->UpdatePhysics()) ;
		//CORE::Thread thread([a]() { a->UpdatePhysics(); });
		//CORE::Thread thread ([a]() { a->UpdatePhysics(); });
		//a->UpdatePhysics();
	}

}
