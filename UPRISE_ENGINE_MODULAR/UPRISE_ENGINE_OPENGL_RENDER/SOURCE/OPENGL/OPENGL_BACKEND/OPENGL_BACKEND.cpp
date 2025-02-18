// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/OPENGL_BACKEND/OPENGL_BACKEND.h"

#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
#include "OPENGL/OPENGL_SHADER/OPENGL_SHADER.h"
import GLAD;
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        class OPENGL_WINDOW;

    }
    SharedRef<RENDER_COMMON::RENDER_BACKEND, true> OPENGL_BACKEND::GL_Create_Backend()
    {
        SCOPED_TIME_
        SharedRef<RENDER_COMMON::RENDER_BACKEND, true> a = CreateSharedRef<OPENGL_BACKEND, true>(OPENGL_BACKEND());
        return a;

    }

    void OPENGL_BACKEND::_internal_setup()
    {
    }



    SharedRef<RENDER_COMMON::CONTEXT_BASE, true> OPENGL_BACKEND::_internal_Create_Context()
    {
        return SharedRef<RENDER_COMMON::CONTEXT_BASE, true>();
    }

    SharedRef<RENDER_COMMON::SHADER_BASE, true> OPENGL_BACKEND::_internal_Create_Shader(const std::string& ShaderCode)
    {
        auto ret = CreateSharedRef<OPENGL_RENDER::OPENGL_SHADER, true>(OPENGL_RENDER::OPENGL_SHADER(ShaderCode));
        return ret;
    }

    SharedRef<RENDER_COMMON::SHADER_BASE, true> OPENGL_BACKEND::_internal_Create_Shader(const std::filesystem::path& ShaderCode_Path)
    {
        auto ret = CreateSharedRef<OPENGL_RENDER::OPENGL_SHADER, true>(OPENGL_RENDER::OPENGL_SHADER(ShaderCode_Path));
        ret->Load();
            return ret;
    }

    SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true> OPENGL_BACKEND::_internal_CreateShaderProgram(SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader0)
    {
        return SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true>();
    }

    SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true> OPENGL_BACKEND::_internal_CreateShaderProgram(SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader0, SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader1)
    {
        return SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true>();
    }

    SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true> OPENGL_BACKEND::_internal_CreateShaderProgram(SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader0, SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader1, SharedRef<RENDER_COMMON::SHADER_BASE, true> Shader2)
    {
        return SharedRef<RENDER_COMMON::SHADER_PROGRAM_BASE, true>();
    }

    void OPENGL_BACKEND::_internal_DestroyBackend()
    {
    }

    SharedRef<RENDER_COMMON::WINDOW_BASE, true> OPENGL_BACKEND::_internal_CreateWindow(int w, int h, const char* Title)
    {
        SCOPED_TIME_
        SharedRef<OPENGL_RENDER::OPENGL_WINDOW, true> a = CreateSharedRef<OPENGL_RENDER::OPENGL_WINDOW, true>(OPENGL_RENDER::OPENGL_WINDOW());
        a->CreateWindow(w, h, Title);
        return a;
    }

    void OPENGL_BACKEND::_internal_CreateMaterial()
    {
    }

   unsigned int OPENGL_BACKEND::_internal_Create_Buffer()
    {
        SCOPED_TIME_
            unsigned int buffer;
        glGenBuffers(1, &buffer);
        return buffer;
    }

    void OPENGL_BACKEND::_internal_Destroy_Window(SharedRef<RENDER_COMMON::WINDOW_BASE, true> Window)
    {
        SCOPED_TIME_

        Window->DestroyWindow();
    }

    void OPENGL_BACKEND::_internal_DestroyBuffer(const unsigned int Buffer)
    {
        SCOPED_TIME_
        glDeleteBuffers(1, &Buffer);
        
    }

    void OPENGL_BACKEND::_internal_BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_Size, unsigned long bufferType)
    {
        SCOPED_TIME_

        

            if (length * Type_Size > static_cast<size_t>(std::numeric_limits<GLsizeiptr>::max()))
            {
                throw std::runtime_error("Buffer too large");
            }
        glBindBuffer(bufferType, Buffer);
        glBufferData(bufferType, static_cast<signed long long>(length * Type_Size), _Data, _GL_STATIC_DRAW);
    }
}

