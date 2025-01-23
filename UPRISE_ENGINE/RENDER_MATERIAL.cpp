// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "GLINCLUDES.h"
#include "RENDER_MATERIAL.h"
#include "HeaderE/DATATYPES/D_DATATYPES.h"
#include "HeaderE/DATATYPES/D_TERRAIN_DATA.h"
#include "CAMERA.h"
#include "tracy/TracyOpenGL.hpp"
#include "D_MAT4.h"

 PAIN::Material::Material(Shader* shade) {
	 shader = shade;
 }
 PAIN::Material::Material(Shader* shade, int id) { 
	 shader = shade;
	 ID = id; 
 }
 PAIN::Material::Material(Shader shade)
 {
	 Shader_ = shade;
	 shader = &Shader_;
 }
 PAIN::Material::Material(Shader shade,int id)
 {
	 Shader_ = shade;
	 shader = &Shader_;
	 ID = id;

 }
 std::vector<PAIN::Material> PAIN::Render::mats;
 PAIN::Render_Camera* PAIN::Render::RenderCam;
 std::shared_ptr<Camera> PAIN::Render::CAM;
 std::vector<std::shared_ptr<PAIN::TerrainModel>> PAIN::Render::terrains;
 std::unordered_map<std::string, std::shared_ptr<PAIN::Model>> PAIN::Render::Modeldict;
 std::unordered_map<std::string, int> PAIN::Render::MaterialIdLinkDict;
 bool PAIN::Render::Check_Removed = false;
 VEC(PAIN::Shader*) PAIN::Render::Shader_Ptr;
inline void PAIN::Material::DrawObj() {
	//glBindFramebuffer(GL_FRAMEBUFFER, PAIN::Render::FBO);
	
		//shader->use();
	TrPr(ctx01, "Shader Use");
	shader->use();
	TrPrE(ctx01);
	int i = Object_ModelSubstitute.size() - 1;
	for (; i >= 0; i--) {
		TrPr(ctx0,"Draw Mesh")

		if (*Object_ModelSubstitute[i]->_enabled >= 1) {


			//auto poss = std::dynamic_pointer_cast<Transform>(objects[i]->behaviours[1]);

			TrPr(ctx, "Perspective");
			glm::mat4 projection = Mat4::Perspective(CAM->camera.FOV, (float)1600 / (float)900, 0.1f, 500.0f);//glm::perspective(glm::radians(CAM->camera.FOV), (float)1600 / (float)900, 0.1f, 500.0f);
			//Mat4 projection = Mat4::Perspective(CAM->camera.FOV, (float)1600 / (float)900, 0.1f, 500.0f);
			TrPrE(ctx);
			//auto rott = poss.get();
			//auto rot = rott->rotation;
			glm::mat4 view = CAM->camera.GetViewMatrix();
			TrPr(ctx1, "Rotation");
			glm::mat4 rotation = Object_ModelSubstitute[i]->_Transform->rotation.ToMat4();
			TrPrE(ctx1);
			glm::mat4 model = glm::mat4(1.0f);
			//DATATYPES::TS_P_Vector3 pos = std::dynamic_pointer_cast<Transform>(objects[i].get()->behaviours[1]).get()->Position;
			//auto ooo = objects[i]->TrAnSfOrM->Position;
			//pos = ooo->Position;
			TrPr(ctx2, "Translate");
			model = glm::translate(model, glm::vec3(Object_ModelSubstitute[i]->_Transform->Position));
			TrPrE(ctx2);
			TrPr(ctx3, "Set Shader Vars");
			//shader->setMat4("projection", projection.operator glm::mat<4, 4, float, glm::packed_highp>());
			shader->setMat4("projection", projection);
			shader->setMat4("view", view);
			shader->setMat4("model", model);
			shader->setMat4("Rotation", rotation);
			TrPrE(ctx3);

			//auto aa = std::dynamic_pointer_cast<COMPONENTS::_Mesh>(objects[i]->MesH);
			//objects[i]->MESH->Model->Draw(*shader);
			Object_ModelSubstitute[i]->_Model->Draw(*shader);
			//aa.get()->Model.get()->Draw(*shader);
			//auto meesh = (COMPONENTS::_Mesh*)objects[i]->msh;
			//meesh->Model.Draw(*shader);
			//objects[i]->MesH.Model.Draw(*shader);
		}
		//else {
		//	//if //(*Object_ModelSubstitute[i]->_removed == true) {
		//	//	Object_ModelSubstitute[i]->~MiniModel();
		//		Object_ModelSubstitute[i].reset();
		//		Object_ModelSubstitute[i] = NULL;
		//		Object_ModelSubstitute.erase(Object_ModelSubstitute.begin() + i);
		//	}
		//}

		TrPrE(ctx0);
	}
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);

}
unsigned int PAIN::Render::FBO;
  void PAIN::Render::DrawAll() {

	int i = mats.size() - 1;
	for (; i >= 0; i--) {
		TrPr(ctx, "Draw Model");

		mats[i].DrawObj();
		TrPrE(ctx);
	}
	int s = terrains.size()-1;
	for (; s >= 0; s--) {
		terrains[s].get()->DrawObj();
	}
	Check_Removed = false;
	//TrPrE(ctx);
	
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
			  vertex.Position = DATATYPES::TSPVector3(x, data->GetHeight(x, z), z);
			  vertex.Normal = DATATYPES::TSPVector3(0, 1, 0);
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
