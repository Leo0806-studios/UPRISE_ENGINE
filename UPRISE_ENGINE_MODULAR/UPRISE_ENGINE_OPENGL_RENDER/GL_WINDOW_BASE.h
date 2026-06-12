#pragma once
#include <string>

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    // Forward declarations
    typedef void* HWND_VoidPtr;
    typedef void* HINSTANCE_VoidPtr;
    typedef void* HICON_VoidPtr;

    /// CRTP Base class for window management
    /// Derived classes should inherit as: class ConcreteWindow : public WindowBase<ConcreteWindow>
    /// This provides zero-cost abstraction with compile-time polymorphism
    template<typename Derived>
    class WindowBase {
    protected:
        WindowBase() = default;
        ~WindowBase() = default;

        // Helper method to get derived class instance
        Derived* GetDerived() noexcept {
            return static_cast<Derived*>(this);
        }

        const Derived* GetDerived() const noexcept {
            return static_cast<const Derived*>(this);
        }

    public:
        // Window property accessors - interface documentation
        HWND_VoidPtr GetHandle() const noexcept {
            return GetDerived()->GetHandle();
        }

        int GetWidth() const noexcept {
            return GetDerived()->GetWidth();
        }

        int GetHeight() const noexcept {
            return GetDerived()->GetHeight();
        }

        bool IsVisible() const noexcept {
            return GetDerived()->IsVisible();
        }

        bool IsMaximized() const noexcept {
            return GetDerived()->IsMaximized();
        }

        bool IsTransparent() const noexcept {
            return GetDerived()->IsTransparent();
        }

        // Window manipulation methods - interface documentation
        void SetTitle(const std::string& title) {
            GetDerived()->SetTitle(title);
        }

        void SetDimensions(int w, int h) {
            GetDerived()->SetDimensions(w, h);
        }

        void SetPosition(int x, int y) {
            GetDerived()->SetPosition(x, y);
        }

        void SetVisibility(bool visible) {
            GetDerived()->SetVisibility(visible);
        }

        void ToggleVisibility() {
            GetDerived()->ToggleVisibility();
        }

        void SetCursorVisibility(bool visible) {
            GetDerived()->SetCursorVisibility(visible);
        }

        void ToggleCursorVisibility() noexcept {
            GetDerived()->ToggleCursorVisibility();
        }

        void SetTransparency(bool transparent) {
            GetDerived()->SetTransparency(transparent);
        }

        void SetBorderless(bool borderless) {
            GetDerived()->SetBorderless(borderless);
        }

        void Maximize() {
            GetDerived()->Maximize();
        }

        void Minimize() {
            GetDerived()->Minimize();
        }

        void Restore() {
            GetDerived()->Restore();
        }

        void Center() {
            GetDerived()->Center();
        }
    };
}
