#pragma once
#ifndef _TRANSFORM_
#define _TRANSFORM_

#include "MODULE_IMPORTS.h"
#include "HeaderE/CORE/CORE.h"

///#include "HeaderE/DATATYPES/D_TS_P_VECTOR3.h"
//using namespace DATATYPESTEST;
#include "HeaderE/DATATYPES/D_DATATYPES.h"
#include "DEBUG_LOGGER.h"




	class Transform : public CORE::Behaviour {
	public:
		I_WINDOW(
			ImGui::InputFloat3("Rotation", &this->Vec3Rotation.x);
		this->SetRotation(this -> Vec3Rotation);
		ImGui::InputFloat3("Position", &this->Position.x);
		)
		COPY(Transform, Log << "DONT!"; throw(std::exception());)
			DEEP_COPY(Transform, Log << "DONT!"; throw(std::exception());,)
		static UUID UUID;
		GameObject* oobj = nullptr;

		DATATYPES::TSPVector3 Position;
		DATATYPES::Quaternion rotation;
		DATATYPES::TSPVector3 Vec3Rotation;
		DATATYPES::TSPVector3 forward;
		DATATYPES::TSPVector3 up;
		DATATYPES::TSPVector3 right;
		void SetRotation(DATATYPES::TSPVector3 vec);
		void SetRotation(DATATYPES::Quaternion quat);
		//DATATYPES::TS_P_Vector3 Rotation;;
		void Update()override;
		void Awake()override;
		void Start()override;
		void UpdateDirections();




	};
	//static Registrar<Transform> transform("Transform");

#define ADDROTATION(X,Y,Z) TRANSFORM->SetRotation(DATATYPES::TSPVector3(pos->Vec3Rotation.x+(X), pos->Vec3Rotation.y+(Y), pos->Vec3Rotation.z +(Z)));

#endif // !_TRANSFORM_
