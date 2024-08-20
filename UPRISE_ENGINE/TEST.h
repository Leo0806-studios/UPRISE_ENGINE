#pragma once
#ifndef _TEST_
#define _TEST_

#include "HeaderE/CORE/C_BEHAVIOUR.h"
#include "HeaderE/CORE/C_INPUT.h"
#include "_COMPONENT.h"
#include "HeaderE/DATATYPES/D_DATATYPES.h"
//class Behaviour;
class Test :public CORE::Behaviour {

public:
	DATATYPES::Quaternion quat;
	DATATYPES::TSPVector3 rrot = DATATYPES::TSPVector3(0,0,0);
	int i = 0;

	Test() {}

	int ID() {
	}
	static UUID UUID;
	GameObject* oobj=nullptr;
	int wo = 4;
	std::shared_ptr<CORE::Behaviour> Copy()override {
		auto a= std::make_shared<Test>();
		
		std::shared_ptr<CORE::Behaviour> ret = a;
		return ret;
	}
	DEEP_COPY(Test, , )
		I_WINDOW_E()
	 void Update()override;
	 void Awake()override{
	 
		// std::cout << "name of object is: " << gameobject->name << "\n";
	 
	 }
	 void Start()override{}
};
//static Registrar<Test> test("Test");
//template<typename Te>::Test();
#ifndef _REGISTER_TEST_
#define _REGISTER_TEST_
//static   Register <Test> tst(Test(), "Test");
#endif
#endif // !_TEST_
