#pragma once
#ifndef _Camera_
#define _Camera_
import REF_WRAPPER;
#include "BEHAVIOUR/BEHAVIOUR.h"
namespace RENDER {
	class RenderCam;
}
class Camera:public CORE::Behaviour {
private:
	float fov;
	RefWrapper<RENDER::RenderCam, true> rendercam;
public:
	static UUID uid;

	Camera() = default;
	~Camera(){}
#pragma region Funcs

	UPRISE_ECS_API float& Fov();
	UPRISE_ECS_API void Awake()override;
	UPRISE_ECS_API void Update()override;
	UPRISE_ECS_API void Start()override;
#pragma endregion


};
#endif // !_Camera_
