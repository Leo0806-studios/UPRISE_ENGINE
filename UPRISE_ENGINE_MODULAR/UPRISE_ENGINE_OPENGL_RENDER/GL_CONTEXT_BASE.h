#pragma once

#include <MACROS.h>

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    template<typename Derived>
    class ContextBase {
    protected:
        ContextBase() = default;
        ~ContextBase() = default;

        Derived* GetDerived() noexcept { return static_cast<Derived*>(this); }
        const Derived* GetDerived() const noexcept { return static_cast<const Derived*>(this); }

    public:

    };
}
