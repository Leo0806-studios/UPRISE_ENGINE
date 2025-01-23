// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"

namespace RENDER_COMMON {

    
    RefWrapper<RENDER_BACKEND, true> RENDER_BACKEND::_internal_backend;
    RENDER_BACKEND::_Create_Backend_FUNC RENDER_BACKEND::_Create_Backend = nullptr;
    void RENDER_BACKEND::DestroyBackend()
    {
        RENDER_BACKEND::_internal_backend->_internal_DestroyBackend();
    }

    RefWrapper<WINDOW_BASE, true> RENDER_BACKEND::_CreateWindow(int w, int h, const char* Title)
    {
        return RENDER_BACKEND::_internal_backend->_internal_CreateWindow(w, h, Title);
    }
    class DIRECTX12_BACKEND;
    RefWrapper<RENDER_BACKEND, true> RENDER_BACKEND::CreateBackend()
    { 
       return _Create_Backend();

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
     void RENDER_BACKEND::DestroyWindow(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Window)
    {
         _internal_backend->_internal_Destroy_Window(Window);
    }
}

