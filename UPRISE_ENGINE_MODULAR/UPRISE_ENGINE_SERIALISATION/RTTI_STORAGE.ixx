module;
#include <MACROS.h>
export module UE_SERIALISATION:RTTI_STORAGE;
import std;
import :SERIALIZED_TYPE_INFO;
namespace UPRISE_ENGINE::SERIALISATION {
    namespace {
        template <typename T>
        consteval  TypeClass GetTypeClass() {
            if constexpr (std::is_integral_v<T>) {
                return TypeClass::Primitive;
            }
            else if constexpr (std::is_floating_point_v<T>) {
                return TypeClass::Primitive;
            }
            else if constexpr (std::is_void_v<T>) {
                return TypeClass::Primitive;
            }
            else if constexpr (std::is_same_v<T, bool>) {
                return TypeClass::Primitive;
            }
            else if constexpr (std::is_same_v<T, char>) {
                return TypeClass::Primitive;
            }
            else if constexpr (std::is_null_pointer_v<T>) {
                return TypeClass::Primitive;
            }
            else if constexpr (std::is_class_v<T>) {
                return TypeClass::Class;
            }
            else if constexpr (std::is_enum_v<T>) {
                return TypeClass::Enum;
            }
            else if constexpr (std::is_array_v<T>) {
                return TypeClass::Array;
            }
            else if constexpr (std::is_pointer_v<T>) {
                return TypeClass::Pointer;
            }
            else if constexpr (std::is_reference_v<T>) {
                return TypeClass::Reference;
            }
            else if constexpr (std::is_function_v<T>) {
                return TypeClass::Function;
            }
            else if constexpr (std::is_lvalue_reference_v<T> || std::is_rvalue_reference_v<T>) {
                return TypeClass::Reference;
            }
            else if constexpr (std::is_member_function_pointer_v<T> || std::is_member_object_pointer_v<T>) {
                return TypeClass::Pointer; // Treat member pointers as regular pointers for simplicity
            }
            else {
                static_assert(false, "Unsupported type");
                return TypeClass{}; // Unreachable, but required to satisfy the compiler
            }
        }
    }

}
export  namespace UPRISE_ENGINE::SERIALISATION {


    class RTTIStorage {
      inline static  std::unordered_map<std::string, std::shared_ptr<SerializedTypeInfo>> RegisteredTypes;
        inline static std::unordered_map<std::string, std::string> RawTypeNameToRegisteredTypeNameMap;
    public:
        UPRISE_SERIALISATION_API static bool RegisterType(const SerializedTypeInfo& typeInfo, std::string name, std::string rawName);
        UPRISE_SERIALISATION_API static std::weak_ptr<SerializedTypeInfo> TryGetTypeInfo(const std::string& name);
    };
    template <typename T, typename MemberPtr>
        requires std::is_class_v<T>&& std::is_member_object_pointer_v<MemberPtr>
    MemberInfo CreateMemberInfo(const std::string& name, MemberPtr memberPtr, AccesebilityModifiers accessModifier) {
        MemberInfo memberInfo;
        memberInfo.name = name;
        memberInfo.offset = reinterpret_cast<size_t>(&(reinterpret_cast<T*>(0)->*memberPtr));
        using MemberType = typename std::remove_cv_t<std::remove_reference_t<decltype(std::declval<T>().*memberPtr)>>;
        memberInfo.typeInfo = RTTIStorage::RegisteredTypes[typeid(MemberType).name()];
        memberInfo.AccessModifier = accessModifier;
        return memberInfo;
    }
    template <typename T>
        requires std::is_class_v<T>
    class TypeRegistrar {
    public:
        TypeRegistrar() {
            SerializedTypeInfo typeInfo;
            typeInfo.Name = typeid(T).name();
            typeInfo.Class = GetTypeClass<T>();
            RTTIStorage::RegisterType(typeInfo, typeid(T).name(), typeid(T).raw_name());
        }
    };
}