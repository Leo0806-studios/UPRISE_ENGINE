#pragma once
#ifndef _C_RESIDENTIAL_
#define _C_RESIDENTIAL_
#include "pch.h"
#include "Header/CORE/C_BEHAVIOUR.h"
class C_Resitential :public CORE::Behaviour {
public:
	static UUID UUID;
	std::string Name;
	std::shared_ptr<CORE::Behaviour> Main_Component;

	COPY(C_Resitential, )
		DEEP_COPY(C_Resitential, , )
		I_WINDOW_E()
	void Awake()override;
	void Update()override;
	void Start()override;
};
#endif // !1
#ifndef _C_RESIDENTIAL_REGISTER_
#define _C_RESIDENTIAL_REGISTER_
static Register<C_Resitential> C_Resitential_Register(C_Resitential(), "C_Resitential");
#endif // _C_RESIDENTIAL_REGISTER_
