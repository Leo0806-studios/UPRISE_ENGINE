#pragma once
#ifndef _TRANSFORM_
#define _TRANSFORM_

#include "CORE.h"

///#include "TS_P_VECTOR3.h"
//using namespace DATATYPESTEST;
#include "DATATYPES.h"




	class Transform : public CORE::Behaviour {
	public:
		static UUID UUID;
		GameObject* oobj = nullptr;

		DATATYPES::TS_P_Vector3 Position;
		DATATYPES::Quaternion rotation;
		DATATYPES::TS_P_Vector3 forward;
		DATATYPES::TS_P_Vector3 up;
		DATATYPES::TS_P_Vector3 right;
		void SetRotation(DATATYPES::TS_P_Vector3 vec);
		void SetRotation(DATATYPES::Quaternion quat);
		//DATATYPES::TS_P_Vector3 Rotation;;
		void Update()override;
		void Awake()override;
		void Start()override;
		void UpdateDirections();




	};

#endif // !_TRANSFORM_
