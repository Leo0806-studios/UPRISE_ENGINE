#include "pch.h"
#include "BEHAVIOUR.h"


//	static std::vector<Behaviour*> tester;
//template <class _Ty, class... _Types>
//static std::vector<_Ty> types;

std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::behaviours;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::AWAKES;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::Starts;
 CORE::Behaviour::Behaviour() {}

 CORE::Behaviour::Behaviour(GameObject* oobj, std::shared_ptr<CORE::Behaviour> trans)
 {
	 gameobject = oobj;
	 transf = trans;
 }

 void CORE::Behaviour::updateAll() {

	std::cout << behaviours.size() << "\n";
	for (auto& behaviour : behaviours) {
		behaviour->Update();

	}
}

 void CORE::Behaviour::updateAllAWAKE() {

	for (int i = AWAKES.size() - 1; i >= 0; i--) {

		AWAKES[i]->Awake();
		AWAKES.erase(AWAKES.begin() + i);

	}

}

 void CORE::Behaviour::updateAllSTART() {

	for (int i = Starts.size() - 1; i >= 0; i--) {

		Starts[i]->Start();
		Starts.erase(Starts.begin() + i);

	}
}
