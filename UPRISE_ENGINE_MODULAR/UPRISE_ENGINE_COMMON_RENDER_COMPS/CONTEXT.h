#pragma once

#include <memory>
#include <unordered_map>
#include <MACROS.h>
#include "RENDER_BACKEND.h"
namespace UPRISE_ENGINE ::RENDER{


    namespace RENDER_COMMON {
        class Window;
        class Buffer;
        class RenderContext {
        public:
            using CreatorFunk = std::unique_ptr<RenderContext>(*)(std::weak_ptr<Window>);
        private:
            UPRISE_COMMON_RENDER_COMPS_API static std::array<CreatorFunk, 4> RegisteredWindowTypes;//initializes to arr of nullptr
        public:
            UPRISE_COMMON_RENDER_COMPS_API static void RegisterContextClass(RENDER_COMMON::Backend backend, CreatorFunk creator);
            UPRISE_COMMON_RENDER_COMPS_API virtual void AttachToWindow(std::weak_ptr<Window> window)=0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void DetachFromWindow() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual std::weak_ptr<Window> GetAttachedWindow() const = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void BindBuffer(std::weak_ptr<Buffer> buffer) = 0;


            UPRISE_COMMON_RENDER_COMPS_API virtual void MakeCurrent() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual ~RenderContext();
            static std::unique_ptr<RenderContext> CreateContext(std::weak_ptr<Window> window);


        };


    template <typename T>
    concept hasContextCreateFunc = requires (std::weak_ptr<Window> window) {
        {
            T::CreateContext(window)
        } -> std::same_as<std::unique_ptr<RenderContext>>;
    };
    template <typename T>
    concept isContextClass = std::derived_from<T, RenderContext>;

    template <typename T, RENDER_COMMON::Backend backend>
        requires isContextClass<T>&& hasContextCreateFunc<T>

    struct ContextClassRegistry {
    public:
        ContextClassRegistry() {
            Window::RegisterWindowClass(backend, [](std::weak_ptr<Window> window) -> std::unique_ptr<RenderContext> {
                return T::CreateContext(window);
            });
        }
    };

    }
}


