#pragma once

#include <memory>
#include <unordered_map>
#include <MACROS.h>
#include "RENDER_BACKEND.h"
namespace UPRISE_ENGINE ::RENDER{


    namespace RENDER_COMMON {
        class Window;
        class Context {
        public:
            using CreatorFunk = std::unique_ptr<Context>(*)(std::weak_ptr<Window>);
        private:
            UPRISE_COMMON_RENDER_COMPS_API static std::unordered_map<Backend, CreatorFunk> RegisteredWindowTypes;





        };


    template <typename T>
    concept hasContextCreateFunc = requires (std::weak_ptr<Window> window) {
        {
            T::CreateContext(window)
        } -> std::same_as<std::unique_ptr<Context>>;
    };
    template <typename T>
    concept isContextClass = std::derived_from<T, Context>;

    template <typename T, RENDER_COMMON::Backend backend>
        requires isContextClass<T>&& hasContextCreateFunc<T>

    struct ContextClassRegistry {
    public:
        ContextClassRegistry() {
            Window::RegisterWindowClass(backend, [](std::weak_ptr<Window> window) -> std::unique_ptr<Context> {
                return T::CreateContext(window);
            });
        }
    };

    }
}


