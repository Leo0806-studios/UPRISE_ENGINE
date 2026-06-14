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
        InbuildEnum,
        Undefined = 255

    };
    enum class AccesebilityModifiers {
        Public,
        Protected,
        Private
    };
    enum class CallingConvention {
        StdCall,
        Cdecl,
        FastCall,
        VectorCall,
        ThisCall
    };
    
    struct SerializedTypeInfo;
    struct MemberInfo {
        std::string name;
        size_t offset;
        std::weak_ptr<SerializedTypeInfo> typeInfo;
        AccesebilityModifiers AccessModifier;
    };
    struct FunctionMemberInfo {
        std::string name;
        void(*Invoker)(void* obj, void**, void* out );
        std::weak_ptr<SerializedTypeInfo> ReturnType;
        std::vector< std::weak_ptr<SerializedTypeInfo>> Parameters;
        bool Const;
        bool Noexcept;
        CallingConvention Convention;
    };
    struct SerializedTypeInfo {
        friend class RTTIStrorage;
        template <typename T>
        friend class TypeRegistrar;
        std::string Name="Unknown";
        TypeClass Class=TypeClass::Undefined;
        TypeCategory Category=TypeCategory::Undefined;
        size_t Alligment=0;
        size_t Size=0;
        std::unordered_map<std::string, MemberInfo> Members;
        bool operator==(const SerializedTypeInfo& other) const noexcept {
            return this == &other;//Serialized Type info are globaly unique and only one of each can exist;
        }
        bool isDefault() const {
            return Name == "Unknown" && Class == TypeClass::Undefined && Category == TypeCategory::Undefined && Alligment == 0 && Size == 0 && Members.empty();
        }
    };
}
