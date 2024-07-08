#pragma once
#ifndef _TEST_
#define _TEST_

#include "BEHAVIOUR.h"
#include "INPUT.h"
#include "_COMPONENT.h"
//class Behaviour;
class Test :public CORE::Behaviour {

public:
	Test() {}

	int ID() {
	}
	static UUID UUID;
	GameObject* oobj=nullptr;
	int wo = 4;

	 void Update()override {
		 ZoneScoped;
		 ZoneText("test update",100);

		 if (CORE::Input::GetKey(W)) {
			 //std::cout << "test" << wo << "\n";
			 //auto aut = oobj;
			 //std::cout << "name of object is: " << gameobject->name<<"\n";

			 std::dynamic_pointer_cast<Transform>(transf).get()->Position.z = std::dynamic_pointer_cast<Transform>(transf).get()->Position.z +1;

		 }
		 if (CORE::Input::GetKey(S)) {

				 std::dynamic_pointer_cast<Transform>(transf).get()->Position.z = std::dynamic_pointer_cast<Transform>(transf).get()->Position.z - 1;
		 }
		 if (CORE::Input::GetKey(A)) {

			 std::dynamic_pointer_cast<Transform>(transf).get()->Position.x =std::dynamic_pointer_cast<Transform>(transf).get()->Position.x - 1;

		 }
		 if (CORE::Input::GetKey(D)) {
			 std::dynamic_pointer_cast<Transform>(transf).get()->Position.x = std::dynamic_pointer_cast<Transform>(transf).get()->Position.x + 1;

		 }
		 if (CORE::Input::GetKey(Space)) {
			 std::dynamic_pointer_cast<Transform>(transf).get()->Position.y = std::dynamic_pointer_cast<Transform>(transf).get()->Position.y + 1;

		 }
		 if (CORE::Input::GetKey(Lshift)) {
			 std::dynamic_pointer_cast<Transform>(transf).get()->Position.y = std::dynamic_pointer_cast<Transform>(transf).get()->Position.y - 1;

		 }
	}
	 void Awake()override{}
	 void Start()override{}
};

#endif // !_TEST_
