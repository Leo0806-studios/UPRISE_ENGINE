#pragma once
#ifndef UE_WINDOW_INTERNAL_
#define UE_WINDOW_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif

#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

#ifdef UPRISEENGINERENDER_EXPORTS
#define UPRISE_RENDER_API __declspec(dllexport)
#endif // UPRISEENGINERENDER_EXPORTS


namespace UPRISE_ENGINE {
    namespace RENDER::RENDER_COMMON {
        class WINDOW_BASE;
    }

    namespace RENDER {
        class Window {
        private:
            OwnedRef<RENDER_COMMON::WINDOW_BASE> Windowvar;
        public:
            Window() = default;
            Window(const Window&) = delete;
            Window(Window&& other) :Windowvar(std::move(other.Windowvar)) {
            }
            Window& operator=(const Window&) = delete;
            Window& operator=(Window&& other) {
                Windowvar = std::move(other.Windowvar);
                return *this;
            }
            UPRISE_RENDER_API  inline void SetWindow(OwnedRef<RENDER_COMMON::WINDOW_BASE> window) {

                SCOPED_TIME_
                    Windowvar = std::move(window);
            }
            UPRISE_RENDER_API inline WeakRef<RENDER_COMMON::WINDOW_BASE, true> GetInternalWeakRef() {
                return Windowvar.GetWeakRef();
            }
            UPRISE_RENDER_API static  OwnedRef<RENDER_COMMON::WINDOW_BASE> _CreateWindow(int w, int h, const char* title);
            UPRISE_RENDER_API static  void DestroyWindow(WeakRef<Window, true> window);
            UPRISE_RENDER_API void DisplayFpsInWindowTitle(double Fps, std::string BaseTitle);
        };
    }

}

#endif




