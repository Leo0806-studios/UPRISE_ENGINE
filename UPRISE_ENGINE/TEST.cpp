#include "pch.h"
#include "TEST.h"
#include "GAMEOBJECT.h"

GUID Test::UUID = GUID_NULL;

 void Test::Update() {
	auto pos = TRANSFORM;
	//ZoneNamedN(testupdate, "Test", true);
	if (CORE::Input::GetKey(W)) {
		//std::cout << "test" << wo << "\n";
		//auto aut = oobj;
		//std::cout << "name of object is: " << gameobject->name<<"\n";
		auto aaa = gameobject->TrAnSfOrM->Position - gameobject->TrAnSfOrM->forward.Normalized();

		gameobject->TrAnSfOrM->Position = aaa;
	}
	if (CORE::Input::GetKey(S)) {

		gameobject->TrAnSfOrM->Position = gameobject->TrAnSfOrM->Position + gameobject->TrAnSfOrM->forward.Normalized();
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
		pos->SetRotation(DATATYPES::TS_P_Vector3(pos->Vec3Rotation.x, pos->Vec3Rotation.y, pos->Vec3Rotation.z + 0.1));

		//std::cout << "x" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().x << "y" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().y << "Z" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z << "\n";
		// std::cout << "x" << quat.ToRotationVector().x << "y" << quat.ToRotationVector().y << "Z" << quat.ToRotationVector().z << "\n";

	}
	if (CORE::Input::GetKey(E)) {
		rrot.z = rrot.z - 0.1;
		pos->SetRotation(DATATYPES::TS_P_Vector3(pos->Vec3Rotation.x, pos->Vec3Rotation.y, pos->Vec3Rotation.z - 0.1));


		// quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z - 0.1));

		//std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(DATATYPES::TS_P_Vector3(0, 0, std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z - 1));

	}
	if (CORE::Input::GetKey(R)) {

		rrot.y = rrot.y + 0.1;
		// pos->SetRotation(DATATYPES::TS_P_Vector3(pos->rotation.ToRotationVector().x, pos->rotation.ToRotationVector().y + 0.1, pos->rotation.ToRotationVector().z ));
		ADDROTATION(0, 0.1, 0)

	}
	if (CORE::Input::GetKey(T)) {
		rrot.y = rrot.y - 0.1;
		// pos->SetRotation(DATATYPES::TS_P_Vector3(pos->rotation.ToRotationVector().x, pos->rotation.ToRotationVector().y - 0.1, pos->rotation.ToRotationVector().z));
		ADDROTATION(0, -0.1, 0)

	}
	//std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(rrot);

}
