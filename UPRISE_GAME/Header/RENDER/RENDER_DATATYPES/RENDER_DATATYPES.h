
#ifndef _RENDER_DATATYPES_
#define _RENDER_DATATYPES_
#include "GLINCLUDES.h"
#include "Header/DATATYPES/D_DATATYPES.h"


#include "pch.h"
namespace PAIN {

	class Render;
}
namespace PAIN {
	class Shader;
}

//#include "assimp/ai_assert.h"

#ifndef _assimp_
#define _assimp_

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#endif // !_assimp_


using namespace std;

namespace PAIN {


	unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);
	struct Vertex {
		DATATYPES::TS_P_Vector3 Position;
		DATATYPES::TS_P_Vector3 Normal;

		glm::vec2 TexCoords;
	};
	struct Texture {
		unsigned int id = 0;
		string type;
		string path;
	};



	class MewshU {

	};

	class ModelU {

	public:
		//Material* material;
		ModelU();;
		//ModelU(Material* mat) { material = mat; };
	};



	class Mesh {
	public:
		// mesh data
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture> textures;
		Mesh(vector<Vertex> vertices, vector<unsigned int> indices,
			vector<Texture> textures);
		void Draw(Shader& shader);
		void Draw(ShaderU& shader);
	private:
		// render data
		unsigned int VAO, VBO, EBO;
		void setupMesh();;
	};

	class Model
	{
	public:
		Model();
		Model(std::string path);
		void Draw(Shader& shader);
		vector<Mesh> meshes;
		static std::shared_ptr<Model> Empty() { return std::make_shared< Model>(); }

	private:
		vector<Texture> textures_loaded;
		// model data
		string directory;
		void loadModel(string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
			string typeName);

		unsigned int TextureFromFile(const char* path, const string& directory, bool gamma);
	};

}
#endif // _RENDER_DATATYPES_
