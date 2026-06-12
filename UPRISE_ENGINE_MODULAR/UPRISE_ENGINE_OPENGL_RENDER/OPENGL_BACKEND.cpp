// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL_BACKEND.h"



namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
        class OpenGlWindow;
#ifndef UPRISE_TESTS
    
#endif // !UPRISE_TESTS

    OwnedRef<RENDER_COMMON::RenderBackend> OpenGlBackend::GL_Create_Backend()
    {
        SCOPED_TIME_
            OwnedRef<RENDER_COMMON::RenderBackend> a = (OwnedRef<OpenGlBackend>::Create(OpenGlBackend()));
        return a;

    }

    



    WeakRef<RENDER_COMMON::CONTEXT_BASE,true> OpenGlBackend::_internal_Create_Context(WeakRef<RENDER_COMMON::Window,true> window)
    {
        OwnedRef ctx = OwnedRef<OpenGlContext>::Create();
        
        ctx->_internal_create_context(window);
        ContextList_.push_back(std::move(ctx));
        WeakRef<RENDER_COMMON::CONTEXT_BASE,true> ret = ContextList_.back().GetWeakRef();;
        static auto galdinit = gladLoadGL();
        return ret;
    }

    OwnedRef<RENDER_COMMON::SHADER_BASE> OpenGlBackend::_internal_Create_Shader(const std::string& ShaderCode)
    {
        auto ret = OwnedRef<OPENGL_SHADER>::Create(OPENGL_SHADER(ShaderCode));
        return ret;
    }

    OwnedRef<RENDER_COMMON::SHADER_BASE> OpenGlBackend::_internal_Create_Shader(const std::filesystem::path& ShaderCode_Path)
    {
        auto ret = OwnedRef<OPENGL_SHADER>::Create(OPENGL_SHADER(ShaderCode_Path));
        ret->Load();
            return ret;
    }

    OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE> OpenGlBackend::_internal_CreateShaderProgram(OwnedRef<RENDER_COMMON::SHADER_BASE> Shader0)
    {
        UE_UNUSED_PARAMETER(Shader0);
        UE_THROW_NOT_IMPLEMENTED;
        return OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE>();
    }

    OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE> OpenGlBackend::_internal_CreateShaderProgram(OwnedRef<RENDER_COMMON::SHADER_BASE> Shader0, OwnedRef<RENDER_COMMON::SHADER_BASE> Shader1)
    {
        UE_UNUSED_PARAMETER(Shader0);
        UE_UNUSED_PARAMETER(Shader1);
        UE_THROW_NOT_IMPLEMENTED;
        return OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE>();
    }

    OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE> OpenGlBackend::_internal_CreateShaderProgram(OwnedRef<RENDER_COMMON::SHADER_BASE> Shader0, OwnedRef<RENDER_COMMON::SHADER_BASE> Shader1, OwnedRef<RENDER_COMMON::SHADER_BASE> Shader2)
    {
        UE_UNUSED_PARAMETER(Shader0);
        UE_UNUSED_PARAMETER(Shader1);
        UE_UNUSED_PARAMETER(Shader2);
        UE_THROW_NOT_IMPLEMENTED;
        return OwnedRef<RENDER_COMMON::SHADER_PROGRAM_BASE>();
    }

    void OpenGlBackend::_internal_DestroyBackend()
    {
    }

    OwnedRef<RENDER_COMMON::Window> OpenGlBackend::_internal_CreateWindow(int w, int h, const char* Title)
    {
        SCOPED_TIME_
        OwnedRef<OpenGlWindow> a = OwnedRef<OPENGL_WINDOW>::Create(OPENGL_WINDOW());
        a->CreateWindow(w, h, Title);
        return a;
    }

    void OpenGlBackend::_internal_CreateMaterial()
    {
    }

   unsigned int OpenGlBackend::_internal_Create_Buffer()
    {
        SCOPED_TIME_
            unsigned int buffer;
        GLAD::glGenBuffers(1, &buffer);
        return buffer;
    }

    void OpenGlBackend::_internal_Destroy_Window(WeakRef<RENDER_COMMON::Window, true> Window)
    {
        SCOPED_TIME_

        Window->DestroyWindow();
    }

    void OpenGlBackend::_internal_DestroyBuffer(const unsigned int Buffer)
    {
        SCOPED_TIME_
        GLAD::glDeleteBuffers(1, &Buffer);
        
    }

    void OpenGlBackend::_internal_BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_Size, unsigned long long bufferType)
    {
        SCOPED_TIME_

        

            if (length * Type_Size > static_cast<size_t>(std::numeric_limits<GLAD::GLsizeiptr>::max()))
            {
                throw std::runtime_error("Buffer too large");
            }

        if (bufferType >= static_cast<size_t>(std::numeric_limits<GLAD::GLenum>::max()))
        {
            throw std::runtime_error("Buffer type too large");
        }
       GLAD:: glBindBuffer(static_cast<unsigned int>(bufferType), Buffer);
        GLAD::glBufferData(static_cast<unsigned int>(bufferType), static_cast<signed long long>(length * Type_Size), _Data, GLAD::CONSTANTS::_GL_STATIC_DRAW);
    }
    void OpenGlBackend::_internal_PreFrameWork()
    {
        //SCOPED_TIME_

        for (auto& context : ContextList_) {
            context->PreFrameWork();
        }
    }
    void OpenGlBackend::_internal_PostFrameWork()
    {
       // SCOPED_TIME_

        for (auto& context : ContextList_) {
            context->PostFrameWork();
        }
    }
}

