#pragma once
#ifndef _TEST_
#define _TEST_

#include "BEHAVIOUR.h"
#include "INPUT.h"
class Test :public CORE::Behaviour {

public:
	int ID() {

		
	}
	static UUID UUID;
	int wo = 4;
	Test() {
		
		//std::shared_ptr<Behaviour> a = std::make_shared<Test>();
		//behaviours.push_back(a);

		//objectss.push_back(std::make_shared<CORE::Behaviour>(this));
		//tester.push_back(this);
		//types.push_back(Test);
	}
	 void Update()override {
		 if (CORE::Input::GetKey(W)) {
			 std::cout << "test" << wo << "\n";


		 }
	}
	 void Awake()override{}
	 void Start()override{}
};

#endif // !_TEST_
