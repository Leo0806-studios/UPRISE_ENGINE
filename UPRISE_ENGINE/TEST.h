#pragma once
#ifndef _TEST_
#define _TEST_

#include "BEHAVIOUR.h"
#include "INPUT.h"
#include "_COMPONENT.h"
#include "DATATYPES.h"
//class Behaviour;
class Test :public CORE::Behaviour {

public:
	DATATYPES::Quaternion quat;
	DATATYPES::TS_P_Vector3 rrot = DATATYPES::TS_P_Vector3(0,0,0);
	int i = 0;

	Test() {}

	int ID() {
	}
	static UUID UUID;
	GameObject* oobj=nullptr;
	int wo = 4;

	 void Update()override {
		 auto pos = TRANSFORM;
		 ZoneNamedN(testupdate, "Test", true);
		 if (CORE::Input::GetKey(W)) {
			 //std::cout << "test" << wo << "\n";
			 //auto aut = oobj;
			 //std::cout << "name of object is: " << gameobject->name<<"\n";

			 pos->Position = pos->Position -pos->forward.Normalized();

		 }
		 if (CORE::Input::GetKey(S)) {

			 pos->Position = pos->Position + pos->forward.Normalized();
		 }
		 if (CORE::Input::GetKey(A)) {

			 pos->Position = pos->Position - pos->right.Normalized();

		 }
		 if (CORE::Input::GetKey(D)) {
			 pos->Position = pos->Position + pos->right.Normalized();

		 }
		 if (CORE::Input::GetKey(Space)) {
			 pos->Position = pos->Position + pos->up.Normalized();

		 }
		 if (CORE::Input::GetKey(Lshift)) {
			 pos->Position = pos->Position - pos->up.Normalized();

		 }
		 if (CORE::Input::GetKey(Q)) {
			 //quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z + 0.1));
			 rrot.z = rrot.z + 0.1;
			 pos->SetRotation(DATATYPES::TS_P_Vector3(pos->Vec3Rotation.x, pos->Vec3Rotation.y,pos->Vec3Rotation.z + 0.1));

			 //std::cout << "x" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().x << "y" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().y << "Z" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z << "\n";
			// std::cout << "x" << quat.ToRotationVector().x << "y" << quat.ToRotationVector().y << "Z" << quat.ToRotationVector().z << "\n";

		 }
		 if (CORE::Input::GetKey(E)) {
			 rrot.z = rrot.z -0.1;
			 pos->SetRotation(DATATYPES::TS_P_Vector3(pos->Vec3Rotation.x, pos->Vec3Rotation.y, pos->Vec3Rotation.z - 0.1));


			// quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z - 0.1));

			 //std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(DATATYPES::TS_P_Vector3(0, 0, std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z - 1));
			 
		 }
		 if (CORE::Input::GetKey(R)) {

			 rrot.y= rrot.y + 0.1;
			// pos->SetRotation(DATATYPES::TS_P_Vector3(pos->rotation.ToRotationVector().x, pos->rotation.ToRotationVector().y + 0.1, pos->rotation.ToRotationVector().z ));
			 ADDROTATION(0, 0.1, 0)

		 }
		 if (CORE::Input::GetKey(T)) {
			 rrot.y= rrot.y - 0.1;
			// pos->SetRotation(DATATYPES::TS_P_Vector3(pos->rotation.ToRotationVector().x, pos->rotation.ToRotationVector().y - 0.1, pos->rotation.ToRotationVector().z));
			 ADDROTATION(0,-0.1,0)

		 }
		 //std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(rrot);

	}
	 void Awake()override{
	 
		// std::cout << "name of object is: " << gameobject->name << "\n";
	 
	 }
	 void Start()override{}
};
//static Registrar<Test> test("Test");
//template<typename Te>::Test();
#ifndef _REGISTER_TEST_
#define _REGISTER_TEST_
static   Register<Test> teste(Test(), "Test");
#endif
#endif // !_TEST_
