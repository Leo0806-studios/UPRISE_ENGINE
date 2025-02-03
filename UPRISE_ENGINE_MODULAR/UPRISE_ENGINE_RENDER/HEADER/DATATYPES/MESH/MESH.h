// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Mesh_
#define _Mesh_
import std;
import REF_WRAPPER;
namespace UPRISE_ENGINE {
    namespace RENDER {
        class Vertex;
        class Texture;
        class Shader;
        class Mesh {
        public:
            // mesh data
            std::vector<RefWrapper<Vertex, true>> vertices;
            std::vector<unsigned int> indices;
            std::vector<RefWrapper<Texture, true>> textures;
            Mesh(std::vector<RefWrapper<Vertex, true>> vertices, std::vector<unsigned int> indices,
                std::vector<RefWrapper<Texture, true>> textures);
            void Draw(Shader& shader);
            //void Draw(ShaderU& shader);
        private:
            // render data
            unsigned int VAO, VBO, EBO;
            void setupMesh();;
        };
    }
}

#endif // !_Mesh_
