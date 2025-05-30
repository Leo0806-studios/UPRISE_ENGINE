#pragma once
#ifndef UE_SHADER_BASE_INTERNAL_
#define UE_SHADER_BASE_INTERNAL_
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
#include <string>
#include <filesystem>
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE::RENDER {
    namespace OPENGL_RENDER {
        class OPENGL_SHADER;
    }
    namespace  DIRECTX11_RENDER {
        class DIRECTX11_SHADER;
    }
    namespace  DIRECTX12_RENDER {
        class DIRECTX12_SHADER;
    }
    namespace VULKAN_RENDER {
        class VULKAN_SHADER;
    }

    namespace RENDER_COMMON {
        enum class ShaderType {
            S_null,
            S_Vertex,
            S_Fragment,
            S_Geometry,
            S_Compute
        };
        class SHADER_BASE {//NOSONAR
        protected:
            friend OPENGL_RENDER::OPENGL_SHADER;
            friend VULKAN_RENDER::VULKAN_SHADER;
            friend DIRECTX11_RENDER::DIRECTX11_SHADER;
            friend DIRECTX12_RENDER::DIRECTX12_SHADER;
            std::string Code;
            std::string Path;
            ShaderType shadertype = ShaderType::S_null;
            char PAD[4]; //TODO find a better way to align this or put data here //-V112 //NOSONAR

        public:
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Compile() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Delete() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Load() = 0;
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE(const SHADER_BASE& other);
            UPRISE_COMMON_RENDER_COMPS_API explicit SHADER_BASE(const std::string& code);
            UPRISE_COMMON_RENDER_COMPS_API explicit SHADER_BASE(const std::filesystem::path& path);
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE() = default;
            virtual ~SHADER_BASE() =default;
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE& operator=(const SHADER_BASE& other);


        };
    }
}

#endif