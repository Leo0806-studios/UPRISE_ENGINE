#pragma once
#ifndef _OPENGL_BACKEND_
#define _OPENGL_BACKEND_
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
namespace RENDER_COMMON {
    class WINDOW_BASE;
}
class OPENGL_BACKEND : public RENDER_COMMON::RENDER_BACKEND{
private:
    friend class RENDER::Render;


      static  RefWrapper<RENDER_COMMON::RENDER_BACKEND, true>GL_Create_Backend()
    {
    return RefWrapper<RENDER_BACKEND, true>();
    };
      RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> GL_internal_Create_Backend();
	 void _internal_setup() override;
	 RefWrapper<RENDER_COMMON::WINDOW_BASE, true> _internal_create_window() override;
	 RefWrapper<RENDER_COMMON::CONTEXT_BASE, true> _internal_Get_Context() override;
	 RefWrapper<RENDER_COMMON::SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode) override;
	 RefWrapper<RENDER_COMMON::SHADER_BASE, true> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path) override;
	 RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0) override;
	 RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader1) override;
	 RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader1, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader2) override;
	 void _internal_DestroyBackend() override;
	 RefWrapper<RENDER_COMMON::WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title) override;
	 void _internal_CreateMaterial() override;
public:
	OPENGL_BACKEND() = default;
	~OPENGL_BACKEND(){}
};
#endif // !_OPENGL_BACKEND_
