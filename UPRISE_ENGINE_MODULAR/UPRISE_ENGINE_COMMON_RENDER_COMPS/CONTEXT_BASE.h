#pragma once

#include <memory>
#include <MACROS.h>
namespace UPRISE_ENGINE ::RENDER{
    namespace OPENGL_RENDER {
        class OPENGL_CONTEXT;

    }
    namespace DIRECTX11_RENDER {
        class DIRECTX11_CONTEXT;
    }
    namespace DIRECTX12_RENDER {
        class DIRECTX12_CONTEXT;
    }
    namespace VULKAN_RENDER {
        class VULKAN_CONTEXT;
    }

    namespace RENDER_COMMON {
        class WINDOW_BASE;
        class CONTEXT_BASE {
        private:

            friend class OPENGL_CONTEXT;
            friend class DIRECTX12_CONTEXT;
            friend class DIRECTX11_CONTEXT;
            friend class VULKAN_CONTEXT;
            virtual std::unique_ptr<CONTEXT_BASE> _internal_create_context(std::weak_ptr<RENDER_COMMON::WINDOW_BASE> Window) = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void _internal_destroy_context() = 0;
        public:
            CONTEXT_BASE(const CONTEXT_BASE&) = delete;
            CONTEXT_BASE(CONTEXT_BASE&&)noexcept = default;
            CONTEXT_BASE& operator=(const CONTEXT_BASE&) = delete;
            CONTEXT_BASE& operator=(CONTEXT_BASE&&)noexcept = default;
            UPRISE_COMMON_RENDER_COMPS_API virtual ~CONTEXT_BASE();
            CONTEXT_BASE()noexcept = default;


        };
    }
}


