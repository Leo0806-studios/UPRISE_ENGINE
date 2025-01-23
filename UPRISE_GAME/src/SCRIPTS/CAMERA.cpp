// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "CAMERA.h"
GUID Camera::UUID = GUID_NULL;

Camera::Camera(std::shared_ptr<Transform> tr)
{
	TrPr(ctx, __func__)
		//TRANSFORM->UpdateDirections();
		camera = PAIN::Render_Camera::Create(tr);
	TrPrE(ctx);

}
Camera::Camera() {
	TrPr(ctx, __func__)  TrPrE(ctx);
}

void Camera::Awake()
{
	TrPr(ctx, __func__)
		//camera.transform = std::dynamic_pointer_cast<Transform>(transf).get() ;
		TrPrE(ctx);
}

void Camera::Update()
{
	TrPr(ctx, __func__)
		auto pos = TRANSFORM;//std::dynamic_pointer_cast<Transform>(transf).get();
	//ZoneNamedN(testupdate, "Test", true);
	if (CORE::Input::GetKey(I)) {
		//std::cout << "test" << wo << "\n";
		//auto aut = oobj;
		//std::cout << "name of object is: " << gameobject->name<<"\n";

		pos->Position = pos->Position - pos->forward.Normalized();

	}
	if (CORE::Input::GetKey(K)) {

		pos->Position = pos->Position + pos->forward.Normalized();
	}
	if (CORE::Input::GetKey(J)) {

		pos->Position = pos->Position - pos->right.Normalized();

	}
	if (CORE::Input::GetKey(L)) {
		pos->Position = pos->Position + pos->right.Normalized();

	}
	if (CORE::Input::GetKey(M)) {
		CORE::Input::SetMouseMode(CORE::Input::MouseLocked);
	}

	if (CORE::Input::GetKey(N)) {
		CORE::Input::SetMouseMode(CORE::Input::MouseFree);
	}
	if (CORE::Input::MousePosition.x >= 1900) {

		rrot.z = rrot.z + 0.05;
	}
	if (CORE::Input::MousePosition.x <= 10) {
		rrot.z = rrot.z - 0.05;

	}
	if (CORE::Input::MousePosition.y >= 1000) {
		rrot.x = rrot.x + 0.05;

	}
	if (CORE::Input::MousePosition.y <= 10) {
		rrot.x = rrot.x - 0.05;

	}
	//	std::cout << "X" << CORE::Input::MousePosition.x << " Y" << CORE::Input::MousePosition.y << "\n";

		//if (CORE::Input::GetKey(Space)) {
		//	pos->Position = pos->Position + pos->up.Normalized();

		//}
		//if (CORE::Input::GetKey(Lshift)) {
		//	pos->Position = pos->Position - pos->up.Normalized();

		//}
		//if (CORE::Input::GetKey(Q)) {
		//	//quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z + 0.1));
		//	rrot.z = rrot.z + 0.1;
		//	std::cout << "x" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().x << "y" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().y << "Z" << std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z << "\n";
		//	std::cout << "x" << quat.ToRotationVector().x << "y" << quat.ToRotationVector().y << "Z" << quat.ToRotationVector().z << "\n";

		//}
		//if (CORE::Input::GetKey(E)) {
		//	rrot.z = rrot.z - 0.1;

		//	// quat = DATATYPES::Quaternion().FromEulerAngles(DATATYPES::TS_P_Vector3(0, 0, quat.ToRotationVector().z - 0.1));

		//	 //std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(DATATYPES::TS_P_Vector3(0, 0, std::dynamic_pointer_cast<Transform>(transf).get()->rotation.ToRotationVector().z - 1));

		//}
		//if (CORE::Input::GetKey(R)) {

		//	rrot.y = rrot.y + 0.1;
		//}
		//if (CORE::Input::GetKey(T)) {
		//	rrot.y = rrot.y - 0.1;
		//}
		//std::dynamic_pointer_cast<Transform>(transf).get()->SetRotation(rrot);
	TrPrE(ctx);
}

void Camera::Start()
{
	TrPr(ctx, __func__)
		TrPrE(ctx);
}
