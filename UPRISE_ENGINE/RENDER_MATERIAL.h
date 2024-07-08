#pragma once
#ifndef _RENDER_MATERIAL_
#define _RENDER_MATERIAL_
#include "pch.h"
#include "RENDER_SHADER_UTILLS.h"
#include "ECS.h" 
namespace PAIN {
	class Render {



	public:
		static std::vector<PAIN::Material> mats;
		std::vector< GameObject* > objects;
		std::vector< std::shared_ptr<CORE::Object> > ptrobjects;
		std::vector< void* > voidobjects;

		virtual void Draw() = 0;

		static void DrawAll();

	};

	class Material : public PAIN::Render {
	public:
		int ID;
		Shader* shader;
		Material(Shader* shade);;
		void Draw()override;
	};
}


#endif // !_RENDER_MATERIAL_
