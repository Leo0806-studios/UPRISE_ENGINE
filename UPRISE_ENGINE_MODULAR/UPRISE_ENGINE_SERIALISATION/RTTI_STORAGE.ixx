module;
#include <MACROS.h>
export module UE_SERIALISATION:RTTI_STORAGE;
import std;
import :SERIALIZED_TYPE_INFO;
namespace UPRISE_ENGINE::SERIALISATION {
    namespace {
        template<typename T>
        consteval TypeCategory GetTypeCategory() {
            if constexpr (std::is_integral_v<T>) {
                return TypeCategory::InbuildIntegral;
            }
            else if constexpr (std::is_floating_point_v<T>) {
                return TypeCategory::InbuildFloatingPoint;
            }
            else if constexpr (std::is_void_v<T>) {
                return TypeCategory::InbuildVoid;
            }
            else if constexpr (std::is_same_v<T, bool>) {
                return TypeCategory::InbuildBool;
            }
            else if constexpr (std::is_same_v<T, char>||std::is_same_v<T,wchar_t>) {
                return TypeCategory::InbuildChar;
            }
            else if constexpr (std::is_null_pointer_v<T>) {
                return TypeCategory::InbuildNullptr;
            }
            else if constexpr (std::is_class_v<T>) {
                return TypeCategory::UserDefinedClass;
            }
            else {
                static_assert(false, "Unsupported type");
                return TypeCategory{}; // Unreachable, but required to satisfy the compiler
            }
        }
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
        inline static  std::unordered_map<std::string, std::shared_ptr<SerializedTypeInfo>>& RegisteredTypes() {
            static std::unordered_map<std::string, std::shared_ptr<SerializedTypeInfo>> registeredTypes;
            return registeredTypes;
      }
        inline static std::unordered_map<std::string, std::string>& RawTypeNameToRegisteredTypeNameMap() {
            static std::unordered_map<std::string, std::string> rawTypeNameToRegisteredTypeNameMap;
            return rawTypeNameToRegisteredTypeNameMap;
        }
    public:
        UPRISE_SERIALISATION_API static bool RegisterType(const SerializedTypeInfo& typeInfo, std::string name, std::string rawName);
        UPRISE_SERIALISATION_API static std::weak_ptr<SerializedTypeInfo> TryGetTypeInfo(const std::string& name);
    };
    template <typename T, typename MemberPtr>
        requires  std::is_member_object_pointer_v<MemberPtr>
    MemberInfo CreateMemberInfo(const std::string& name, MemberPtr memberPtr, AccesebilityModifiers accessModifier) {
        MemberInfo memberInfo;
        memberInfo.name = name;
        memberInfo.offset = reinterpret_cast<size_t>(&(reinterpret_cast<T*>(0)->*memberPtr));
        using MemberType = typename std::remove_cv_t<std::remove_reference_t<decltype(std::declval<T>().*memberPtr)>>;
        memberInfo.typeInfo = RTTIStorage::TryGetTypeInfo(typeid(MemberType).name());
        memberInfo.AccessModifier = accessModifier;

        return memberInfo;
    }
    template <typename T>
        
    class TypeRegistrar {
    public:
        template <typename... MemberInfos>
        requires (std::is_same_v<MemberInfos,MemberInfo>&&...)
        TypeRegistrar(MemberInfos... infos ) {
                SerializedTypeInfo typeInfo;
                typeInfo.Name = typeid(T).name();
                typeInfo.Class = GetTypeClass<T>();
                std::vector<MemberInfo> tmpVector{ infos... };
                for (const MemberInfo& member : tmpVector) {
                    const auto&[it,succsess]=typeInfo.Members.try_emplace(member.name, member);
                    if (!succsess) {
                        throw std::runtime_error("Duplicate member name: " + member.name);
                    }
                }
                typeInfo.Alligment = alignof(T);
                typeInfo.Size= sizeof(T);
                typeInfo.Category = GetTypeCategory<T>();
                RTTIStorage::RegisterType(typeInfo, typeid(T).name(), typeid(T).raw_name());
        }
    };
}
export namespace std {


    UPRISE_SERIALISATION_API std::string to_string(const UPRISE_ENGINE::SERIALISATION::TypeClass& typeClass) {
        switch (typeClass) {
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Primitive:
                return "Primitive";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Class:
                return "Class";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Struct:
                return "Struct";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Enum:
                return "Enum";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Array:
                return "Array";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Pointer:
                return "Pointer";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Reference:
                return "Reference";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Function:
                return "Function";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Lambda:
                return "Lambda";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Template:
                return "Template";
            case UPRISE_ENGINE::SERIALISATION::TypeClass::Undefined:
                UE_FALLTROUGH;
            default:
                return "Undefined";
        }
    }
   UPRISE_SERIALISATION_API std::string to_string(const UPRISE_ENGINE::SERIALISATION::TypeCategory& typeCategory) {
        switch (typeCategory) {
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildIntegral:
                return "InbuildIntegral";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildFloatingPoint:
                return "InbuildFloatingPoint";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildVoid:
                return "InbuildVoid";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildBool:
                return "InbuildBool";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildChar:
                return "InbuildChar";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildNullptr:
                return "InbuildNullptr";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::UserDefinedClass:
                return "UserDefinedClass";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::Undefined:

            default:
                return "Undefined";
        }
    }
}