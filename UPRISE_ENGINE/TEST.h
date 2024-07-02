#pragma once
#include "BEHAVIOUR.h"
class Test :public CORE::Behaviour {

public:
	int ID() {

		
	}
	Test() {
		auto a = this;

		objectss.push_back(std::make_shared<CORE::Behaviour>(this));
		types.push_back(Test);
	}
	 void Update()override {

		std::cout << "test";
	}
};