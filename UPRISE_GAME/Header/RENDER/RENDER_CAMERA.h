#pragma once
#ifndef _RENDER_CAMERA_

#define _RENDER_CAMERA_
#include "pch.h"
#include "TRANSFORM.h"
namespace PAIN {
	class Shader;
}

namespace PAIN {

	class Render_Camera {
	private:

	public:
		float FOV;


		std::shared_ptr<Transform> transf;
		Render_Camera();
		static Render_Camera Create(std::shared_ptr<Transform> tr);

		glm::mat4 GetViewMatrix();
		//{
		//	return glm::lookAt(Position, Position + Front, Up);
		//}

	};


}

#endif // !_RENDER_CAMERA_
