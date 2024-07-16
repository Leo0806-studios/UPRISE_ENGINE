#pragma once
#ifndef _RENDER_CAMERA_

#define _RENDER_CAMERA_
#include "pch.h"
#include "CORE.h"
#include "TRANSFORM.h"
namespace PAIN {
	class Shader;
}

namespace PAIN {

	class Render_Camera {
	private:
		Transform* transf;
	public :
		float FOV;
		void setTransf(std::shared_ptr<CORE::Behaviour> transform) {
			transf = std::dynamic_pointer_cast<Transform>(transform).get();
		}
		Transform* GetTransf() {
			return transf;
		}

		//__declspec(property(get = GetTransf, put = setTransf) )Transform* transform;
		Transform* transform;
		Render_Camera();
		static Render_Camera Create();

		glm::mat4 GetViewMatrix();
		//{
		//	return glm::lookAt(Position, Position + Front, Up);
		//}

	};


 }

#endif // !_RENDER_CAMERA_
