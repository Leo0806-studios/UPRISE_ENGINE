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

        UPRISE_OPENGL_RENDER_API  static  SharedRef<RENDER_COMMON::RENDER_BACKEND, true>GL_Create_Backend();
        UPRISE_OPENGL_RENDER_API	 void _internal_setup() override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::CONTEXT_BASE, true> _internal_Create_Context() override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode) override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::SHADER_BASE, true> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path) override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader0) override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader0, SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader1) override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader0, SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader1, SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader2) override;
        UPRISE_OPENGL_RENDER_API void _internal_DestroyBackend() override;
        UPRISE_OPENGL_RENDER_API SharedRef<RENDER_COMMON::WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title) override;
        UPRISE_OPENGL_RENDER_API void _internal_CreateMaterial() override;
        UPRISE_OPENGL_RENDER_API unsigned int _internal_Create_Buffer() override;
        UPRISE_OPENGL_RENDER_API void _internal_Destroy_Window(SharedRef<RENDER_COMMON::WINDOW_BASE, true> Window) override;
        UPRISE_OPENGL_RENDER_API void _internal_DestroyBuffer(const unsigned int Buffer) override;
        UPRISE_OPENGL_RENDER_API void _internal_BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_Size, unsigned long bufferType) override;
    public:
    public:
        OPENGL_BACKEND() = default;
        ~OPENGL_BACKEND() = default;
        OPENGL_BACKEND(const OPENGL_BACKEND& other) = default;
        OPENGL_BACKEND(OPENGL_BACKEND&& other) = default;
        OPENGL_BACKEND& operator=(const OPENGL_BACKEND& other) = default;
        OPENGL_BACKEND& operator=(OPENGL_BACKEND&& other) = default;
    };
}

#endif // !_OPENGL_BACKEND_
