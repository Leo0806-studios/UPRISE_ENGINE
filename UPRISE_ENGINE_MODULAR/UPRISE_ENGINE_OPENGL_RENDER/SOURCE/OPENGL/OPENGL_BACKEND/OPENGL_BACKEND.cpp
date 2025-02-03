// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/OPENGL_BACKEND/OPENGL_BACKEND.h"

#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        class OPENGL_WINDOW;

    }
    RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> OPENGL_BACKEND::GL_Create_Backend()
    {
        SCOPED_TIME_
        RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> a = WrapRef<OPENGL_BACKEND, true>(OPENGL_BACKEND());
        return a;

    }

    void OPENGL_BACKEND::_internal_setup()
    {
    }



    RefWrapper<RENDER_COMMON::CONTEXT_BASE, true> OPENGL_BACKEND::_internal_Get_Context()
    {
        return RefWrapper<RENDER_COMMON::CONTEXT_BASE, true>();
    }

    RefWrapper<RENDER_COMMON::SHADER_BASE, true> OPENGL_BACKEND::_internal_Create_Shader(const std::string& ShaderCode)
    {
        return RefWrapper<RENDER_COMMON::SHADER_BASE, true>();
    }

    RefWrapper<RENDER_COMMON::SHADER_BASE, true> OPENGL_BACKEND::_internal_Create_Shader(const std::filesystem::path& ShaderCode_Path)
    {
        return RefWrapper<RENDER_COMMON::SHADER_BASE, true>();
    }

    RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> OPENGL_BACKEND::_internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0)
    {
        return RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true>();
    }

    RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> OPENGL_BACKEND::_internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader1)
    {
        return RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true>();
    }

    RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true> OPENGL_BACKEND::_internal_CreateShaderProgram(RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader0, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader1, RefWrapper<RENDER_COMMON::SHADER_BASE, true> Shader2)
    {
        return RefWrapper<RENDER_COMMON::SHADER_PROGRAM_BASE, true>();
    }

    void OPENGL_BACKEND::_internal_DestroyBackend()
    {
    }

    RefWrapper<RENDER_COMMON::WINDOW_BASE, true> OPENGL_BACKEND::_internal_CreateWindow(int w, int h, const char* Title)
    {
        SCOPED_TIME_
        RefWrapper<OPENGL_RENDER::OPENGL_WINDOW, true> a = WrapRef<OPENGL_RENDER::OPENGL_WINDOW, true>(OPENGL_RENDER::OPENGL_WINDOW());
        a->CreateWindow(w, h, Title);
        return a;
    }

    void OPENGL_BACKEND::_internal_CreateMaterial()
    {
    }

    int OPENGL_BACKEND::_internal_Create_Buffer()
    {
        return 0;
    }

    void OPENGL_BACKEND::_internal_Destroy_Window(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Window)
    {
        SCOPED_TIME_

        Window->DestroyWindow();
    }

    void OPENGL_BACKEND::_internal_DestroyBuffer(int Buffer)
    {
    }

    void OPENGL_BACKEND::_internal_BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_Size)
    {
    }
}

