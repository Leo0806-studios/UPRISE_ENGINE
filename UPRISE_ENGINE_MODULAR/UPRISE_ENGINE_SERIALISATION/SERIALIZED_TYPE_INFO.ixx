module;
#include <MACROS.h>
export module UE_SERIALISATION:SERIALIZED_TYPE_INFO;
import std;


export namespace UPRISE_ENGINE::SERIALISATION {
    enum class TypeClass {
        Primitive,
        Class,
        Struct,
        Enum,
        Array,
        Pointer,
        Reference,
        Function,
        Lambda,
        Template
    };
    enum class TypeCategory {
        InbuildIntegral,
        InbuildFloatingPoint,
        InbuildVoid,
        InbuildBool,
        InbuildChar,
        InbuildNullptr,
        UserDefinedClass

    };
    enum class AccesebilityModifiers {
        Public,
        Protected,
        Private
    };
    struct SerializedTypeInfo;
    struct MemberInfo {
        std::string name;
        size_t offset;
        std::weak_ptr<SerializedTypeInfo> typeInfo;
        AccesebilityModifiers AccessModifier;
    };
    struct SerializedTypeInfo {
        std::string Name;
        TypeClass Class;
        TypeCategory Category;
        size_t Alligment;
        size_t Size;
        std::unordered_map<std::string, MemberInfo> Members;
    };
}