#pragma once
#ifndef _CAMERA_

#define _CAMERA_
#include "pch.h"
#include "COMPONENT.h"
#include "RENDER_CAMERA.h"
//#include "CORE.h"


	class Camera: public CORE::Component {
	public:
		float FOV;
		PAIN::Render_Camera Camera;



	};
#endif // !_CAMERA_
