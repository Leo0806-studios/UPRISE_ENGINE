#pragma once
#ifndef _RENDER_MATERIAL_
#define _RENDER_MATERIAL_

#include "pch.h"
#include "MODULE_IMPORTS.h"

#include "RENDER_SHADER_UTILLS.h"
#include "RENDER_CAMERA.h"
#include "ECS.h" 
//class CORE::Behaviour;
//class Camera :public CORE::Behaviour;

namespace PAIN {
	
	class MiniModel {
	public:
		MiniModel() = default;
		MiniModel(std::shared_ptr < PAIN::Model> Model, std::shared_ptr<Transform> transf, std::shared_ptr<bool> enabled, std::shared_ptr<bool> removed) {
			_Model = Model; _Transform = transf; _enabled = enabled,_removed=removed;
		}
		~MiniModel() {
			_Model = NULL;
			_Transform = NULL;
			_enabled = NULL;
			_removed = NULL;
		}
		std::shared_ptr < PAIN::Model> _Model;
		std::shared_ptr<Transform> _Transform;
		std::shared_ptr<bool> _enabled;
		std::shared_ptr<bool> _removed;
	};
	class TerrainModel;
	
	class Render {



	public:
		static unsigned int FBO;
		static std::unordered_map<std::string, int> MaterialIdLinkDict;
		static std::unordered_map<std::string, std::shared_ptr<PAIN::Model>> Modeldict;
		static std::vector<PAIN::Material> mats;
		static std::vector<std::shared_ptr<PAIN::TerrainModel>> terrains;
		std::vector< std::shared_ptr<GameObject> > objects;
		VEC(std::shared_ptr<MiniModel>) Object_ModelSubstitute;
		std::vector< std::shared_ptr<CORE::Object> > ptrobjects;
		std::vector< void* > voidobjects;
		static PAIN::Render_Camera* RenderCam;
		static std::shared_ptr<Camera> CAM;
		static VEC(Shader*) Shader_Ptr;
		static bool Check_Removed;
		virtual void DrawObj() = 0;

		static void DrawAll();
		static void Init();

	};

	class Material : public PAIN::Render {
	public:
		int ID;
		Shader* shader;
		Shader Shader_;
		Material(Shader* shade);
		Material(Shader* shade,int id);
		Material(Shader shade);
		Material(Shader shade,int id);
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

	class UiRender {
		VEC(Vertex) Buffer;
		virtual void Draw() = 0;
		static void DrawUI();

	};
}


#endif // !_RENDER_MATERIAL_
