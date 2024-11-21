#pragma once
#ifndef _CONTEXT_BASE_
#define _CONTEXT_BASE_
class OPENGL_CONTEXT;
class DIRECTX11_CONTEXT;
class DIRECTX12_CONTEXT;
class VULKAN_CONTEXT;

class CONTEXT_BASE {
private:

    friend class OPENGL_CONTEXT;
    friend class DIRECTX12_CONTEXT;
    friend class DIRECTX11_CONTEXT;
    friend class VULKAN_CONTEXT;
public:

    

};
#endif // !_CONTEXT_BASE_
