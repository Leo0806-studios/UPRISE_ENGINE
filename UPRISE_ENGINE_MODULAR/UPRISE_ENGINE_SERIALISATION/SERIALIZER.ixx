export module UE_SERIALISATION:SERIALIZER;
import std;
import :RTTI_STORAGE;
import:SERIALIZED_TYPE_INFO;
export namespace UPRISE_ENGINE::SERIALISATION {
    template<typename T>
    struct TypeSerializer {
        static std::string Serialize(const T& obj) {}
        static T Deserialize(const std::string& str) {}
    };
}