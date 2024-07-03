#pragma once

//#include "CORE.h"
#include "ECS.h"
#include "pch.h"
# include "Helpers.h"
#pragma comment(lib, "rpcrt4.lib")  // UuidCreate - Minimum supported OS Win 2000
#include <windows.h>
namespace CORE {


	class Behaviour {

	public:
		//ENTITYS::GameObject gameobject;
		//COMPONENTS::Transform transform;
		static std::vector<std::shared_ptr<CORE::Behaviour>> objectss;
		static std::vector<std::shared_ptr<Behaviour>> behaviours;
		static std::vector<std::shared_ptr<Behaviour>> AWAKES;
		static std::vector<std::shared_ptr<Behaviour>> Starts;
		UUID uuID;
		int id;
	//	static std::vector<Behaviour*> tester;
		//template <class _Ty, class... _Types>
		//static std::vector<_Ty> types;
		Behaviour() {};

		virtual void Update() = 0;
		virtual void Awake() = 0;
		virtual void Start() = 0;
		static void updateAll() {
			for (auto& behaviour : behaviours) {
				behaviour->Update();
				
			}
		}
		static void updateAllAWAKE() {
			for (int i = AWAKES.size() - 1;i>=0 ; i++) {

				AWAKES[i]->Awake();
				AWAKES.erase(AWAKES.begin() + i);

			}

		}
		static void updateAllSTART() {
			for (int i = Starts.size() - 1; i >= 0; i++) {

				Starts[i]->Start();
				Starts.erase(Starts.begin() + i);

			}
		}
		
	};
}