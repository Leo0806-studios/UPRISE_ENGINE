// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_OPENGL_BACKEND_
#define UE_OPENGL_BACKEND_
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        class WINDOW_BASE;
    }

    class OPENGL_BACKEND : public RENDER_COMMON::RENDER_BACKEND {
    private:
        friend class RENDER::Render;

        UPRISE_OPENGL_RENDER_API  static  RefWrapper<RENDER_COMMON::RENDER_BACKEND, true>GL_Create_Backend();
        UPRISE_OPENGL_RENDER_API	 void _internal_setup() override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::CONTEXT_BASE, true> _internal_Get_Context() override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode) override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::SHADER_BASE, true> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path) override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0) override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader1) override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader1, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader2) override;
        UPRISE_OPENGL_RENDER_API void _internal_DestroyBackend() override;
        UPRISE_OPENGL_RENDER_API RefWrapper<RENDER_COMMON::WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title) override;
        UPRISE_OPENGL_RENDER_API void _internal_CreateMaterial() override;
        UPRISE_OPENGL_RENDER_API int _internal_Create_Buffer() override;
        UPRISE_OPENGL_RENDER_API void _internal_Destroy_Window(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Window) override;
        UPRISE_OPENGL_RENDER_API void _internal_DestroyBuffer(int Buffer) override;
        UPRISE_OPENGL_RENDER_API void _internal_BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_Size) override;
    public:
    public:
        OPENGL_BACKEND() = default;
        ~OPENGL_BACKEND() {}
    };
}

#endif // !_OPENGL_BACKEND_
