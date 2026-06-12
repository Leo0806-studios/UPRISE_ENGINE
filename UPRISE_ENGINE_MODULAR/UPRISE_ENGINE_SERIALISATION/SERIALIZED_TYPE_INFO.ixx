module;
#include <MACROS.h>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
export module UE_SERIALISATION:SERIALIZED_TYPE_INFO;
import std;


export namespace UPRISE_ENGINE::SERIALISATION {
    enum class TypeClass:uint8_t {
        Primitive,
        Class,
        Struct,
        Enum,
        Array,
        Pointer,
        Reference,
        Function,
        Lambda,
        Template,
        Undefined=255 
    };
    enum class TypeCategory:uint8_t {
        InbuildIntegral,
        InbuildFloatingPoint,
        InbuildVoid,
        InbuildBool,
        InbuildChar,
        InbuildNullptr,
        UserDefinedClass,
        Undefined = 255

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
        std::string Name="Unknown";
        TypeClass Class=TypeClass::Undefined;
        TypeCategory Category=TypeCategory::Undefined;
        size_t Alligment=0;
        size_t Size=0;
        std::unordered_map<std::string, MemberInfo> Members;
        bool isDefault() const {
            return Name == "Unknown" && Class == TypeClass::Undefined && Category == TypeCategory::Undefined && Alligment == 0 && Size == 0 && Members.empty();
        }
    };
}