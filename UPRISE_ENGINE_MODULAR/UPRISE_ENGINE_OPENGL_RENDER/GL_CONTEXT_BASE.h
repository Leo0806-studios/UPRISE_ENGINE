#pragma once

#include <MACROS.h>

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    /// CRTP base class for OpenGL platform-specific contexts
    /// Derived classes should inherit as: class ConcreteContext : public ContextBase<ConcreteContext>
    template<typename Derived>
    class ContextBase {
    protected:
        ContextBase() = default;
        ~ContextBase() = default;

        Derived* GetDerived() noexcept { return static_cast<Derived*>(this); }
        const Derived* GetDerived() const noexcept { return static_cast<const Derived*>(this); }

    public:
        // Platform-specific context implementations can expose platform APIs
        // through the derived type. This base provides no-op forwarding helpers
        // for now and exists to mirror the WindowBase CRTP pattern.
    };
}
