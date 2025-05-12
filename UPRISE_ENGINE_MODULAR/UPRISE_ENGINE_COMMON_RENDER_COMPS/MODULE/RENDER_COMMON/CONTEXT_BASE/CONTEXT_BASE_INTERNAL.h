#pragma once
#ifndef UE_CONTEXT_BASE_INTERNAL_
#define UE_CONTEXT_BASE_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_COMMON_COMPS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    class OPENGL_CONTEXT;
    class DIRECTX11_CONTEXT;
    class DIRECTX12_CONTEXT;
    class VULKAN_CONTEXT;

    namespace RENDER_COMMON {
        class WINDOW_BASE;
        class CONTEXT_BASE {
        private:

            friend class OPENGL_CONTEXT;
            friend class DIRECTX12_CONTEXT;
            friend class DIRECTX11_CONTEXT;
            friend class VULKAN_CONTEXT;
            virtual OwnedRef<CONTEXT_BASE> _internal_create_context(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window) = 0;
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


#endif