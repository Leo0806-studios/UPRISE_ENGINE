#pragma once
#ifndef _CONTEXT_BASE_
#define _CONTEXT_BASE_
import REF_WRAPPER;
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
        virtual RefWrapper<CONTEXT_BASE, true> _internal_create_context() = 0;
    public:



    };
}

#endif // !_CONTEXT_BASE_
