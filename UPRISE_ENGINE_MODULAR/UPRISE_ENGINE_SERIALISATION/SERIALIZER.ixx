export module UE_SERIALISATION:SERIALIZER;
import std;
import :RTTI_STORAGE;
import:SERIALIZED_TYPE_INFO;
import :JSON;
import :REFLECTION_EXCEPTIONS;
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
namespace {
    UPRISE_ENGINE::SERIALISATION::Json SerializePrimitive(void* obj, const UPRISE_ENGINE::SERIALISATION::SerializedTypeInfo* typeInfo) {
        using namespace UPRISE_ENGINE::SERIALISATION;
        auto category = typeInfo->Category();
        auto type = typeInfo->Class();
        if ((type ==TypeClass::Primitive)&& (category== TypeCategory::InbuildIntegral )) {
            return Json(*reinterpret_cast<int64_t*>(obj));
        }
    }
}
export namespace UPRISE_ENGINE::SERIALISATION {
    struct JsonSerializer {
        template <typename T>
        Json Serialize(const T& obj) {
            const SerializedTypeInfo* typeInfo = RTTIStorage::Get(typeid(T).name());
            if (!typeInfo) {
                throw std::runtime_error("Type not registered");
            }
            auto sserialize = typeInfo->GetFunctionMember("Serialize");
            if (sserialize) {
                return sserialize->Invoke<Json>(&obj);
            }
            auto& members = typeInfo->Members();
            for (const auto& [memberName, memberInfo] : members) {
                if (memberInfo->TypeInfo()->Class() == TypeClass::Primitive) {
                    void* memberPtr = reinterpret_cast<unsigned char*>(const_cast<T*>(&obj)) + memberInfo->Offset();
                    Json memberJson = SerializePrimitive(memberPtr, memberInfo->TypeInfo());
                    // Store or process memberJson as needed
                }
                else {
                    // Handle non-primitive members (e.g., nested objects)
                }
            }

        }
        Json Serialize(const void* obj, const SerializedTypeInfo* typeInfo) {
            if (!typeInfo) {
                throw std::runtime_error("Invalid Type Info");
            }
            if (std::bit_cast<uint64_t>(obj) % typeInfo->Alignment()) {
                throw AlignmentException("Object buffer is not properly aligned");
            }
            // Implement serialization logic based on typeInfo
            return Json(false);
        }
        template <typename T>
        T Deserialize(const Json& json) {
            const SerializedTypeInfo* typeInfo = RTTIStorage::Get(typeid(T).name());
            if (!typeInfo) {
                throw std::runtime_error("Type not registered");

            }
            // Implement deserialization logic based on typeInfo
        }
        void Deserialize(const Json& json, void* objOut, const SerializedTypeInfo* typeInfo) {
            if (!typeInfo) {
                throw std::runtime_error("Invalid Type Info");

            }
            if (std::bit_cast<uint64_t>(objOut) % typeInfo->Alignment()) {
                throw AlignmentException("Output buffer is not properly aligned");
            }
            auto deserialize = typeInfo->GetFunctionMember("Deserialize");
            if (deserialize) {
                void* args[] = { const_cast<Json*>(&json) };
                deserialize->InvokeRaw(objOut, args, nullptr);
                return;
            }
            // Implement deserialization logic based on typeInfo
        }

    };

}