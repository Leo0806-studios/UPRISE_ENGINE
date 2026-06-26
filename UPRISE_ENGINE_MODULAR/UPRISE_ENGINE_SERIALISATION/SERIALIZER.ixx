export module UE_SERIALISATION:SERIALIZER;
import std;
import :RTTI_STORAGE;
import:SERIALIZED_TYPE_INFO;
import :JSON;
//export namespace UPRISE_ENGINE::SERIALISATION {
//    template<typename T,bool UseReflection>
//    struct JsonSerializer {
//        //template<size_t N> __pragma("")  __declspec(allocate("ABC")   ) __declspec(dllexport) __declspec(spectre) __declspec(no_sanitize_address) alignas(alignof(unsigned long long int))  thread_local static inline const constexpr unsigned long long int autoGen = N;
//        static inline constexpr bool Autogen = true;
//        static std::string Serialize(const T& obj) {
//           
//        }
//        static T Deserialize(const std::string& jsonStr) {
//
//        }
//    };
//
//
//    template<typename T>
//    struct JsonSerializer<T, true> {
//
//    };
//}
//


export namespace UPRISE_ENGINE::SERIALISATION {
    struct JsonSerializer {
        template <typename T>
        Json Serialize(const T& obj) {
            const SerializedTypeInfo* typeInfo = RTTIStorage::Get(typeid(T).name());
            if (!typeInfo) {
                throw std::runtime_error("Type not registered for serialization");
            }
            // Implement serialization logic based on typeInfo
        }
        Json Serialize(const void* obj, const SerializedTypeInfo* typeInfo) {
            if (!typeInfo) {
                throw std::runtime_error("Type not registered for serialization");
            }
            // Implement serialization logic based on typeInfo
        }
        template <typename T>
        T Deserialize(const Json& json) {
            const SerializedTypeInfo* typeInfo = RTTIStorage::Get(typeid(T).name());
            if (!typeInfo) {
                throw std::runtime_error("Type not registered for deserialization");
            }
            // Implement deserialization logic based on typeInfo
        }
        void Deserialize(const Json& json, void* objOut, const SerializedTypeInfo* typeInfo) {
            if (!typeInfo) {
                throw std::runtime_error("Type not registered for deserialization");
            }
            // Implement deserialization logic based on typeInfo
        }
    
    };

}