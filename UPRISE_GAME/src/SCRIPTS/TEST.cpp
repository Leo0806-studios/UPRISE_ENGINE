#include "pch.h"
#include "TEST_.h"
#include "GAMEOBJECT.h"
#include "DLL-ENGINE-LINK.h"

GUID Test::UUID = GUID_NULL;

void Test::Update() {
	auto pos = TRANSFORM;
	std::cout << "test" << wo << "\n";

	//ZoneNamedN(testupdate, "Test", true);
	if (IMPORTANT::DATA->GetKey(W)) {
		std::cout << "test" << wo << "\n";
		//auto aut = oobj;
		//std::cout << "name of object is: " << gameobject->name<<"\n";
		TRANSFORM->Position = TRANSFORM->Position - TRANSFORM->forward.Normalized();

		//gameobject->TrAnSfOrM->Position = aaa;
	}
	if (IMPORTANT::DATA->GetKey(S)) {

		TRANSFORM->Position = TRANSFORM->Position + TRANSFORM->forward.Normalized();
	}
	if (IMPORTANT::DATA->GetKey(A)) {

		TRANSFORM->Position = TRANSFORM->Position - TRANSFORM->right.Normalized()*10;

	}
	if (IMPORTANT::DATA->GetKey(D)) {
		TRANSFORM->Position = TRANSFORM->Position + TRANSFORM->right.Normalized();

	}
	if (IMPORTANT::DATA->GetKey(Space)) {
		TRANSFORM->Position = TRANSFORM->Position + TRANSFORM->up.Normalized();

	}
	if (IMPORTANT::DATA->GetKey(Lshift)) {
		TRANSFORM->Position = TRANSFORM->Position - TRANSFORM->up.Normalized();

	}
	if (IMPORTANT::DATA->GetKey(Q)) {
		//quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z + 0.1));
		rrot.z = rrot.z + 0.1;
		TRANSFORM->SetRotation(DATATYPES::TS_P_Vector3(TRANSFORM->Vec3Rotation.x, TRANSFORM->Vec3Rotation.y, TRANSFORM->Vec3Rotation.z + 0.1));

		//std::cout << "x" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().x << "y" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().y << "Z" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z << "\n";
		// std::cout << "x" << quat.ToRotationVector().x << "y" << quat.ToRotationVector().y << "Z" << quat.ToRotationVector().z << "\n";

	}
	if (IMPORTANT::DATA->GetKey(E)) {
		rrot.z = rrot.z - 0.1;
		TRANSFORM->SetRotation(DATATYPES::TS_P_Vector3(TRANSFORM->Vec3Rotation.x, TRANSFORM->Vec3Rotation.y, TRANSFORM->Vec3Rotation.z - 0.1));


		// quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z - 0.1));

		//std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(DATATYPES::TS_P_Vector3(0, 0, std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z - 1));

	}
	if (IMPORTANT::DATA->GetKey(R)) {

		rrot.y = rrot.y + 0.1;
		// pos->SetRotation(DATATYPES::TS_P_Vector3(pos->rotation.ToRotationVector().x, pos->rotation.ToRotationVector().y + 0.1, pos->rotation.ToRotationVector().z ));
		ADDROTATION(0, 0.1, 0)

	}
	if (IMPORTANT::DATA->GetKey(T)) {
		rrot.y = rrot.y - 0.1;
		// pos->SetRotation(DATATYPES::TS_P_Vector3(pos->rotation.ToRotationVector().x, pos->rotation.ToRotationVector().y - 0.1, pos->rotation.ToRotationVector().z));
		ADDROTATION(0, -0.1, 0)

	}
	//std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(rrot);

}
