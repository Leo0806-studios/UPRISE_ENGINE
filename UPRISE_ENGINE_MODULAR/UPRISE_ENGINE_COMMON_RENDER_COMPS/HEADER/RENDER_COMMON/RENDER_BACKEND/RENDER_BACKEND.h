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
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<RENDER_BACKEND> _internal_backend;
            friend class Render;
            friend class RenderSetup;
            friend  OPENGL_BACKEND;
            friend  DIRECTX11_BACKEND;
            friend DIRECTX12_BACKEND;
            friend VULKAN_BACKEND;
            friend RENDER::Render;
            typedef OwnedRef<RENDER_BACKEND>(*_Create_Backend_FUNC)();
            UPRISE_COMMON_RENDER_COMPS_API  static _Create_Backend_FUNC _Create_Backend; //-V2573 //-V3547

            UPRISE_COMMON_RENDER_COMPS_API  virtual void _internal_setup() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual WeakRef<RENDER_COMMON::CONTEXT_BASE, true>_internal_Create_Context(WeakRef<RENDER_COMMON::WINDOW_BASE, true> window) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   OwnedRef<SHADER_BASE> _internal_Create_Shader(const std::string& ShaderCode) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   OwnedRef<SHADER_BASE> _internal_Create_Shader(const std::filesystem::path& ShaderCode_Path) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   OwnedRef<SHADER_PROGRAM_BASE> _internal_CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual    OwnedRef<SHADER_PROGRAM_BASE> _internal_CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0, OwnedRef<SHADER_BASE> Shader1) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   OwnedRef<SHADER_PROGRAM_BASE> _internal_CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0, OwnedRef<SHADER_BASE> Shader1, OwnedRef<SHADER_BASE> Shader2) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_DestroyBackend() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   OwnedRef<WINDOW_BASE> _internal_CreateWindow(int w, int h, const char* Title) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_CreateMaterial() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual unsigned  int _internal_Create_Buffer() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_Destroy_Window(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual  void _internal_DestroyBuffer(const unsigned int Buffer) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual  void _internal_BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_Size,unsigned long long  bufferType) = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PreFrameWork() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PostFrameWork() = 0;



        public:
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<RENDER_BACKEND> CreateBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<WINDOW_BASE> _CreateWindow(int w, int h, const char* Title);
            UPRISE_COMMON_RENDER_COMPS_API  static const WeakRef<RENDER_BACKEND,true> GetBackend();
            UPRISE_COMMON_RENDER_COMPS_API static WeakRef<RENDER_COMMON::CONTEXT_BASE,true> CreateContext(WeakRef<RENDER_COMMON::WINDOW_BASE,true> window);
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<SHADER_BASE> CreateShader(const std::string& ShaderCode);
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<SHADER_BASE> CreateShader(const std::filesystem::path& ShaderCode_Path);
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<SHADER_PROGRAM_BASE> CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0);
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<SHADER_PROGRAM_BASE> CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0, OwnedRef<SHADER_BASE> Shader1);
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<SHADER_PROGRAM_BASE> CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0, OwnedRef<SHADER_BASE> Shader1, OwnedRef<SHADER_BASE> Shader2);
            UPRISE_COMMON_RENDER_COMPS_API  static void CreateMaterial();///TODO find parameterss+
            UPRISE_COMMON_RENDER_COMPS_API  static unsigned int CreateBuffer();
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyWindow(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window);
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyBuffer(unsigned int Buffer);
            UPRISE_COMMON_RENDER_COMPS_API  static void BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_size, unsigned long long bufferType);
            UPRISE_COMMON_RENDER_COMPS_API static void PostFrameWork();
            UPRISE_COMMON_RENDER_COMPS_API static void PreFrameWork();


            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND(const RENDER_BACKEND& other) = delete;
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND( RENDER_BACKEND&& other);
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& operator=(const RENDER_BACKEND& other)=delete;
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& operator=( RENDER_BACKEND&& other);

        };

    }
    //template<> SharedRef<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<DIRECTX12_BACKEND>();
    //template<> SharedRef<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<DIRECTX11_BACKEND>();
    //template<> SharedRef<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<OPENGL_BACKEND>();
    //template<> SharedRef<RENDER_COMMON::RENDER_BACKEND, true> RENDER_COMMON::RENDER_BACKEND::createBackend<VULKAN_BACKEND>();
}

#endif // !_RENDER_BACKEND_
