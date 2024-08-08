#pragma once
#pragma once
#ifndef _DLL_ENGINE_LINK_

#define _DLL_ENGINE_LINK_
#include "pch.h"
#include "GLINCLUDES.h"

namespace CORE {
	class Scene;
}
class Mesh_LINK {
public:

};
class Model_LINK {
	VEC(Mesh_LINK) Meshes;
};
class DATALINK {
public:
	CORE::Scene* ACTIVE_SCENE;
	GLFWwindow* window;
};


	

#endif // !_DLL_ENGINE_LINK_
