#pragma once
#ifndef UE_MESH_INTERNAL_
#define UE_MESH_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <vector>
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    namespace RENDER {
        class Vertex;
        class Texture;
        class Shader;
        class Mesh {
        public:
            // mesh data
            std::vector<SharedRef<Vertex, true>> vertices;
            std::vector<unsigned int> indices;
            std::vector<SharedRef<Texture, true>> textures;
            Mesh(std::vector<SharedRef<Vertex, true>> vertices, std::vector<unsigned int> indices,
                std::vector<SharedRef<Texture, true>> textures);
            void Draw(Shader& shader);
        private:
            // render data
            unsigned int VAO, VBO, EBO;//NOSONAR
            char PAD[4];//TODO find a better way to align this or put data here //-V112 //NOSONAR
            void setupMesh();;
        };
    }
}

#endif




