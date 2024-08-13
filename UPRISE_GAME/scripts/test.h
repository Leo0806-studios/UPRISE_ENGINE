#pragma once
#include "pch.h"
#include "Header/CORE/C_BEHAVIOUR.h"

class tst : public CORE::Behaviour {
	I_WINDOW_E()
		COPY(tst, );
	DEEP_COPY(tst,,)
	void Awake()override {};
	void Update()override {};
	void Start()override {};
};
class tstwe : public CORE::Behaviour {
	I_WINDOW_E()
		COPY(tstwe, );
	DEEP_COPY(tstwe, , )
	void Awake()override {};
	void Update()override {};
	void Start()override {};
};



#ifndef _TEST_REGISTER_
#define _TEST_REGISTER_
static Register<tst> tst_Register(tst(), "tst");
static Register<tstwe> tstwe_Register(tstwe(), "tstwe");
#endif // _TEST_REGISTER_
