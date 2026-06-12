#pragma once
#include <memory>
#include <MACROS.h>
#include <Windows.h>
#include <CONTEXT_BASE.h>

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

            class OpenGlContext final : public RENDER_COMMON::CONTEXT_BASE {
            private:
                std::shared_ptr<GL_CONTEXT_PLATFORM> _platform;
                unsigned long long PixelForatDescriptorHash = 0;
                HGLRC_VoidPtr HGLRC_ptr = nullptr;
                HDC_VoidPtr HDC_ptr = nullptr;
                HMODULE_VoidPtr HMODULE_ptr = nullptr;


            public:
                OpenGlContext(const OpenGlContext& other) = delete;
                OpenGlContext& operator=(const OpenGlContext& other) = delete;
                OpenGlContext(OpenGlContext&& other) :RENDER_COMMON::CONTEXT_BASE(std::move(other)), _platform(std::move(other._platform)) {}
                OpenGlContext& operator=(OpenGlContext&& other) {
                    if (this != &other) {
                        RENDER_COMMON::CONTEXT_BASE::operator=(std::move(other));
                        _platform = std::move(other._platform);
                    }
                    return *this;
                }

                OpenGlContext() noexcept :RENDER_COMMON::CONTEXT_BASE(), _platform{} {};
                ~OpenGlContext();

                // Inherited via CONTEXT_BASE
                std::unique_ptr<CONTEXT_BASE> _internal_create_context(std::weak_ptr<RENDER_COMMON::WINDOW_BASE> Window) override;
                UPRISE_OPENGL_RENDER_API void _internal_destroy_context() override;
                UPRISE_OPENGL_RENDER_API void PostFrameWork() const;
                UPRISE_OPENGL_RENDER_API void PreFrameWork();
            };
        }

    }
}







