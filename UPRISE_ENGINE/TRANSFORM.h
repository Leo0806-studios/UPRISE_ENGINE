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
		DATATYPES::TS_P_Vector3 Rotation;;
		void Update()override;
		void Awake()override;
		void Start()override;


	};

#endif // !_TRANSFORM_
