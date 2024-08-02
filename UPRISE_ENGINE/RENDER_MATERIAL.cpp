#include "pch.h"
#include "GLINCLUDES.h"
#include "RENDER_MATERIAL.h"
#include "DATATYPES.h"
#include "TERRAIN_DATA.h"
#include "CAMERA.h"
 PAIN::Material::Material(Shader* shade) { shader = shade; }
 PAIN::Material::Material(Shader shade)
 {
	 Shader_ = shade;
 }
 std::vector<PAIN::Material> PAIN::Render::mats;
 PAIN::Render_Camera* PAIN::Render::RenderCam;
 std::shared_ptr<Camera> PAIN::Render::CAM;
 std::vector<std::shared_ptr<PAIN::TerrainModel>> PAIN::Render::terrains;
 std::unordered_map<std::string, std::shared_ptr<PAIN::Model>> PAIN::Render::Modeldict;
 std::unordered_map<std::string, int> PAIN::Render::MaterialIdLinkDict;

inline void PAIN::Material::DrawObj() {
	shader->use();
	int i = objects.size() - 1;
	for (; i >= 0; i--) {

		if (objects[i]->Enabled >= 1) {


			//auto poss = std::dynamic_pointer_cast<Transform>(objects[i]->behaviours[1]);

			
			glm::mat4 projection = glm::perspective(glm::radians(CAM->camera.FOV), (float)1600 / (float)900, 0.1f, 500.0f);
			//auto rott = poss.get();
			//auto rot = rott->rotation;
			glm::mat4 view = CAM->camera.GetViewMatrix();
			glm::mat4 rotation = objects[i]->TrAnSfOrM->rotation.ToMat4();
			glm::mat4 model = glm::mat4(1.0f);
			DATATYPES::TS_P_Vector3 pos = std::dynamic_pointer_cast<Transform>(objects[i].get()->behaviours[1]).get()->Position;
			//auto ooo = objects[i]->TrAnSfOrM->Position;
			//pos = ooo->Position;
			model = glm::translate(model, (glm::vec3)objects[i]->TrAnSfOrM->Position);
			shader->setMat4("projection", projection);
			shader->setMat4("view", view);
			shader->setMat4("model", model);
			shader->setMat4("Rotation", rotation);

			//auto aa = std::dynamic_pointer_cast<COMPONENTS::_Mesh>(objects[i]->MesH);
			objects[i]->MESH->Model->Draw(*shader);
			//aa.get()->Model.get()->Draw(*shader);
			//auto meesh = (COMPONENTS::_Mesh*)objects[i]->msh;
			//meesh->Model.Draw(*shader);
			//objects[i]->MesH.Model.Draw(*shader);
		}
	}
}

  void PAIN::Render::DrawAll() {
	int i = mats.size() - 1;
	for (; i >= 0; i--) {


		mats[i].DrawObj();
	}
	int s = terrains.size()-1;
	for (; s >= 0; s--) {
		terrains[s].get()->DrawObj();
	}
}

  void PAIN::Render::Init()
  {
  }

  PAIN::TerrainModel::TerrainModel()
  {
  }

  PAIN::TerrainModel::TerrainModel(void* data,int width, int depth, float maxHeight, Shader* shade)
  {
	  shader = shade;
	  Terraindata = data;
	  
	  meshes.push_back(generateTerrainMesh(width, depth, maxHeight));
  }

  void PAIN::TerrainModel::DrawObj()
  {
	  auto poss = std::dynamic_pointer_cast<Transform>(object->behaviours[1]);

	  glm::mat4 projection = glm::perspective(glm::radians(std::dynamic_pointer_cast<Camera>(CAM).get()->camera.FOV), (float)1600 / (float)900, 0.1f, 500.0f);
	  glm::mat4 view = std::dynamic_pointer_cast<Camera>(CAM).get()->camera.GetViewMatrix();
	  glm::mat4 rotation = poss.get()->rotation.ToMat4();
	  glm::mat4 model = glm::mat4(1.0f);
	  model = glm::translate(model, (glm::vec3)poss.get()->Position);
	  shader->setMat4("projection", projection);
	  shader->setMat4("view", view);
	  shader->setMat4("model", model);
	  shader->setMat4("Rotation", rotation);
	  std::dynamic_pointer_cast<Terrain_Data>(object.get()->behaviours[0]).get()->model.Draw(*shader);


  }

  PAIN::Mesh PAIN::TerrainModel::generateTerrainMesh(int width, int depth, float maxHeight)
  {
	  auto data = (Terrain_Data*)Terraindata;
	  std::vector<Vertex> vertices;
	  std::vector<unsigned int> indices;
	  Vertex vertex;
	  for (int z = 0; z < depth; z++) {

		  for (int x = 0; x < width; x++) {
			  vertex.Position = DATATYPES::TS_P_Vector3(x, data->GetHeight(x, z), z);
			  vertex.Normal = DATATYPES::TS_P_Vector3(0, 1, 0);
			  vertex.TexCoords = glm::vec2((float)x / data->width, (float)z / data->depth);
			  vertices.push_back(vertex);
		  }

	  }
	  for (int z = 0; z < data->depth - 1; ++z) {
		  for (int x = 0; x < data->width - 1; ++x) {
			  int topLeft = z * data->width + x;
			  int topRight = topLeft + 1;
			  int bottomLeft = (z + 1) * data->width + x;
			  int bottomRight = bottomLeft + 1;

			  indices.push_back(topLeft);
			  indices.push_back(bottomLeft);
			  indices.push_back(topRight);

			  indices.push_back(topRight);
			  indices.push_back(bottomLeft);
			  indices.push_back(bottomRight);
		  }
	  }
	  return Mesh(vertices, indices, std::vector<Texture>());
  }
