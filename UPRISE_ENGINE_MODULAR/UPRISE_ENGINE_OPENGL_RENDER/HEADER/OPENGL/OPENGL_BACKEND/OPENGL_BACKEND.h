#pragma once
#ifndef _OPENGL_BACKEND_
#define _OPENGL_BACKEND_
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
class OPENGL_BACKEND : public RENDER_BACKEND{
private:
	 void _internal_setup() override;
	 RefWrapper<WINDOW_BASE, true> _internal_create_window() override;
	 RefWrapper<CONTEXT_BASE, true> _internal_Get_Context() override;
	 RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode) override;
	 RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path) override;
	 RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0) override;
	 RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1) override;
	 RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2) override;
	 void _internal_DestroyBackend() override;
	 RefWrapper<WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title) override;
	 void _internal_CreateMaterial() override;
public:
	OPENGL_BACKEND() = default;
	~OPENGL_BACKEND(){}
};
#endif // !_OPENGL_BACKEND_
