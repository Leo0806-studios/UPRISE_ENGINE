#pragma once
#include "string"
#include "filesystem"
#include <memory>
#include <MACROS.h>

namespace UPRISE_ENGINE::RENDER {
        namespace OPENGL_RENDER {
            class OpenGlBackend;
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
        class Window;
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

        class RenderBackend {//NOSONAR
        public:
            using CreatorFunk = std::unique_ptr<RenderBackend>(*)(std::string Title, int Width, int Height);

            RenderBackend() = default;
            virtual  ~RenderBackend() = default;
        private:
            UPRISE_COMMON_RENDER_COMPS_API  static std::shared_ptr<RenderBackend> _internal_backend;
            UPRISE_COMMON_RENDER_COMPS_API static Backend _internal_backend_type;
            using _Create_Backend_FUNC = std::shared_ptr<RenderBackend> (*)();
            UPRISE_COMMON_RENDER_COMPS_API  static _Create_Backend_FUNC _Create_Backend; //-V2573 //-V3547
            UPRISE_COMMON_RENDER_COMPS_API static Backend backendType;

            UPRISE_COMMON_RENDER_COMPS_API  virtual void _internal_setup() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual   void _internal_DestroyBackend() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PreFrameWork() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_PostFrameWork() = 0;


        public:
            UPRISE_COMMON_RENDER_COMPS_API  static bool CreateBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static bool DestroyBackend();
            UPRISE_COMMON_RENDER_COMPS_API  static const std::weak_ptr<RenderBackend> GetBackend();
            UPRISE_COMMON_RENDER_COMPS_API static bool RegisterWindow(std::shared_ptr<Window> window);
            UPRISE_COMMON_RENDER_COMPS_API static std::shared_ptr<Window> UnregisterWindow(std::weak_ptr<Window> window);
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
            UPRISE_COMMON_RENDER_COMPS_API RenderBackend(const RenderBackend& other) = delete;
            UPRISE_COMMON_RENDER_COMPS_API RenderBackend(RenderBackend&& other); //NOSONAR
            UPRISE_COMMON_RENDER_COMPS_API RenderBackend& operator=(const RenderBackend& other) = delete;
            UPRISE_COMMON_RENDER_COMPS_API RenderBackend& operator=(RenderBackend&& other)noexcept;

        };

    }

}




namespace std {
    std::string to_string(UPRISE_ENGINE::RENDER::RENDER_COMMON::Backend _Val) {
        switch (_Val) {
            using enum UPRISE_ENGINE::RENDER::RENDER_COMMON::Backend;
            case B_OPENGL: return "OPENGL";
            case B_DIRECTX11:return "DIRECTX11";
            case B_DIRECTX12:return "DIRECTX12";
            case B_VULKAN: return "VULKAN";
            default: return "unknown";
        }
    }
}