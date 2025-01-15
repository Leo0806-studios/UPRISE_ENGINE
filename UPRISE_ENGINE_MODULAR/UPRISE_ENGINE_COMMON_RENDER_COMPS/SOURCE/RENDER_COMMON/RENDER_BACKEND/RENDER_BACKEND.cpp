#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"

namespace RENDER_COMMON {
    void RENDER_BACKEND::DestroyBackend()
    {
        RENDER_BACKEND::_internal_backend->_internal_DestroyBackend();
    }

    RefWrapper<WINDOW_BASE, true> RENDER_BACKEND::CreateWindow(int w, int h, const char* Title)
    {
        return RENDER_BACKEND::_internal_backend->_internal_CreateWindow(w, h, Title);
    }
    class DIRECTX12_BACKEND;
    RefWrapper<RENDER_BACKEND, true> RENDER_BACKEND::CreateBackend(Backend Backend)
    {
       return _Create_Backend(Backend);

    }

    const RefWrapper<RENDER_BACKEND, true>& RENDER_BACKEND::GetBackend()
    {
        return _internal_backend;
    }

    RefWrapper<CONTEXT_BASE, true> RENDER_BACKEND::GetContext()
    {
        return _internal_backend->_internal_Get_Context();
    }

    RefWrapper<SHADER_BASE, true> RENDER_BACKEND::CreateShader(const std::string& ShaderCode)
    {
        return _internal_backend->_internal_Create_Shader(ShaderCode);
    }

    RefWrapper<SHADER_BASE, true> RENDER_BACKEND::CreateShader(const std::filesystem::path& ShaderCode_Path)
    {
        return _internal_backend->_internal_Create_Shader(ShaderCode_Path);
    }

    RefWrapper<SHADER_PROGRAM_BASE, true> RENDER_BACKEND::CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0)
    {
        return _internal_backend->_internal_CreateShaderProgram(Shader0);
    }

    RefWrapper<SHADER_PROGRAM_BASE, true> RENDER_BACKEND::CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1)
    {
        return _internal_backend->_internal_CreateShaderProgram(Shader0, Shader1);
    }

    RefWrapper<SHADER_PROGRAM_BASE, true> RENDER_BACKEND::CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2)
    {
        return _internal_backend->_internal_CreateShaderProgram(Shader0, Shader1, Shader2);
    }

    void RENDER_BACKEND::CreateMaterial()
    {
        _internal_backend->_internal_CreateMaterial();
    }
}

