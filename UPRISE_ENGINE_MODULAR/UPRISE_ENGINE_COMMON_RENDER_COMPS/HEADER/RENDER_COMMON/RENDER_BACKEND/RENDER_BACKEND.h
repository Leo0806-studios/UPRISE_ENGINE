#pragma once
#ifndef _RENDER_BACKEND_
#define _RENDER_BACKEND_
//#include "..\WINDOW_BASE\WINDOW_BASE.h"
import REF_WRAPPER;
import std;
enum Backend {
    B_OPENGL,
    B_VULKAN,
    B_DIRECTX11,
    B_DIRECTX12,

};
class OPENGL_BACKEND;
class DIRECTX11_BACKEND;
class DIRECTX12_BACKEND;
class VULKAN_BACKEND;
class WINDOW_BASE;
class CONTEXT_BASE;
class SHADER_BASE;
class MATERIAL_BASE;
class SHADER_PROGRAM_BASE;

class RENDER_BACKEND {
private:
    RENDER_BACKEND() = default;
    ~RENDER_BACKEND() {}
    static RefWrapper<RENDER_BACKEND, true> backend;
    friend class Render;
    friend class RenderSetup;
    friend class OPENGL_BACKEND;
    friend class DIRECTX11_BACKEND;
    friend class DIRECTX12_BACKEND;
    friend class VULKAN_BACKEND;

   // template<class T>
    template<class T, typename std::enable_if<
        std::is_same<T, OPENGL_BACKEND>::value ||
        std::is_same<T, DIRECTX11_BACKEND>::value ||
        std::is_same<T, DIRECTX12_BACKEND>::value ||
        std::is_same<T, VULKAN_BACKEND>::value, int>::type = 0>
    RefWrapper<RENDER_BACKEND, true> createBackend() {
        RefWrapper<T, true> backend = WrapRef<T, true>();
        backend->_internal_setup();
        this->backend = backend;
        return backend;
    }
    virtual void _internal_setup() = 0;
    virtual RefWrapper<WINDOW_BASE, true> _internal_create_window() = 0;
    virtual RefWrapper<CONTEXT_BASE, true> _internal_Get_Context() = 0;
    virtual RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode) = 0;
    virtual RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode_Path) = 0;
    virtual RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0) = 0;
    virtual RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1) = 0;
    virtual RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2) = 0;
    virtual void _internal_DestroyBackend() = 0;
    virtual RefWrapper<WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title);


    

public:
    static void DestroyBackend();
    static RefWrapper<WINDOW_BASE, true> CreateWindow(int w, int h, const char* Title);
    static RefWrapper<RENDER_BACKEND, true> CreateBackend(Backend Backend);
    static RefWrapper<RENDER_BACKEND, true> GetBackend();
    static RefWrapper<CONTEXT_BASE, true> GetContext();
    static RefWrapper<SHADER_BASE, true> CreateShader(const std::string& ShaderCode);
    static RefWrapper<SHADER_BASE, true> CreateShader(const std::filesystem::path& ShaderCode_Path);
    static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0);
    static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1);
    static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2);
    static void CreateMaterial();///TODO find parameterss


};
#endif // !_RENDER_BACKEND_
