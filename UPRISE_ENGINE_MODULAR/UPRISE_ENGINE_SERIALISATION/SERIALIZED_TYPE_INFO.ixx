module;
#include <MACROS.h>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
export module UE_SERIALISATION:SERIALIZED_TYPE_INFO;
import :TYPE_TRAITS;
import std;


export namespace UPRISE_ENGINE::SERIALISATION {
    enum class TypeClass :uint8_t {
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
        Undefined = 255
    };
    enum class TypeCategory :uint8_t {
        InbuildIntegral,
        InbuildFloatingPoint,
        InbuildVoid,
        InbuildBool,
        InbuildChar,
        InbuildNullptr,
        UserDefinedClass,
        InbuildEnum,
        InbuildPointer,
        InbuildMemberPointer,
        InbuildFunctionMemberPointer,
        InbuildFunctionPointer,
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
        const SerializedTypeInfo* typeInfo;
        AccesebilityModifiers AccessModifier;
    };
    struct ConstructorInfo {
    private:
        UPRISE_SERIALISATION_API bool CheckTypes(std::vector<std::string> params);
        public:
        std::string name;
        void (*Invoker)(void* obj, void** params);
        std::vector<const SerializedTypeInfo*> Parameters;
        bool isNoexcept;
        template<typename R, typename ...Args>
        R Invoke(Args... args) {
            if (!CheckTypes({ typeid(Args).name()... })) {
                throw std::runtime_error("Invalid argument types");
            }
            alignas(alignof(R)) std::array<uint8_t, sizeof(R)> obj{};
            void* argArray[] = { &args... };
            Invoker(&obj, argArray, );
            
            return *std::launder(reinterpret_cast<R*>(obj.data()));
        }
    };
    struct FunctionMemberInfo {
    private:
        UPRISE_SERIALISATION_API bool CheckTypes(std::vector<std::string> params);
    public:
        std::string name;
        void(*Invoker)(void* obj, void**, void* out);
        const SerializedTypeInfo* ReturnType;
        std::vector< const SerializedTypeInfo*> Parameters;
        bool Const;
        bool Noexcept;
        UPRISE_ENGINE::SERIALISATION::CallingConvention Convention;
        template<typename R, typename ... Args>
        R Invoke(void* obj, Args... args) {
            if (!CheckTypes({ typeid(Args).name()... })) {
                throw std::runtime_error("Invalid argument types");
            }
            alignas(alignof(R)) std::array<uint8_t, sizeof(R)> returnValue{};
            void* argArray[] = { &args... };
            Invoker(obj, argArray, &returnValue);
            return *reinterpret_cast<R*>(returnValue.data());
        }
    };
    struct SerializedTypeInfo {
        friend class RTTIStrorage;
        template <typename T>
        friend class TypeRegistrar;
        std::string Name = "Unknown";
        TypeClass Class = TypeClass::Undefined;
        TypeCategory Category = TypeCategory::Undefined;
        size_t Alligment = 0;
        size_t Size = 0;
        std::unordered_map<std::string, MemberInfo> Members;
        std::unordered_map<std::string, FunctionMemberInfo> FunctionMembers;
        bool operator==(const SerializedTypeInfo& other) const noexcept {
            return this == &other;//Serialized Type info are globaly unique and only one of each can exist;
        }
        bool isDefault() const {
            return Name == "Unknown" && Class == TypeClass::Undefined && Category == TypeCategory::Undefined && Alligment == 0 && Size == 0 && Members.empty();
        }
        SerializedTypeInfo() = default;
        SerializedTypeInfo& operator=(SerializedTypeInfo&& other) noexcept{
            if (this != &other) {
                Name = std::move(other.Name);
                Class = other.Class;
                Category = other.Category;
                Alligment = other.Alligment;
                Size = other.Size;
                Members = std::move(other.Members);
                FunctionMembers = std::move(other.FunctionMembers);
            }
            return *this;
        }
        UPRISE_SERIALISATION_API SerializedTypeInfo(SerializedTypeInfo&& other)noexcept : Name(std::move(other.Name)),
            Class(other.Class),
            Category(other.Category),
            Alligment(other.Alligment),
            Size(other.Size),
            Members(std::move(other.Members)),
            FunctionMembers(std::move(other.FunctionMembers))
        {}
    private:
        SerializedTypeInfo(const SerializedTypeInfo& other) = delete;
        SerializedTypeInfo& operator=(const SerializedTypeInfo& other) = delete;
    };
}
