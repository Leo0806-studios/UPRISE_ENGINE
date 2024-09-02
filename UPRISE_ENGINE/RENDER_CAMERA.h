#pragma once
#ifndef _RENDER_CAMERA_

#define _RENDER_CAMERA_
#include "pch.h"
#include "MODULE_IMPORTS.h"
#include "TRANSFORM.h"
#include "D_MAT4.h"
namespace PAIN {
	class Shader;
}

namespace PAIN {

	class Render_Camera {
	private:

	public :
		float FOV;


		std::shared_ptr<Transform> transf;
		Render_Camera();
		static Render_Camera Create(std::shared_ptr<Transform> tr);

		__inline glm::mat4 GetViewMatrix() {
			ZoneScoped;
			//TrPr(ctx, __func__)
			//	TrPrE(ctx);
			//return Mat4::Look_At(transf->Position, (transf->Position + transf->forward), transf->up).operator glm::mat<4, 4, float, glm::packed_highp>();
			return Mat4::Look_At_GLM(transf->Position, (transf->Position + transf->forward), transf->up);
			//return glm::lookAt((glm::vec3)transf->Position, (glm::vec3)(transf->Position + transf->forward), (glm::vec3)transf->up);
		}
		//{
		//	return glm::lookAt(Position, Position + Front, Up);
		//}

	};


 }

#endif // !_RENDER_CAMERA_
