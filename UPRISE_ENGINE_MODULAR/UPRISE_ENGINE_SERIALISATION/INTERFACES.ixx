export module UE_SERIALISATION:INTERFACES;
import :RTTI_STORAGE;

import std;
export namespace UPRISE_ENGINE::SERIALISATION {

    template<typename T> 
    struct IReflectable {

        static T DefaultConstruct() {
            return T();
        }
        static T CopyConstruct(const T& other) {
            return T(other);
        }
        static T MoveConstruct(T&& other) {
            return T(std::move(other));
        }
        T& CopyAssign(const T& other) {
            return *this = other;
        }
        T& MoveAssign(T&& other) {
            return *this = std::move(other);
        }
    };
}