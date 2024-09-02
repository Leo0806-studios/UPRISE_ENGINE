#pragma once
#ifndef _C_BUILDING_
#include "pch.h"
#include "Header/CORE/C_BEHAVIOUR.h"
#define _C_BUILDING_
class C_Building :public CORE::Behaviour {

public:
	static UUID UUID;
	std::string Name;
	std::shared_ptr<CORE::Behaviour> Main_Component;
	int HP;
	
	COPY(C_Building, )
		DEEP_COPY(C_Building, , )
		I_WINDOW_E()
		void Awake()override;
	void Update()override;
	void Start()override;


};


#endif // !_C_BUILDING_
#ifndef _C_BUILDING_REGISTER_
#define _C_BUILDING_REGISTER_
static Register<C_Building> C_Building_Register(C_Building(), "C_Building");
#endif // _C_BUILDING_REGISTER_
