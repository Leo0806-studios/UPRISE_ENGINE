// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Vertex_
#define _Vertex_
#include "GLOBAL/GLINCLUDES.h"
#include "VECTOR/VECTOR3/FAST/VECTOR3_F.h"
import REF_WRAPPER;
import std;
namespace UPRISE_ENGINE {
    namespace RENDER {
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
}

#endif // !_Vertex_
