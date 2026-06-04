#pragma once
#include "string"
#include "filesystem"
#include <memory>
#include <MACROS.h>

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
        enum Backend {//NOSONAR
            B_OPENGL,
            B_VULKAN,
            B_DIRECTX11,
            B_DIRECTX12,

        };

        class RENDER_BACKEND {//NOSONAR
        public:
            RENDER_BACKEND() = default;
            virtual  ~RENDER_BACKEND() = default;
        private:
            UPRISE_COMMON_RENDER_COMPS_API  static std::shared_ptr<RENDER_BACKEND> _internal_backend;
            UPRISE_COMMON_RENDER_COMPS_API static Backend _internal_backend_type;
            using _Create_Backend_FUNC = std::shared_ptr<RENDER_BACKEND> (*)();
            UPRISE_COMMON_RENDER_COMPS_API  static _Create_Backend_FUNC _Create_Backend; //-V2573 //-V3547
            UPRISE_COMMON_RENDER_COMPS_API static Backend backendType;

            UPRISE_COMMON_RENDER_COMPS_API  virtual void _internal_setup() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_DestroyBackend() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PreFrameWork() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PostFrameWork() = 0;


        public:
            UPRISE_COMMON_RENDER_COMPS_API  static bool CreateBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static bool DestroyBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static const std::weak_ptr<RENDER_BACKEND> GetBackend();
             static void PostFrameWork()
            {
                // SCOPED_TIME_

                _internal_backend->_internal_PostFrameWork();
            }
             static void PreFrameWork()
             {

                _internal_backend->_internal_PreFrameWork();
            }
             UPRISE_COMMON_RENDER_COMPS_API  static Backend GetBackendType() {
                 return backendType;
             }
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND(const RENDER_BACKEND& other) = delete;
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND(RENDER_BACKEND&& other); //NOSONAR
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& operator=(const RENDER_BACKEND& other) = delete;
            UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& operator=(RENDER_BACKEND&& other)noexcept;

        };

    }

}




