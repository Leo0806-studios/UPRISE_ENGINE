export module UPRISE_ENGINE_CORE:OWNED_REF;
import :WEAK_REF;
import :WRAPPER_BASE;
export namespace UPRISE_ENGINE {
    template <typename Type>
    class OwnedRef {

    public:
        WeakRef<Type, true> GetWeakRef();
    };
}