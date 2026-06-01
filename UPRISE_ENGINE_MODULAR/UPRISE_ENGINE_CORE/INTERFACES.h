#pragma once
namespace UPRISE_ENGINE::INTERFACES {
    template<typename T>
    class IEnumerable {
    public:
        T::iterator begin() const noexcept {
            return static_cast<const T*>(this)->begin();
        }
        T::iterator end() const noexcept {
            return static_cast<const T*>(this)->end();
        }
        T::reverse_iterator rbegin() const noexcept {
            return static_cast<const T*>(this)->rbegin();
        }
        T::reverse_iterator rend() const noexcept {
            return static_cast<const T*>(this)->rend();
        }
    };
}