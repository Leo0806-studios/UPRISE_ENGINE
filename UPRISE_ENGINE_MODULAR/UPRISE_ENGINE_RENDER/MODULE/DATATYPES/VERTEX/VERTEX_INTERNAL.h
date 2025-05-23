#pragma once
#ifndef UE_VERTEX_INTERNAL_
#define UE_VERTEX_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__


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
            Vector2 texcoords;
        };
    }
}
#endif




