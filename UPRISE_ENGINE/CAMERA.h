#pragma once
#ifndef _CAMERA_

#define _CAMERA_
#include "MODULE_IMPORTS.h"
#include "HeaderE/CORE/C_BEHAVIOUR.h"
#include "pch.h"
#include "RENDER_CAMERA.h"
#include "DEBUG_LOGGER.h"
//#include "HeaderE/CORE/CORE.h"


class Camera : public CORE::Behaviour {
private:
	float fov;

public:
	I_WINDOW(
		/*//ImGui::SliderInt("FOV", &FOV, 0, 90);*/
	ImGui::SliderFloat("FOV Direct", &camera.FOV,0,90);
	)
	COPY(Camera, Log << "DONT";throw(std::exception()))
	DEEP_COPY(Camera, Log << "DONT";throw(std::exception()),)
	DATATYPES::Quaternion quat;
	DATATYPES::TSPVector3 rrot = DATATYPES::TSPVector3(0, 0, 0);
	static UUID UUID;

	Camera(std::shared_ptr<Transform> tr);
	Camera();
	void setfov(float Fow) 
	{
		camera.FOV = Fow;
		Fow = fov;
	}
	int getfov() 
	{
		return fov;
	}
	__declspec(property(get = getfov, put = setfov)) int FOV;
PAIN::Render_Camera camera;


void Awake()override;
void Update()override;
void Start()override;

	};
//static Registrar<Camera> camera("Camera");
#endif // !_CAMERA_
