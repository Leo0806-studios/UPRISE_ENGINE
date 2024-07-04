#pragma once

#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include "_COMPONENT.h"
#include "CORE.h"
#include "DATATYPES.h"
#include "memory"
#include "OBJECT.h"
#include "string"
#include "MESH.h"
namespace ENTITYS {

	class GameObject :CORE::Object {
	public:

		COMPONENTS::Transform Transform;
		COMPONENTS::_Mesh Mesh;
		std::string name;
		std::vector<void*> Components;
		std::vector<std::shared_ptr<CORE::Behaviour>> behaviours;
		std::vector<UUID> uuids;
		GameObject() {};
		static GameObject Create(DATATYPES::TS_P_Vector3 pos) {
			return GameObject();
		}


		void AddComponent(void* component) {

			Components.push_back(component);
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
			std::shared_ptr<CORE::Behaviour> a = std::make_shared<_Ty>();

			
			CORE::Behaviour::behaviours.push_back(a);
			behaviours.push_back(a);
			
			Components.push_back(component);
		}

		template <class _Ty, class... _Types>
		_Ty* GetComponent(_Ty arg) {
			//auto o = (_Ty*)Conponents[i];
			//_Ty tes;

			for (int i = 0; i < Components.size(); i++) {
				if (arg.UUID == uuids[i]) {

					std::cout << "found";
					return (_Ty*)Components[i];
				}
				//try {
				//	//_Ty *= (_Ty)Conponents[i];
				//	return (_Ty*)Components[i];

				//}
				//catch (exception e) {
				//	return NULL;
				//}
				
			}

			//reurn o;
		}


	};
}
#endif // !_GAMEOBJECT_
