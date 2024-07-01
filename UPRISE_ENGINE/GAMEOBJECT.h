#pragma once
#include "TRANSFORM.h"
#include "MESH.h"
#include "OBJECT.h"
#include "TS_P_VECTOR3.h"
#include "string"
	class GameObject :CORE::Object{
	public:

		COMPONENTS::Transform Transform;
		COMPONENTS::_Mesh Mesh;
		std::string name;
		GameObject() {};
		static GameObject Create(DATATYPES::TS_P_Vector3 pos) {
			return GameObject();
		}



	};