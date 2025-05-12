#pragma once
#ifndef UE_SHADER_PROGRAM_BASE_INTERNAL_
#define UE_SADER_PROGRAM_BASE_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_COMMON_COMPS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include <string>
#include <filesystem>
#endif // __INTELLISENSE__
namespace UPRISE_ENGINE {
    class OPENGL_SHADERPROGRAM;
    class VULKAN_SHADERPROGRAM;
    class DIRECTX11_SHADERPROGRAM;
    class DIRECTX12_SHADERPROGRAM;
    class SHADER_BASE;
    namespace RENDER_COMMON {
        class SHADERPROGRAM_BASE {
        private:
            std::string name = "";
        public:

            UPRISE_COMMON_RENDER_COMPS_API  virtual  void* Create(const std::vector<SharedRef<SHADER_BASE, true>>& Shaders) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Use() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Delete() = 0;
            virtual ~SHADERPROGRAM_BASE(){}
        };
    }
}



#endif