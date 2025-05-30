#pragma once
#ifndef UE_MODEL_INTERNAL_
#define UE_MODEL_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <string>
#include <vector>
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__
#pragma message("Not fully implemented. assimp types are for now just  forwar declarations")
class aiNode;
class aiScene;
class aiMesh;
class aiMaterial;
class aiTextureType;
namespace UPRISE_ENGINE {
    namespace RENDER {
        class Shader;
        class Mesh;
        class Texture;
        class Model {
        private:
        public:
            Model();
            explicit Model(std::string path);
            void Draw(Shader& shader);
            std::vector<SharedRef<RENDER::Mesh, true>> Meshes;
            static SharedRef<Model, true> Empty() { return SharedRef<RENDER::Model, true>::Create(); }

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
#endif




