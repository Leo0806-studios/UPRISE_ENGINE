export module UE_SERIALISATION:SERIALIZED_PTR;
import :SERIALIZED_TYPE_INFO;
import :RTTI_STORAGE;
import :SERIALIZER;
import std;

//
// There are two (three) kinds of serialized pointers:
// one simply called SerializedPtr<T> wich serializes the first time it gets encountered and all other pinters to the same object store an reference id. this version functions like a normal pointer
// and SerializedPtrStrong<T> and SerializedPtrWeak<T> where only The string version serializes the poiter and the other one only stores the reference id. this version implicitly also act like smart pointers
// 
// 
// 
// 
// 
//



export namespace UPRISE_ENGINE::SERIALISATION {
    class PointerBase;
    template<typename T>
    class SerializedPtr;
    class ControllBase {
    public:
        virtual std::string Serialize() = 0;
        virtual ~ControllBase() = default;
    };
    template<typename T>
    class ControllBlock : public ControllBase {
    public:
        std::string Serialize() override {
        }
    };
    class ImplicitControllBase {
    public:
    };
    template <typename T>
    class ImplicitControllBlock : public ImplicitControllBase {



    };
    class PointerBase {};
    template<typename T>
    class SerializedPtr :public PointerBase {

    };
    template<typename T>
    class SerializedPtrStrong : public PointerBase {};

    template <typename T>
    class SerializedPtrWeak : public PointerBase {

    };
}