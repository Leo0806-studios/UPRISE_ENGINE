#pragma once
#ifndef _Vertex_
#define _Vertex_
#include "GLOBAL/GLINCLUDES.h"
#include "VECTOR/VECTOR3/FAST/VECTOR3_F.h"
import REF_WRAPPER;
import std;
namespace RENDER{
	class Shader;
	class Vertex {
	private:

	public:
		Vertex() = default;
		~Vertex() {}
		Vector3 position;
		Vector3 normal;
		glm::vec2 texcoords;
	};
}
#endif // !_Vertex_
