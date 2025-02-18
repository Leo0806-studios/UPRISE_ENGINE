// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Model_
#define _Model_
#include "GLOBAL/GLINCLUDES.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
import std;
import REF_WRAPPER;
namespace UPRISE_ENGINE {
    namespace RENDER {
        class Shader;
        class Mesh;
        class Texture;
        class Model {
        private:
        public:
            Model();
            Model(std::string path);
            void Draw(Shader& shader);
            std::vector<SharedRef<RENDER::Mesh, true>> Meshes;
            static SharedRef<Model, true> Empty() { return CreateSharedRef<RENDER::Model, true>(); }

        private:
            std::vector<SharedRef<RENDER::Texture, true>> textures_loaded;
            // model data
            std::string directory;
            void loadModel(std::string path);
            void processNode(aiNode* node, const aiScene* scene);
            Mesh processMesh(aiMesh* mesh, const aiScene* scene);
            std::vector<SharedRef<Texture, true>> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
                std::string typeName);

            unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma);
        };
    }
}

#endif // !_Model_
