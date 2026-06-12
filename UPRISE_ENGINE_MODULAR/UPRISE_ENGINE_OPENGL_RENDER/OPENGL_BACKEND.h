#pragma once
#include <memory>
#include <vector>
#include <MACROS.h>
#include <RENDER_BACKEND.h>
namespace UPRISE_ENGINE {
    namespace RENDER {
        namespace OPENGL_RENDER {
            class OpenGlContext;
            

            class OpenGlBackend : public RENDER_COMMON::RenderBackend {
            private:
                friend class UPRISE_ENGINE::RENDER::Render;

                    UPRISE_OPENGL_RENDER_API  static  std::shared_ptr<RENDER_COMMON::RenderBackend>GL_Create_Backend();

                // Inherited via RenderBackend
                void _internal_setup() override;
                void _internal_DestroyBackend() override;
                void _internal_PreFrameWork() override;
                void _internal_PostFrameWork() override;
            public:
            public:
                OpenGlBackend()noexcept = default;
                ~OpenGlBackend()override = default;
                OpenGlBackend(const OpenGlBackend& other) = delete;
                OpenGlBackend(OpenGlBackend&& other)noexcept :RenderBackend(std::move(other)) {

                }
                OpenGlBackend& operator=(const OpenGlBackend& other) = delete;
                OpenGlBackend& operator=(OpenGlBackend&& other)noexcept(std::is_nothrow_move_assignable_v< RENDER_COMMON::RenderBackend>) {
                    RENDER_COMMON::RenderBackend::operator=(std::move(other));
                    return *this;
                }

            };
            
        }
    }
}


