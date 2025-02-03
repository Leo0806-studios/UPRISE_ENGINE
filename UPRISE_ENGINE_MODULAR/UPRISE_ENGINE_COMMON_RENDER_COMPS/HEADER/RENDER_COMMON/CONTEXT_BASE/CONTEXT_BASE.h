// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_CONTEXT_BASE_
#define UE_CONTEXT_BASE_
import REF_WRAPPER; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    class OPENGL_CONTEXT;
    class DIRECTX11_CONTEXT;
    class DIRECTX12_CONTEXT;
    class VULKAN_CONTEXT;

    namespace RENDER_COMMON {
        class CONTEXT_BASE {
        private:

            friend class OPENGL_CONTEXT;
            friend class DIRECTX12_CONTEXT;
            friend class DIRECTX11_CONTEXT;
            friend class VULKAN_CONTEXT;
            UPRISE_COMMON_RENDER_COMPS_API virtual RefWrapper<CONTEXT_BASE, true> _internal_create_context() = 0;
        public:



        };
    }
}


#endif // !_CONTEXT_BASE_
