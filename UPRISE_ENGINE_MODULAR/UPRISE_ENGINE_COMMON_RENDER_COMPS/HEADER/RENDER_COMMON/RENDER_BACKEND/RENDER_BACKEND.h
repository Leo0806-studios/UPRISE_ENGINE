#pragma once
#ifndef _RENDER_BACKEND_
#define _RENDER_BACKEND_
import REF_WRAPPER;
import std;
enum Backend {
    B_OPENGL,
    B_VULKAN,
    B_DIRECTX11,
    B_DIRECTX12,

};
class OPENGL_BACKEND;
class DIRECTX11_BACKEND;
class DIRECTX12_BACKEND;
class VULKAN_BACKEND;

class RENDER_BACKEND {
private:
    RENDER_BACKEND() = default;
    ~RENDER_BACKEND() {}
    static RefWrapper<RENDER_BACKEND, true> backend;
    friend class Render;
    friend class RenderSetup;
    friend class OPENGL_BACKEND;
    friend class DIRECTX11_BACKEND;
    friend class DIRECTX12_BACKEND;
    friend class VULKAN_BACKEND;

   // template<class T>
    template<class T, typename std::enable_if<
        std::is_same<T, OPENGL_BACKEND>::value ||
        std::is_same<T, DIRECTX11_BACKEND>::value ||
        std::is_same<T, DIRECTX12_BACKEND>::value ||
        std::is_same<T, VULKAN_BACKEND>::value, int>::type = 0>
    RefWrapper<RENDER_BACKEND, true> createBackend() {
        RefWrapper<T, true> backend = WrapRef<T, true>();
        backend->_internal_setup();
        this->backend = backend;
        return backend;
    }
    virtual void _internal_setup() = 0;
public:
    virtual void DestroyBackend() = 0;
    virtual void CreateWindow(int w, int h, const char* Title) = 0;
    static RefWrapper<RENDER_BACKEND, true> CreateBackend(Backend Backend);
    static RefWrapper<RENDER_BACKEND, true> GetBackend();
};
#endif // !_RENDER_BACKEND_
