#pragma once
#ifndef UE_OPENGL_CONTEXT_INTERNAL_
#define UE_OPENGL_CONTEXT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_OPENGL_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"

#endif 

namespace UPRISE_ENGINE {
    namespace RENDER {
        namespace OPENGL_RENDER {
            class CONTEXT_GL_WIN32; //-V3549 //-V2575
            class CONTEXT_GL_LINUX; //-V3549 //-V2575
            class CONTEXT_GL_APPLE; //-V3549 //-V2575
            class CONTEXT_GL_UNIX; //-V3549 //-V2575

#ifdef _WIN32
            using GL_CONTEXT_PLATFORM = CONTEXT_GL_WIN32;
#elif __linux__
            using GL_CONTEXT_PLATFORM = CONTEXT_GL_LINUX
#elif __APPLE__
            using GL_CONTEXT_PLATFORM = CONTEXT_GL_APPLE
#elif __unix__
            using GL_CONTEXT_PLATFORM = CONTEXT_GL_UNIX
#endif 



                typedef void* HGLRC_VoidPtr;
            typedef void* HDC_VoidPtr;
            typedef void* HMODULE_VoidPtr;

            class OPENGL_CONTEXT final: public RENDER_COMMON::CONTEXT_BASE {
            private:
                OwnedRef<GL_CONTEXT_PLATFORM> _platform;
                unsigned long long PixelForatDescriptorHash = 0;
                HGLRC_VoidPtr HGLRC_ptr = nullptr;
                HDC_VoidPtr HDC_ptr = nullptr;
                HMODULE_VoidPtr HMODULE_ptr = nullptr;


            public:
                OPENGL_CONTEXT(const OPENGL_CONTEXT& other) = delete;
                OPENGL_CONTEXT& operator=(const OPENGL_CONTEXT& other) = delete;
                OPENGL_CONTEXT(OPENGL_CONTEXT&& other) :RENDER_COMMON::CONTEXT_BASE(std::move(other)), _platform(std::move(other._platform)) {}
                OPENGL_CONTEXT& operator=(OPENGL_CONTEXT&& other) {
                    if (this != &other) {
                        RENDER_COMMON::CONTEXT_BASE::operator=(std::move(other));
                        _platform = std::move(other._platform);
                    }
                    return *this;
                }

                OPENGL_CONTEXT() noexcept :RENDER_COMMON::CONTEXT_BASE(), _platform{} {};
                ~OPENGL_CONTEXT() = default;

                // Inherited via CONTEXT_BASE
                OwnedRef<CONTEXT_BASE> _internal_create_context(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window) override;
                UPRISE_OPENGL_RENDER_API void _internal_destroy_context() override;
                UPRISE_OPENGL_RENDER_API void PostFrameWork() const;
                UPRISE_OPENGL_RENDER_API void PreFrameWork();
            };
        }

    }
}


#endif




