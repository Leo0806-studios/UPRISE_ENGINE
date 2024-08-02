#pragma once

#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include "pch.h"
#include "CORE.h"
#include "DATATYPES.h"
#include "TS_P_QUATERION.h"
#include "TAG_LAYERS.h"

//#include "_COMPONENT.h"
namespace CORE {
	class Behaviour;

}
namespace COMPONENTS {
	class _Mesh;
}
class Transform;


	class GameObject :public CORE::Object {
	private :
	public:
		bool Enabled = true;
		std::shared_ptr<COMPONENTS::_Mesh> MESH;
		std::shared_ptr<Transform> TrAnSfOrM;
		std::shared_ptr<CORE::Behaviour> MesH;
		Tag tag;
		Layer layer;
		void* msh;
		const bool isNull;
		std::string name;
		std::vector<void*> Components;
		std::vector<std::shared_ptr<CORE::Behaviour>> behaviours;
		std::vector<UUID> uuids;
		GameObject():isNull(false) {};
		GameObject(int null) :isNull(true) {};
		GameObject(const GameObject& other)
			: Enabled(other.Enabled),
			MESH(other.MESH),
			TrAnSfOrM(other.TrAnSfOrM),
			MesH(other.MesH),
			msh(other.msh),
			isNull(other.isNull),
			name(other.name),
			Components(other.Components),
			behaviours(other.behaviours),
			uuids(other.uuids) {}

		GameObject& operator=(const GameObject& other) {
			if (this == &other) return *this; // self-assignment guard
			Enabled = other.Enabled;
			MESH = other.MESH;
			TrAnSfOrM = other.TrAnSfOrM;
			MesH = other.MesH;
			msh = other.msh;
			name = other.name;
			Components = other.Components;
			behaviours = other.behaviours;
			uuids = other.uuids;
			return *this;
		}

		static std::shared_ptr<GameObject> Create(DATATYPES::TS_P_Vector3 pos, void* mesh,int materialID);
		static shared_ptr<GameObject> Create(DATATYPES::TS_P_Vector3 pos,Quaternion rot, std::shared_ptr<COMPONENTS::_Mesh> mesh,int materialID);
		static GameObject CreateEmpty(DATATYPES::TS_P_Vector3 pos);
		static GameObject CreateCamera(DATATYPES::TS_P_Vector3 pos, Quaternion rot);


		//void AddComponent(void* component);
#ifdef DEBUG_Engine
		std::shared_ptr<CORE::Behaviour> AddComponent(std::shared_ptr<CORE::Behaviour> component) {

		}
#endif // DEBUG_Engine

		template <class _Ty, class... _Types>
		_Ty* AddComponent(_Ty arg) {
			TracyCZoneN(ctxx, "Adding Component", true);

			if (arg.UUID == GUID_NULL) {
				UUID uuid;
				UuidCreate(&uuid);


				arg.UUID = uuid;
				arg.uuID = arg.UUID;
			}
			uuids.push_back(arg.UUID);

			auto aaa = arg;
			aaa.gameobject = this;
			//aaa.transf = behaviours[1];
			aaa.TRANSFORM = TrAnSfOrM;
			//aa->gameobject = this;
			// 
			std::shared_ptr<CORE::Behaviour> a = std::make_shared<_Ty>(aaa);



			CORE::Behaviour::behaviours.push_back(a);
			CORE::Behaviour::AWAKES.push_back(a);
			CORE::Behaviour::Starts.push_back(a);
			behaviours.push_back(a);
			TracyCZoneEnd(ctxx);

			return std::dynamic_pointer_cast<_Ty>(a).get();
		}


		template <class _Ty, class... _Types>

		void AddComponent(_Ty arg, void* component) {
			TracyCZoneN(ctxx, "Adding Component", true);

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
			TracyCZoneEnd(ctxx);

		}
		//template <class _Ty, class... _Types>

		//void AddComponent(_Ty arg, std::shared_ptr<CORE::Behaviour> component,void* voidcomp);

		template <class _Ty, class... _Types>
		_Ty* GetComponent(_Ty arg) {
			TracyCZoneN(ctxx, "Getting  Component", true);


			for (int i = 0; i < Components.size(); i++) {
				if (arg.UUID == uuids[i]) {

					std::cout << "found";
					TracyCZoneEnd(ctxx);

					return (_Ty*)Components[i];
				}


			}
			TracyCZoneEnd(ctxx);

		}
		template <class _Ty, class... _Types>
		_Ty* GetComponentDynamic(_Ty arg) {
			TracyCZoneN(ctxx, "Getting  Component", true);


			for (int i = 0; i < Components.size(); i++) {
				if (arg.UUID == uuids[i]) {

					std::cout << "found";
					TracyCZoneEnd(ctxx);

					return std::dynamic_pointer_cast<_Ty>(behaviours[i]).get();
				}


			}
			TracyCZoneEnd(ctxx);

		}



	};
#endif // !_GAMEOBJECT_
