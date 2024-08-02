#pragma once
#ifndef _CAMERA_

#define _CAMERA_
#include "BEHAVIOUR.h"
#include "pch.h"
#include "RENDER_CAMERA.h"
//#include "CORE.h"


class Camera : public CORE::Behaviour {
private:
	float fov;

public:
	DATATYPES::Quaternion quat;
	DATATYPES::TS_P_Vector3 rrot = DATATYPES::TS_P_Vector3(0, 0, 0);
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
