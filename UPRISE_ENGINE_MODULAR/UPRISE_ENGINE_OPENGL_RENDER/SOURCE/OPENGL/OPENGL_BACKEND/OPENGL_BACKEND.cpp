// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/OPENGL_BACKEND/OPENGL_BACKEND.h"

#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
#include "OPENGL/OPENGL_SHADER/OPENGL_SHADER.h"
#include "OPENGL/OPENGL_CONTEXT/OPENGL_CONTEXT.h"
import GLAD;
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        class OPENGL_WINDOW;

    }
#ifndef UPRISE_TESTS
    OPENGL_BACKEND::ContextList OPENGL_BACKEND::ContextList_;
#endif // !UPRISE_TESTS

    OwnedRef<RENDER_COMMON::RENDER_BACKEND> OPENGL_BACKEND::GL_Create_Backend()
    {
        SCOPED_TIME_
            OwnedRef<RENDER_COMMON::RENDER_BACKEND> a = (CreateRefs::CreateOwnedRef<OPENGL_BACKEND>(OPENGL_BACKEND()));
        return a;

    }

    void OPENGL_BACKEND::_internal_setup()
    {
    }



    WeakRef<RENDER_COMMON::CONTEXT_BASE,true> UPRISE_ENGINE::OPENGL_BACKEND::_internal_Create_Context(WeakRef<RENDER_COMMON::WINDOW_BASE,true> window)
    {
        OwnedRef ctx = CreateRefs::CreateOwnedRef<OPENGL_RENDER::OPENGL_CONTEXT>();
        ctx->_internal_create_context(window);
        ContextList_.push_back(std::move(ctx));
        WeakRef<RENDER_COMMON::CONTEXT_BASE,true> ret = ContextList_.back().GetWeakRef();;
        static auto galdinit = gladLoadGL();
        return ret;
    }

    OwnedRef<RENDER_COMMON::SHADER_BASE> OPENGL_BACKEND::_internal_Create_Shader(const std::string& ShaderCode)
    {
        auto ret = CreateRefs::CreateOwnedRef<OPENGL_RENDER::OPENGL_SHADER>(OPENGL_RENDER::OPENGL_SHADER(ShaderCode));
        return ret;
    }

    OwnedRef<RENDER_COMMON::SHADER_BASE> OPENGL_BACKEND::_internal_Create_Shader(const std::filesystem::path& ShaderCode_Path)
    {
        auto ret = CreateRefs::CreateOwnedRef<OPENGL_RENDER::OPENGL_SHADER>(OPENGL_RENDER::OPENGL_SHADER(ShaderCode_Path));
        ret->Load();
            return ret;
    }

    OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE> OPENGL_BACKEND::_internal_CreateShaderProgram(OwnedRef<RENDER_COMMON::SHADER_BASE> Shader0)
    {
        return OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE>();
    }

    OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE> OPENGL_BACKEND::_internal_CreateShaderProgram(OwnedRef<RENDER_COMMON::SHADER_BASE> Shader0, OwnedRef<RENDER_COMMON::SHADER_BASE> Shader1)
    {
        return OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE>();
    }

    OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE> OPENGL_BACKEND::_internal_CreateShaderProgram(OwnedRef<RENDER_COMMON::SHADER_BASE> Shader0, OwnedRef<RENDER_COMMON::SHADER_BASE> Shader1, OwnedRef<RENDER_COMMON::SHADER_BASE> Shader2)
    {
        return OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE>();
    }

    void OPENGL_BACKEND::_internal_DestroyBackend()
    {
    }

    OwnedRef<RENDER_COMMON::WINDOW_BASE> OPENGL_BACKEND::_internal_CreateWindow(int w, int h, const char* Title)
    {
        SCOPED_TIME_
        OwnedRef<OPENGL_RENDER::OPENGL_WINDOW> a = CreateRefs::CreateOwnedRef<OPENGL_RENDER::OPENGL_WINDOW>(OPENGL_RENDER::OPENGL_WINDOW());
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

    void OPENGL_BACKEND::_internal_Destroy_Window(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window)
    {
        SCOPED_TIME_

        Window->DestroyWindow();
    }

    void OPENGL_BACKEND::_internal_DestroyBuffer(const unsigned int Buffer)
    {
        SCOPED_TIME_
        glDeleteBuffers(1, &Buffer);
        
    }

    void OPENGL_BACKEND::_internal_BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_Size, unsigned long long bufferType)
    {
        SCOPED_TIME_

        

            if (length * Type_Size > static_cast<size_t>(std::numeric_limits<GLsizeiptr>::max()))
            {
                throw std::runtime_error("Buffer too large");
            }

        if (bufferType >= static_cast<size_t>(std::numeric_limits<GLenum>::max()))
        {
            throw std::runtime_error("Buffer type too large");
        }
        glBindBuffer(static_cast<unsigned int>(bufferType), Buffer);
        glBufferData(static_cast<unsigned int>(bufferType), static_cast<signed long long>(length * Type_Size), _Data, _GL_STATIC_DRAW);
    }
    void OPENGL_BACKEND::_internal_PreFrameWork()
    {
        //SCOPED_TIME_

        for (auto& context : ContextList_) {
            context->PreFrameWork();
        }
    }
    void OPENGL_BACKEND::_internal_PostFrameWork()
    {
       // SCOPED_TIME_

        for (auto& context : ContextList_) {
            context->PostFrameWork();
        }
    }
}

