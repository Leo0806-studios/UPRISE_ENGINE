#pragma once
#include "pch.h"
#include "Header/CORE/C_BEHAVIOUR.h"
#include "Header/CORE/C_INPUT.h"
#include "TRANSFORM.h"
#ifndef _TELEPORT_
#define _TELEPORT_
class Teleport : public CORE::Behaviour {
public:
	static UUID UUID;

	std::shared_ptr<CORE::Behaviour> Copy()override {
		auto a = std::make_shared<Teleport>();

		std::shared_ptr<CORE::Behaviour> ret = a;
		return ret;
	}
	DEEP_COPY(Teleport, , )
		I_WINDOW(

		)
		void Awake()override;
	void Update()override {
		if (CORE::Input::GetKey(Y)) {
			TRANSFORM->Position = DATATYPES::TS_P_Vector3(0, 0, 0);

		}
		if (CORE::Input::GetKey(X)) {
			TRANSFORM->Position = DATATYPES::TS_P_Vector3(1, 1, 1);

		}
	}
	void Start()override {}
};

#endif // !1
#ifndef _TELEPORT_REGISTER_
#define _TELEPORT_REGISTER_
static Register<Teleport> Teleport_Register(Teleport(), "Teleport");
#endif // _TELEPORT_REGISTER_
