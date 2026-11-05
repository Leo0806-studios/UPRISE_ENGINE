#pragma once

#include <string>
#include <filesystem>
#include <memory>
#include <IMPORT_DEFS.h>

namespace UPRISE_ENGINE::RENDER {
    namespace OPENGL_RENDER {
        class OPENGL_SHADERPROGRAM;
    }
    namespace  DIRECTX11_RENDER {
        class DIRECTX11_SHADERPROGRAM;
    }
    namespace  DIRECTX12_RENDER {
        class DIRECTX12_SHADERPROGRAM;
    }
    namespace VULKAN_RENDER {
        class VULKAN_SHADERPROGRAM;
    }

    namespace RENDER_COMMON {
        class SHADER_BASE;

        class SHADERPROGRAM_BASE {
        private:
            std::string name = "";
        public:

            UPRISE_COMMON_RENDER_COMPS_API  virtual  void* Create(const std::vector<std::weak_ptr<SHADER_BASE>>& Shaders) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Use() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Delete() = 0;
            virtual ~SHADERPROGRAM_BASE(){}
        };
    }
}



