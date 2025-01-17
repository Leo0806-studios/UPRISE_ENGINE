#pragma once
#ifndef _RENDER_BACKEND_
#define _RENDER_BACKEND_
//#include "..\WINDOW_BASE\WINDOW_BASE.h"
import REF_WRAPPER;
import std;

class OPENGL_BACKEND;
class DIRECTX11_BACKEND;
class DIRECTX12_BACKEND;
class VULKAN_BACKEND;

namespace RENDER {
    class Render;
}
namespace RENDER_COMMON
{
    class WINDOW_BASE;
    class CONTEXT_BASE;
    class SHADER_BASE;
    class MATERIAL_BASE;
    class SHADER_PROGRAM_BASE;
    enum Backend {
        B_OPENGL,
        B_VULKAN,
        B_DIRECTX11,
        B_DIRECTX12,

    };
    class RENDER_BACKEND {
    private:
        RENDER_BACKEND() = default;
        virtual  ~RENDER_BACKEND() {}
        static RefWrapper<RENDER_BACKEND, true> _internal_backend;
        friend class Render;
        friend class RenderSetup;
        friend  OPENGL_BACKEND;
        friend  DIRECTX11_BACKEND;
        friend DIRECTX12_BACKEND;
        friend VULKAN_BACKEND;
        friend RENDER::Render;
        typedef RefWrapper<RENDER_BACKEND, true>(*_Create_Backend_FUNC)();
        static _Create_Backend_FUNC _Create_Backend;

        virtual void _internal_setup() {};
        virtual RefWrapper<WINDOW_BASE, true> _internal_create_window() {};
        virtual RefWrapper<CONTEXT_BASE, true> _internal_Get_Context()  {};
        virtual RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode)  {};
        virtual RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path)  {};
        virtual RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0)  {};
        virtual RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1) {};
        virtual RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2) {};
        virtual void _internal_DestroyBackend() {};
        virtual RefWrapper<WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title) {};
        virtual void _internal_CreateMaterial() {};
        virtual int _internal_Create_Buffer() {};
        virtual void _internal_DestroyBuffer(int Buffer) {};
        virtual void _internal_BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_Size) {};



    public:
        static RefWrapper<RENDER_BACKEND, true> CreateBackend();
        static void DestroyBackend();
        static RefWrapper<WINDOW_BASE, true> CreateWindow(int w, int h, const char* Title);
        static const RefWrapper<RENDER_BACKEND, true>& GetBackend();
        static RefWrapper<CONTEXT_BASE, true> GetContext();
        static RefWrapper<SHADER_BASE, true> CreateShader(const std::string& ShaderCode);
        static RefWrapper<SHADER_BASE, true> CreateShader(const std::filesystem::path& ShaderCode_Path);
        static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0);
        static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1);
        static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2);
        static void CreateMaterial();///TODO find parameterss+
        static int CreateBuffer();
        static void DestroyBuffer(int Buffer);
        static void BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_size);


    };

}
//template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<DIRECTX12_BACKEND>();
//template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<DIRECTX11_BACKEND>();
//template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<OPENGL_BACKEND>();
//template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<VULKAN_BACKEND>();
#endif // !_RENDER_BACKEND_
