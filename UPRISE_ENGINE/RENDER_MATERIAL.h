#pragma once
#ifndef _RENDER_MATERIAL_
#define _RENDER_MATERIAL_
#include "pch.h"
#include "RENDER_SHADER_UTILLS.h"
#include "RENDER_CAMERA.h"
#include "ECS.h" 
namespace PAIN {

	class TerrainModel;
	class Render {



	public:
		static std::unordered_map<std::string, std::shared_ptr<PAIN::Model>> Modeldict;
		static std::vector<PAIN::Material> mats;
		static std::vector<std::shared_ptr<PAIN::TerrainModel>> terrains;
		std::vector< std::shared_ptr<GameObject> > objects;
		std::vector< std::shared_ptr<CORE::Object> > ptrobjects;
		std::vector< void* > voidobjects;
		static PAIN::Render_Camera* RenderCam;
		static std::shared_ptr<CORE::Behaviour> CAM;
		virtual void DrawObj() = 0;

		static void DrawAll();
		static void Init();

	};

	class Material : public PAIN::Render {
	public:
		int ID;
		Shader* shader;
		Material(Shader* shade);;
		void DrawObj()override;
	};
	class TerrainModel : public PAIN::Model, PAIN::Render {
	public:
		void* Terraindata;
		TerrainModel();
		TerrainModel(void* data,int width, int depth, float maxHeight,Shader* shade);
		Shader* shader;
		std::shared_ptr<GameObject> object;
		void DrawObj()override;
		Mesh generateTerrainMesh(int width, int depth, float maxHeight);
		 
	};
}


#endif // !_RENDER_MATERIAL_
