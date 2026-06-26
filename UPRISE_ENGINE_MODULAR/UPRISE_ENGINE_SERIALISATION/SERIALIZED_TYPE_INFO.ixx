module;
#include <cstdint>
#include <MACROS.h>
#include <memory>
#include <string>
#include <unordered_map>
export module UE_SERIALISATION:SERIALIZED_TYPE_INFO;
import :TYPE_TRAITS;
import std;
import :REFLECTION_EXCEPTIONS;


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


    enum class TypeInfoState {
        Default,
        Registered,
        Placeholder,
        Generated
    };
    class MemberInfo;
    class ConstructorInfo;
    class FunctionMemberInfo;
    class DestructorInfo;
    class SerializedTypeInfo;
    class RawType {
        SerializedTypeInfo* typeInfo;
        unsigned char* rawPtr;
    public:
        RawType() : typeInfo(nullptr), rawPtr(nullptr) {}
        RawType(void* rawPtr_, SerializedTypeInfo* typeInfo) : typeInfo(typeInfo), rawPtr(static_cast<unsigned char*>(rawPtr)) {}
        ~RawType() {
            operator delete[](rawPtr, std::align_val_t(typeInfo->Alignment()));
        }
        void* data() const noexcept {
            return rawPtr;
        }
        SerializedTypeInfo* type() const noexcept {
            return typeInfo;
        }

        explicit(false) operator bool()const noexcept {
            return rawPtr != nullptr && typeInfo != nullptr;
        }
    };
    class SerializedTypeInfo {
        friend class RTTIStrorage;
        template <typename T>
        friend class TypeRegistrar;
        std::string name = "Unknown";
        TypeClass class_ = TypeClass::Undefined;
        TypeCategory category = TypeCategory::Undefined;
        size_t alligment = 0;
        size_t size = 0;
        bool isMoveConstructible = false;
        bool isCopyConstructible = false;
        bool isDefaultConstructible = false;
        bool isTriviallyCopyable = false;
        bool isCopyAssignable = false;
        bool isMoveAssignable = false;
        std::unordered_map<std::string, std::unique_ptr<MemberInfo>> members;
        std::unordered_map<std::string, std::unique_ptr<FunctionMemberInfo>> functionMembers;
        std::unordered_map<std::string, std::unique_ptr<ConstructorInfo>> constructors;
        std::unique_ptr<DestructorInfo> destructor;
        TypeInfoState state = TypeInfoState::Placeholder;

    public:
        UPRISE_SERIALISATION_API const std::unordered_map<std::string, std::unique_ptr<MemberInfo>>& Members() const noexcept {
            return members;
        }
        UPRISE_SERIALISATION_API const std::unordered_map<std::string, std::unique_ptr<FunctionMemberInfo>>& FunctionMembers() const noexcept {
            return functionMembers;
        }
        UPRISE_SERIALISATION_API  const std::unordered_map<std::string, std::unique_ptr<ConstructorInfo>>& GetConstructors() const noexcept {
            return constructors;
        }
        UPRISE_SERIALISATION_API const DestructorInfo* GetDestructor() const noexcept {
            if (!destructor) {
                return nullptr;
            }
            return destructor.get();

        }

        UPRISE_SERIALISATION_API const std::string& Name() const noexcept {
            return name;
        }
        UPRISE_SERIALISATION_API TypeCategory Category() const noexcept {
            return category;
        }

        UPRISE_SERIALISATION_API TypeClass Class() const noexcept {
            return class_;
        }
        UPRISE_SERIALISATION_API size_t Alignment() const noexcept {
            return alligment;
        }
        UPRISE_SERIALISATION_API size_t Size() const noexcept {
            return size;
        }
        UPRISE_SERIALISATION_API bool IsMoveConstructible() const noexcept {
            return isMoveConstructible;
        }
        UPRISE_SERIALISATION_API bool IsCopyConstructible() const noexcept {
            return isCopyConstructible;
        }

        UPRISE_SERIALISATION_API bool IsDefaultConstructible() const noexcept {
            return isDefaultConstructible;
        }
        UPRISE_SERIALISATION_API bool IsCopyAssignable() const noexcept {
            return isCopyAssignable;
        }
        UPRISE_SERIALISATION_API bool IsMoveAssignable() const noexcept {
            return isMoveAssignable;
        }
        UPRISE_SERIALISATION_API bool IsTriviallyCopyable() const noexcept {
            return isTriviallyCopyable;
        }
        UPRISE_SERIALISATION_API const ConstructorInfo* GetConstructor(const std::string& key) const {
            if (auto it = constructors.find(key); it != constructors.end()) {
                return it->second.get();
            }
            return nullptr;
        }
        UPRISE_SERIALISATION_API const MemberInfo* GetMember(const std::string& key) const {
            auto it = members.find(key);
            if (it != members.end()) {
                return it->second.get();
            }
            return nullptr;
        }
        UPRISE_SERIALISATION_API const FunctionMemberInfo* GetFunctionMember(const std::string& key) const {
            auto it = functionMembers.find(key);
            if (it != functionMembers.end()) {
                return it->second.get();
            }
            return nullptr;
        }
        UPRISE_SERIALISATION_API  bool operator==(const SerializedTypeInfo& other) const noexcept {
            return this == &other;//Serialized Type info are globally unique and only one of each can exist;
        }
        UPRISE_SERIALISATION_API TypeInfoState State() const noexcept {
            return state;
        }
        UPRISE_SERIALISATION_API bool InsertConstructor(std::unique_ptr<ConstructorInfo> constructorInfo);
        UPRISE_SERIALISATION_API bool InsertMember(std::unique_ptr<MemberInfo> memberInfo);
        UPRISE_SERIALISATION_API bool InsertFunctionMember(std::unique_ptr<FunctionMemberInfo> functionMemberInfo);
        UPRISE_SERIALISATION_API SerializedTypeInfo() = default;
        UPRISE_SERIALISATION_API SerializedTypeInfo& operator=(SerializedTypeInfo&& other) noexcept = default;
        UPRISE_SERIALISATION_API SerializedTypeInfo(SerializedTypeInfo&& other)noexcept = default;
        UPRISE_SERIALISATION_API SerializedTypeInfo(const std::string& name,
                           TypeClass class_,
                           TypeCategory category,
                           size_t alligment,
                           size_t size,
                           bool isMoveConstructible,
                           bool isCopyConstructible,
                           bool isDefaultConstructible,
                           bool isTriviallyCopyable,
                           bool isCopyAssignable,
                           bool isMoveAssignable,
                           std::unordered_map<std::string, std::unique_ptr<MemberInfo>> members = {},
                           std::unordered_map<std::string, std::unique_ptr<FunctionMemberInfo>> functionMembers = {},
                           std::unordered_map<std::string, std::unique_ptr<ConstructorInfo>> constructors = {},
                           std::unique_ptr<DestructorInfo> destructor = {}) noexcept
            : name(name),
            class_(class_),
            category(category),
            alligment(alligment),
            size(size),
            isMoveConstructible(isMoveConstructible),
            isCopyConstructible(isCopyConstructible),
            isDefaultConstructible(isDefaultConstructible),
            isTriviallyCopyable(isTriviallyCopyable),
            isCopyAssignable(isCopyAssignable),
            isMoveAssignable(isMoveAssignable),
            members(std::move(members)),
            functionMembers(std::move(functionMembers)),
            constructors(std::move(constructors)),
            destructor(std::move(destructor)),
        state(TypeInfoState::Registered){}
    private:
        SerializedTypeInfo(const SerializedTypeInfo& other) = delete;
        SerializedTypeInfo& operator=(const SerializedTypeInfo& other) = delete;
    };
    class MemberInfo {
        UPRISE_SERIALISATION_API bool CheckType(std::string type) const;
        UPRISE_SERIALISATION_API bool CheckClassType(std::string type) const;

        std::string name;
        size_t offset;
        const SerializedTypeInfo* typeInfo;
        AccesebilityModifiers accessModifier;
        const SerializedTypeInfo* classType;
    public:
        UPRISE_SERIALISATION_API MemberInfo() = default;
        UPRISE_SERIALISATION_API MemberInfo(const std::string& name, size_t offset, const SerializedTypeInfo* typeInfo, AccesebilityModifiers accessModifier, const SerializedTypeInfo* classType) noexcept
            : name(name), offset(offset), typeInfo(typeInfo), accessModifier(accessModifier), classType(classType) {}
        UPRISE_SERIALISATION_API const std::string& Name() const noexcept {
            return name;
        }
        UPRISE_SERIALISATION_API const SerializedTypeInfo* TypeInfo() const noexcept {
            return typeInfo;
        }
        UPRISE_SERIALISATION_API const SerializedTypeInfo* ClassType() const noexcept {
            return classType;
        }
        UPRISE_SERIALISATION_API size_t Offset() const noexcept {
            return offset;
        }
        UPRISE_SERIALISATION_API AccesebilityModifiers AccessModifier() const noexcept {
            return accessModifier;
        }
        UPRISE_SERIALISATION_API void SetRaw(void* obj, void* value, bool assign) const;
        UPRISE_SERIALISATION_API void GetRaw(void* obj, void* out, bool assign) const;
        UPRISE_SERIALISATION_API void* GetPtrRaw(void* obj) const {
            if (reinterpret_cast<uintptr_t>(obj) % classType->Alignment()) {
                throw AlignmentException("Object buffer is not properly aligned");
            }
            return reinterpret_cast<void*>(reinterpret_cast<uint8_t*>(obj) + offset);
        }
        template <typename U, typename T>
        UPRISE_SERIALISATION_API  T* GetPtr(U* obj) const {
            if (!CheckType(typeid(T).name())) {
                throw MismatchedTypeException("Invalid type");
            }
            if (!CheckClassType(typeid(U).name())) {
                throw MismatchedTypeException("Invalid object type");
            }
            if (reinterpret_cast<uintptr_t>(obj) % classType->Alignment()) {
                throw AlignmentException("Object buffer is not properly aligned");
            }
            return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(obj) + offset);
        }
        template <typename T, typename U>
        UPRISE_SERIALISATION_API  T Get(U* obj) const {
            if (!CheckType(typeid(T).name())) {
                throw MismatchedTypeException("Invalid type");
            }
            if (!CheckClassType(typeid(U).name())) {
                throw MismatchedTypeException("Invalid object type");
            }
            return *reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(obj) + offset);
        }
        template <typename T, typename U>
        UPRISE_SERIALISATION_API void Set(U* obj, T value) const {
            if (!CheckType(typeid(T).name())) {
                throw MismatchedTypeException("Invalid type");
            }
            if (!CheckClassType(typeid(U).name())) {
                throw MismatchedTypeException("Invalid object type");
            }
            *reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(obj) + offset) = value;
        }
    };
    class ConstructorInfo {
        UPRISE_SERIALISATION_API bool CheckTypes(std::vector<std::string> params)const;
        std::string name;
        void (*Invoker)(void* obj, void** params);
        std::vector<const SerializedTypeInfo*> Parameters;
        bool isNoexcept;
        const SerializedTypeInfo* classType;
    public:
        UPRISE_SERIALISATION_API ConstructorInfo() = default;
        UPRISE_SERIALISATION_API ConstructorInfo(const std::string& name,
                        void(*Invoker)(void* obj, void** params),
                        std::vector<const SerializedTypeInfo*> Parameters,
                        bool isNoexcept,
                        const SerializedTypeInfo* classType) noexcept
            : name(name),
            Invoker(Invoker),
            Parameters(std::move(Parameters)),
            isNoexcept(isNoexcept),
            classType(classType) {}
        UPRISE_SERIALISATION_API const std::string& Name() const noexcept {
            return name;
        }
        UPRISE_SERIALISATION_API const SerializedTypeInfo* ClassType() const noexcept {
            return classType;
        }
        UPRISE_SERIALISATION_API bool Noexcept() const noexcept {
            return isNoexcept;
        }
        UPRISE_SERIALISATION_API bool hasInvoker() const noexcept {
            return Invoker != nullptr;
        }
        UPRISE_SERIALISATION_API std::span<const SerializedTypeInfo* const> GetParameters() const noexcept {
            return std::span<const SerializedTypeInfo* const>(Parameters.data(), Parameters.size());
        }
        UPRISE_SERIALISATION_API  void InvokeRaw(void* obj, void** params) const {
            if (reinterpret_cast<uintptr_t>(obj) % classType->Alignment()) {
                throw AlignmentException("Object buffer is not properly aligned");
            }
            for (uint64_t i = 0; i < Parameters.size(); i++) {
                if (reinterpret_cast<uintptr_t>(params[i]) % Parameters[i]->Alignment()) {
                    throw AlignmentException(std::format("Parameter {} buffer is not properly aligned", i));
                }
            }
            Invoker(obj, params);
        }
        template<typename R, typename ...Args>
        UPRISE_SERIALISATION_API  R Invoke(Args... args)const {
            if (!CheckTypes({ typeid(Args).name()... })) {
                throw MismatchedTypeException("Invalid argument types");
            }
            alignas(alignof(R)) std::array<uint8_t, sizeof(R)> obj{};
            if constexpr (sizeof...(Args) == 0) {
                Invoker(obj.data(), nullptr);
            }
            else {
                void* argArray[] = { &args... };
                Invoker(&obj, argArray);

            }

            return *(reinterpret_cast<R*>(obj.data()));
        }
    };
    class DestructorInfo {
        std::string name;
        void (*invoker)(void* obj) = nullptr;
        const SerializedTypeInfo* classType = nullptr;
        bool isNoexcept;
        UPRISE_SERIALISATION_API bool CheckClassType(std::string params)const;
    public:
        UPRISE_SERIALISATION_API DestructorInfo() = default;
        UPRISE_SERIALISATION_API  DestructorInfo(const std::string& name, void(*invoker)(void* obj), bool isNoexcept,const SerializedTypeInfo* classType_) noexcept
            : name(name), invoker(invoker),classType(classType_), isNoexcept(isNoexcept) {}
        UPRISE_SERIALISATION_API const std::string& Name() const noexcept {
            return name;
        }
        UPRISE_SERIALISATION_API const SerializedTypeInfo* ClassType() const noexcept {
            return classType;
        }
        UPRISE_SERIALISATION_API  bool Noexcept() const noexcept {
            return isNoexcept;
        }
        UPRISE_SERIALISATION_API  bool hasInvoker() const noexcept {
            return invoker != nullptr;
        }
        UPRISE_SERIALISATION_API  void InvokeRaw(void* obj) const {
            if (reinterpret_cast<uintptr_t>(obj) % classType->Alignment()) {
                throw AlignmentException("Object buffer is not properly aligned");
            }
            if (!invoker) {
                throw std::runtime_error("Invalid destructor invoker");
            }
            invoker(obj);
        }
        template <typename T>
        UPRISE_SERIALISATION_API  void Invoke(T* obj) const {
            if (!obj) {
                throw std::runtime_error("Object pointer is null");
            }
            if (!invoker) {
                throw std::runtime_error("Invalid destructor invoker");
            }
            if (!CheckClassType(typeid(T).name())) {
                throw MismatchedTypeException("Invalid class type");
            }
            invoker(obj);
        }
    };
    class FunctionMemberInfo {

        UPRISE_SERIALISATION_API bool CheckTypes(std::vector<std::string> params)const;
        UPRISE_SERIALISATION_API bool CheckClassType(std::string params)const;
        std::string name;
        void(*invoker)(void* obj, void**, void* out);
        const SerializedTypeInfo* returnType;
        std::vector< const SerializedTypeInfo*> parameters;
        const SerializedTypeInfo* classType;
        bool const_;
        bool noexcept_;
        UPRISE_ENGINE::SERIALISATION::CallingConvention convention;
    public:
        UPRISE_SERIALISATION_API   FunctionMemberInfo() = default;
        UPRISE_SERIALISATION_API   FunctionMemberInfo(const std::string& name,
                         void(*invoker)(void* obj, void**, void* out),
                         const SerializedTypeInfo* returnType,
                         std::vector<const SerializedTypeInfo*> parameters,
                         const SerializedTypeInfo* classType,
                         bool const_,
                         bool noexcept_,
                         UPRISE_ENGINE::SERIALISATION::CallingConvention convention) noexcept
            : name(name),
            invoker(invoker),
            returnType(returnType),
            parameters(std::move(parameters)),
            classType(classType),
            const_(const_),
            noexcept_(noexcept_),
            convention(convention) {}
        UPRISE_SERIALISATION_API   std::string Name() const noexcept {

            return name;
        }
        UPRISE_SERIALISATION_API  const SerializedTypeInfo* ReturnType() const noexcept {
            return returnType;
        }
        UPRISE_SERIALISATION_API  const std::vector<const SerializedTypeInfo*>& Parameters() const noexcept {
            return parameters;
        }
        UPRISE_SERIALISATION_API   CallingConvention CallingConvention() const noexcept {
            return convention;
        }
        UPRISE_SERIALISATION_API  bool Const() const noexcept {
            return const_;
        }
        UPRISE_SERIALISATION_API  bool Noexcept() const noexcept {
            return noexcept_;
        }
        UPRISE_SERIALISATION_API   const SerializedTypeInfo* ClassType() const noexcept {
            return classType;
        }
        template<typename R, typename T, typename ... Args>
        UPRISE_SERIALISATION_API    R Invoke(T* obj, Args... args) const {
            if (!invoker) {
                throw std::runtime_error("Invalid function invoker");
            }
            if (!obj) {
                throw std::runtime_error("Object pointer is null");
            }
            if (!CheckTypes({ typeid(Args).name()... })) {
                throw MismatchedTypeException("Invalid argument types");
            }
            if (!CheckClassType(typeid(T).name())) {
                throw MismatchedTypeException("Invalid class type");
            }
            alignas(alignof(R)) std::array<uint8_t, sizeof(R)> returnValue{};
            void* argArray[] = { &args... };
            invoker(obj, argArray, &returnValue);
            return *reinterpret_cast<R*>(returnValue.data());
        }
        UPRISE_SERIALISATION_API   void InvokeRaw(void* obj, void** args, void* out) const {
            if (!obj) {
                throw std::runtime_error("Object pointer is null");
            }
            if (!invoker) {
                throw std::runtime_error("Invalid function invoker");
            }
            if (reinterpret_cast<uintptr_t>(out) % returnType->Alignment()) {
                throw AlignmentException("Output buffer is not properly aligned");
            }
            if (reinterpret_cast<uintptr_t>(obj) % classType->Alignment()) {
                throw AlignmentException("Object buffer is not properly aligned");
            }
            for (uint64_t i = 0; i < parameters.size(); i++) {
                if (reinterpret_cast<uintptr_t>(args[i]) % parameters[i]->Alignment()) {
                    throw AlignmentException("Argument buffer is not properly aligned");
                }
            }
            invoker(obj, args, out);
        }
    };

}

export namespace std{
    std::string to_string(UPRISE_ENGINE::SERIALISATION::TypeInfoState state) {
        switch (state) {
            case UPRISE_ENGINE::SERIALISATION::TypeInfoState::Default:
                return "Default";
            case UPRISE_ENGINE::SERIALISATION::TypeInfoState::Registered:
                return "Registered";
            case UPRISE_ENGINE::SERIALISATION::TypeInfoState::Placeholder:
                return "Placeholder";
            case UPRISE_ENGINE::SERIALISATION::TypeInfoState::Generated:
                return "Generated";
            default:
                return "Unknown";
        }
    }
}