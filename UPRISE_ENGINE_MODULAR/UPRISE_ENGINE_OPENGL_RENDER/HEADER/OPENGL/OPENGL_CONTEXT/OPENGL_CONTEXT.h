// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _OPENGL_CONTEXT_
#define _OPENGL_CONTEXT_
#include "RENDER_COMMON/CONTEXT_BASE/CONTEXT_BASE.h"
class CONTEXT_GL_WIN32; //-V3549 //-V2575
class CONTEXT_GL_LINUX; //-V3549 //-V2575
class CONTEXT_GL_APPLE; //-V3549 //-V2575
class CONTEXT_GL_UNIX; //-V3549 //-V2575

#ifdef _WIN32

#define UE_GL_WIN_32_PLATFORM_CTX CONTEXT_GL_WIN32
#define UE_GL_LINUX_PLATFORM_CTX
#define APPLE_PLATFORM_CTX
#define UNIX_PLATFORM_CTX

#endif // _WIN32



#ifdef __linux__

#define UE_GL_WIN_32_PLATFORM_CTX 
#define UE_GL_LINUX_PLATFORM_CTX CONTEXT_GL_LINUX
#define APPLE_PLATFORM_CTX
#define UNIX_PLATFORM_CTX

#endif // __linux__


#ifdef __APPLE__

#define UE_GL_WIN_32_PLATFORM_CTX
#define UE_GL_LINUX_PLATFORM_CTX
#define APPLE_PLATFORM_CTX CONTEXT_GL_APPLE
#define UNIX_PLATFORM_CTX

#endif // __APPLE__


#ifdef __unix__

#define UE_GL_WIN_32_PLATFORM_CTX 
#define UE_GL_LINUX_PLATFORM_CTX
#define APPLE_PLATFORM_CTX
#define UNIX_PLATFORM_CTX CONTEXT_GL_UNIX

#endif // __unix__
#define GL_CONTEXT_PLATFORM UE_GL_WIN_32_PLATFORM_CTX  UE_GL_LINUX_PLATFORM_CTX  APPLE_PLATFORM_CTX  UNIX_PLATFORM_CTX
import std;
import REF_WRAPPER;

namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        typedef void* HGLRC_VoidPtr;
        typedef void* HDC_VoidPtr;
        typedef void* HMODULE_VoidPtr;
        class OPENGL_CONTEXT : public RENDER_COMMON::CONTEXT_BASE {
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
            ~OPENGL_CONTEXT() {}

            // Inherited via CONTEXT_BASE
            OwnedRef<CONTEXT_BASE> _internal_create_context(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window) override;
            UPRISE_OPENGL_RENDER_API void _internal_destroy_context() override;
            UPRISE_OPENGL_RENDER_API void PostFrameWork() const;
            UPRISE_OPENGL_RENDER_API void PreFrameWork();
        };
    }


}

#endif // !_OPENGL_CONTEXT_
