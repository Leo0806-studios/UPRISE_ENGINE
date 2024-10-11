#pragma once
#ifndef _RenderCamera_
#define _RenderCamera_
#include "GLOBAL/GLINCLUDES.h"
import REF_WRAPPER;
import std;
class Transform;
namespace RENDER{
	class RenderCamera {
	private:


	public:
		float FOV;


		RefWrapper<Transform,true> transf;
		RenderCamera();
		static RenderCamera Create(RefWrapper<Transform,true> tr);

		__inline glm::mat4 GetViewMatrix();
		//{
		//	return glm::lookAt(Position, Position + Front, Up);
		//}

	};
	};

#endif // !_RenderCamera_
