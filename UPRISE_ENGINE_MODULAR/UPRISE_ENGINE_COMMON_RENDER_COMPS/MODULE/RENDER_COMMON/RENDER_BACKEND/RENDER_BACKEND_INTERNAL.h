#pragma once
#ifndef UE_RENDER_BACKEND_INTERNAL_
#define UE_RENDER_BACKEND_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_COMMON_COMPS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef UPRISEENGINECOMMONRENDERCOMPS_EXPORTS
#define UPRISE_COMMON_RENDER_COMPS_API __declspec(dllexport)
#endif // UPRISEENGINECOMMONRENDERCOMPS_EXPORTS

#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "string"
#include "filesystem"
#endif // __INTELLISENSE__
namespace UPRISE_ENGINE::RENDER {
        namespace OPENGL_RENDER {
            class OPENGL_BACKEND;
        }
        namespace  DIRECTX11_RENDER {
            class DIRECTX11_BACKEND;
        }
        namespace  DIRECTX12_RENDER {
            class DIRECTX12_BACKEND;
        }
        namespace VULKAN_RENDER {
            class VULKAN_BACKEND;
        }
        class Render;  
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
            friend  RENDER::OPENGL_RENDER::OPENGL_BACKEND;
            friend  DIRECTX11_RENDER::DIRECTX11_BACKEND;
            friend DIRECTX12_RENDER::DIRECTX12_BACKEND;
            friend VULKAN_RENDER::VULKAN_BACKEND;
            friend RENDER::Render;
            using _Create_Backend_FUNC = OwnedRef<RENDER_BACKEND> (*)();
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
            UPRISE_COMMON_RENDER_COMPS_API  virtual  void _internal_BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_Size, unsigned long long  bufferType) = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PreFrameWork() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PostFrameWork() = 0;


        public:
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<RENDER_BACKEND> CreateBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static void DestroyBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static OwnedRef<WINDOW_BASE> _CreateWindow(int w, int h, const char* Title);
            UPRISE_COMMON_RENDER_COMPS_API  static const WeakRef<RENDER_BACKEND, true> GetBackend();
            UPRISE_COMMON_RENDER_COMPS_API static WeakRef<RENDER_COMMON::CONTEXT_BASE, true> CreateContext(WeakRef<RENDER_COMMON::WINDOW_BASE, true> window);
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
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND(RENDER_BACKEND&& other);
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& operator=(const RENDER_BACKEND& other) = delete;
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& operator=(RENDER_BACKEND&& other)noexcept;

        };

    }

}




#endif