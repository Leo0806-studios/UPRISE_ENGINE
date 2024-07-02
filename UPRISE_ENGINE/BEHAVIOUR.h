#pragma once

#include "ECS.h"
#include "vector"
#include "memory"
namespace CORE {


	class Behaviour {

	public:
		ENTITYS::GameObject gameobject;
		COMPONENTS::Transform transform;
		static std::vector<std::shared_ptr<CORE::Behaviour>> objectss;
		template <class _Ty, class... _Types>
		static std::vector<_Ty> types;
		void update_All() {

			int wi = objectss.size();
			for (int i = 0; i < wi; i++) {
				//auto oo = types[i];
				//auto o = std::dynamic_pointer_cast<types[i]>(objectss[i]);
			}
		}
		virtual void Update() {


		}


		
	};
}