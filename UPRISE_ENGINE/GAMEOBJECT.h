#pragma once
#include "TRANSFORM.h"
#include "MESH.h"
#include "OBJECT.h"
#include "TS_P_VECTOR3.h"
#include "string"
#include "memory"
namespace ENTITYS {

	class GameObject :CORE::Object {
	public:

		COMPONENTS::Transform Transform;
		COMPONENTS::_Mesh Mesh;
		std::string name;
		std::vector<void*> Conponents;
		GameObject() {};
		static GameObject Create(DATATYPES::TS_P_Vector3 pos) {
			return GameObject();
		}


		void AddComponent(void* component) {

			Conponents.push_back(component);
		}

		template <class _Ty, class... _Types>
		_Ty* GetComponent(_Ty arg) {
			//auto o = (_Ty*)Conponents[i];
			//_Ty tes;
			for (int i = 0; i < Conponents.size(); i++) {

				try {
					//_Ty *= (_Ty)Conponents[i];
					return (_Ty*)Conponents[i];

				}
				catch (exception e) {
					return NULL;
				}
				
			}

			//reurn o;
		}


	};
}
