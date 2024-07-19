#pragma once

#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include "pch.h"
#include "CORE.h"
#include "DATATYPES.h"

//#include "_COMPONENT.h"
namespace CORE {
	class Behaviour;

}
namespace COMPONENTS {
	class _Mesh;
}
class Transform;


	class GameObject :public CORE::Object {
	public:
		bool Enabled = true;
		//Transform trans;
		std::shared_ptr<COMPONENTS::_Mesh> MESH;
		std::shared_ptr<Transform> TrAnSfOrM;
		std::shared_ptr<CORE::Behaviour> MesH;
		void* msh;
		std::string name;
		std::vector<void*> Components;
		std::vector<std::shared_ptr<CORE::Behaviour>> behaviours;
		std::vector<UUID> uuids;
		GameObject() {};
		static GameObject Create(DATATYPES::TS_P_Vector3 pos, void* mesh,int materialID);
		static GameObject Create(DATATYPES::TS_P_Vector3 pos, std::shared_ptr<COMPONENTS::_Mesh> mesh,int materialID);
		static GameObject CreateEmpty(DATATYPES::TS_P_Vector3 pos);
		static GameObject CreateCamera(DATATYPES::TS_P_Vector3 pos);


		void AddComponent(void* component);

		template <class _Ty, class... _Types>
		_Ty* AddComponent(_Ty arg) {
			if (arg.UUID == GUID_NULL) {
				UUID uuid;
				UuidCreate(&uuid);


				arg.UUID = uuid;
				arg.uuID = arg.UUID;
			}
			uuids.push_back(arg.UUID);

			auto aaa = _Ty();
			aaa.gameobject = this;
			aaa.transf = behaviours[1];
			aaa.TRANSFORM = TrAnSfOrM;
			//aa->gameobject = this;
			// 
			std::shared_ptr<CORE::Behaviour> a = std::make_shared<_Ty>(aaa);



			CORE::Behaviour::behaviours.push_back(a);
			CORE::Behaviour::AWAKES.push_back(a);
			CORE::Behaviour::Starts.push_back(a);
			behaviours.push_back(a);
			return std::dynamic_pointer_cast<_Ty>(a).get();
		}


		template <class _Ty, class... _Types>

		void AddComponent(_Ty arg, void* component) {
			if (arg.UUID == GUID_NULL) {
				UUID uuid;
				UuidCreate(&uuid);


				arg.UUID = uuid;
				arg.uuID = arg.UUID;
			}
			uuids.push_back(arg.UUID);
			auto aa = (_Ty*)component;
			aa->gameobject = this;
			//aa->gameobject = this;
			std::shared_ptr<CORE::Behaviour> a = std::make_shared<_Ty>(*aa);



			CORE::Behaviour::behaviours.push_back(a);
			CORE::Behaviour::AWAKES.push_back(a);
			CORE::Behaviour::Starts.push_back(a);
			behaviours.push_back(a);

			Components.push_back(component);
		}
		//template <class _Ty, class... _Types>

		//void AddComponent(_Ty arg, std::shared_ptr<CORE::Behaviour> component,void* voidcomp);

		template <class _Ty, class... _Types>
		_Ty* GetComponent(_Ty arg) {


			for (int i = 0; i < Components.size(); i++) {
				if (arg.UUID == uuids[i]) {

					std::cout << "found";
					return (_Ty*)Components[i];
				}


			}
		}
		template <class _Ty, class... _Types>
		_Ty* GetComponentDynamic(_Ty arg) {


			for (int i = 0; i < Components.size(); i++) {
				if (arg.UUID == uuids[i]) {

					std::cout << "found";
					return std::dynamic_pointer_cast<_Ty>(behaviours[i]).get();
				}


			}
		}



	};
#endif // !_GAMEOBJECT_
