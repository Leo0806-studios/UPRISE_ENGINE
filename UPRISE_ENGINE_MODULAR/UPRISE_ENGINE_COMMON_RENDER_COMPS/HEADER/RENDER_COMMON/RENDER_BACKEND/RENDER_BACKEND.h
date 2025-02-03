// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_RENDER_BACKEND_
#define UE_RENDER_BACKEND_
//#include "..\WINDOW_BASE\WINDOW_BASE.h"
import std; //-V2575 //-V3549

import REF_WRAPPER; //-V2575 //-V3549
namespace UPRISE_ENGINE {
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
        public:
            RENDER_BACKEND() = default;
            virtual  ~RENDER_BACKEND() {}
        private:
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<RENDER_BACKEND, true> _internal_backend;
            friend class Render;
            friend class RenderSetup;
            friend  OPENGL_BACKEND;
            friend  DIRECTX11_BACKEND;
            friend DIRECTX12_BACKEND;
            friend VULKAN_BACKEND;
            friend RENDER::Render;
            typedef RefWrapper<RENDER_BACKEND, true>(*_Create_Backend_FUNC)();
            UPRISE_COMMON_RENDER_COMPS_API  static _Create_Backend_FUNC _Create_Backend; //-V2573 //-V3547

            UPRISE_COMMON_RENDER_COMPS_API  virtual void _internal_setup() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   RefWrapper<CONTEXT_BASE, true> _internal_Get_Context() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::string& ShaderCode) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   RefWrapper<SHADER_BASE, true> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual    RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   RefWrapper<SHADER_PROGRAM_BASE, true> _internal_CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_DestroyBackend() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   RefWrapper<WINDOW_BASE, true> _internal_CreateWindow(int w, int h, const char* Title) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_CreateMaterial() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   int _internal_Create_Buffer() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_Destroy_Window(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Window) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual  void _internal_DestroyBuffer(int Buffer) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual  void _internal_BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_Size) = 0;




        public:
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<RENDER_BACKEND, true> CreateBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<WINDOW_BASE, true> _CreateWindow(int w, int h, const char* Title);
            UPRISE_COMMON_RENDER_COMPS_API  static const RefWrapper<RENDER_BACKEND, true>& GetBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<CONTEXT_BASE, true> GetContext();
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<SHADER_BASE, true> CreateShader(const std::string& ShaderCode);
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<SHADER_BASE, true> CreateShader(const std::filesystem::path& ShaderCode_Path);
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0);
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1);
            UPRISE_COMMON_RENDER_COMPS_API  static RefWrapper<SHADER_PROGRAM_BASE, true> CreateShaderProgram(RefWrapper<SHADER_BASE, true> Shader0, RefWrapper<SHADER_BASE, true> Shader1, RefWrapper<SHADER_BASE, true> Shader2);
            UPRISE_COMMON_RENDER_COMPS_API  static void CreateMaterial();///TODO find parameterss+
            UPRISE_COMMON_RENDER_COMPS_API  static int CreateBuffer();
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyWindow(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Window);
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyBuffer(int Buffer);
            UPRISE_COMMON_RENDER_COMPS_API  static void BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_size);


        };

    }
    //template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<DIRECTX12_BACKEND>();
    //template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<DIRECTX11_BACKEND>();
    //template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<OPENGL_BACKEND>();
    //template<> RefWrapper<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<VULKAN_BACKEND>();
}

#endif // !_RENDER_BACKEND_
