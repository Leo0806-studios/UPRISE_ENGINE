module;
#include <MACROS.h>
export module UE_SERIALISATION:RTTI_STORAGE;
import std;
import :SERIALIZED_TYPE_INFO;
import :TYPE_TRAITS;
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
            else if constexpr (std::is_same_v<T, char> || std::is_same_v<T, wchar_t>) {
                return TypeCategory::InbuildChar;
            }
            else if constexpr (std::is_null_pointer_v<T>) {
                return TypeCategory::InbuildNullptr;
            }
            else if constexpr (std::is_class_v<T>) {
                return TypeCategory::UserDefinedClass;
            }
            else if constexpr (std::is_enum_v<T>) {
                return TypeCategory::InbuildEnum;
            }
            else if constexpr (std::is_pointer_v<T>) {
                return TypeCategory::InbuildPointer;
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
    template <typename T>
    void DestructorThunk(void* obj) {
        static_cast<T*>(obj)->~T();
    }
    template<typename T, auto method, size_t ... I>
    void ThunkImplConstructor(
        void* obj,
        void** params,
        std::index_sequence<I...>)noexcept(noexcept(T(std::declval<typename function_traits<decltype(method)>::template arg<I>>()...)))
    {
        using Traits = UPRISE_ENGINE::SERIALISATION::function_traits<decltype(method)>;
        using Class = T;
        new (obj) Class((*reinterpret_cast<std::remove_cvref_t<typename Traits::template arg<I>>*>(params[I]))...);
    }
    template<typename T, auto method>
    void ThunkConstructor(
        void* obj,
        void** params)
    {
        using Traits = function_traits<decltype(method)>;
        ThunkImplConstructor<T, method>(
            obj,
            params,
            std::make_index_sequence<Traits::arity>{});
    }

    template<auto Method, size_t... I>
    void ThunkImpl(
        void* obj,
        void** params,
        void* out,
        std::index_sequence<I...>)noexcept(noexcept((std::declval<typename function_traits<decltype(Method)>::class_type>().*Method)(*reinterpret_cast<std::remove_cvref_t<typename function_traits<decltype(Method)>::template arg<I>>*>(params[I])...)))
    {
        using Traits = UPRISE_ENGINE::SERIALISATION::function_traits<decltype(Method)>;

        using Class = typename Traits::class_type;
        using Return = typename Traits::return_type;

        Class* self = static_cast<Class*>(obj);

        if constexpr (std::is_void_v<Return>)
        {
            (self->*Method)(
                (*reinterpret_cast<
                 std::remove_cvref_t<
                 typename Traits::template arg<I>
                 >*
                >(params[I]))...
            );
        }
        else
        {
            if constexpr (std::is_reference_v<Return>) {
                *reinterpret_cast<std::remove_reference_t<Return>*>(out) = std::move((self->*Method)(
                    (*reinterpret_cast<
                     std::remove_cvref_t<
                     typename Traits::template arg<I>
                     >*
                    >(params[I]))...
                    ));
            }
            else
                new (out) Return(
                    (self->*Method)(
                        (*reinterpret_cast<
                         std::remove_cvref_t<
                         typename Traits::template arg<I>
                         >*
                        >(params[I]))...
                        )
                );
        }
    }
    template<auto Method>
    void Thunk(
        void* obj,
        void** params,
        void* out)
    {
        using Traits = function_traits<decltype(Method)>;

        ThunkImpl<Method>(
            obj,
            params,
            out,
            std::make_index_sequence<Traits::arity>{});
    }

}
export  namespace UPRISE_ENGINE::SERIALISATION {

    class RTTIStorage {


        inline static  std::unordered_map<std::string, std::unique_ptr<SerializedTypeInfo*>>& RegisteredTypes() {
            static std::unordered_map<std::string, std::unique_ptr<SerializedTypeInfo*>> registeredTypes;
            return registeredTypes;
        }
        inline static std::unordered_map<std::string, std::string>& RawTypeNameToRegisteredTypeNameMap() {
            static std::unordered_map<std::string, std::string> rawTypeNameToRegisteredTypeNameMap;
            return rawTypeNameToRegisteredTypeNameMap;
        }
    public:

        UPRISE_SERIALISATION_API static const SerializedTypeInfo* internalGetTypeOrPlaceholder(const std::string& name);
        UPRISE_SERIALISATION_API static bool RegisterType(SerializedTypeInfo typeInfo, std::string name, std::string rawName);
        UPRISE_SERIALISATION_API static const SerializedTypeInfo* Get(const std::string& name);
        UPRISE_SERIALISATION_API static void PrintAll();
    };
    struct PrivateAccessRTTI {
        template<typename T, typename MemberPtr>
            requires  std::is_member_object_pointer_v<MemberPtr>
        static MemberInfo CreateMemberInfo(const std::string& name, MemberPtr memberPtr, AccesebilityModifiers accessModifier) {
            MemberInfo memberInfo;
            memberInfo.name = name;
            memberInfo.offset = reinterpret_cast<size_t>(&(reinterpret_cast<T*>(0)->*memberPtr));
            using MemberType = typename std::remove_cv_t<std::remove_reference_t<decltype(std::declval<T>().*memberPtr)>>;
            memberInfo.typeInfo = RTTIStorage::internalGetTypeOrPlaceholder(typeid(MemberType).name());
            if constexpr (std::is_pointer_v<MemberType>) {
                SerializedTypeInfo ptrInfo(
                    typeid(MemberType).name(),
                    GetTypeClass<MemberType>(),
                    GetTypeCategory<MemberType>(),
                    alignof(MemberType),
                    sizeof(MemberType),
                    std::is_move_constructible_v<MemberType>,
                    std::is_copy_constructible_v<MemberType>,
                    std::is_default_constructible_v<MemberType>,
                    std::is_trivially_copyable_v<MemberType>,
                    std::is_copy_assignable_v<MemberType>,
                    std::is_move_assignable_v<MemberType>,
                    nullptr
                );

                RTTIStorage::RegisterType(std::move(ptrInfo), typeid(MemberType).name(), typeid(MemberType).raw_name());
            }

        }
    };
    template <typename T, typename MemberPtr>
        requires  std::is_member_object_pointer_v<MemberPtr>
    MemberInfo CreateMemberInfo(const std::string& name, MemberPtr memberPtr, AccesebilityModifiers accessModifier) {
        using MemberType = typename std::remove_cv_t<std::remove_reference_t<decltype(std::declval<T>().*memberPtr)>>;

        if constexpr (std::is_pointer_v<MemberType>) {
            SerializedTypeInfo ptrInfo(
                typeid(MemberType).name(),
                GetTypeClass<MemberType>(),
                GetTypeCategory<MemberType>(),
                alignof(MemberType),
                sizeof(MemberType),
                std::is_move_constructible_v<MemberType>,
                std::is_copy_constructible_v<MemberType>,
                std::is_default_constructible_v<MemberType>,
                std::is_trivially_copyable_v<MemberType>,
                std::is_copy_assignable_v<MemberType>,
                std::is_move_assignable_v<MemberType>, {}, {}, {}, nullptr
               

            );


            RTTIStorage::RegisterType(std::move(ptrInfo), typeid(MemberType).name(), typeid(MemberType).raw_name());
        }
        return MemberInfo(
            name,
            reinterpret_cast<size_t>(&(reinterpret_cast<T*>(0)->*memberPtr)),
            RTTIStorage::internalGetTypeOrPlaceholder(typeid(MemberType).name()),
            accessModifier,
            RTTIStorage::internalGetTypeOrPlaceholder(typeid(T).name())
        );
    }

    template<typename Fn, size_t... I>
    auto GetFunctionParameterTypesImpl(std::index_sequence<I...>)
    {
        using Traits = function_traits<Fn>;

        return std::vector<const SerializedTypeInfo*>
        {
            RTTIStorage::internalGetTypeOrPlaceholder(
                typeid(
                    typename Traits::template arg<I>
                    ).name()
            )...
        };
    }
    template<typename Fn>
    auto GetFunctionParameterTypes()
    {
        using Traits = function_traits<Fn>;

        return GetFunctionParameterTypesImpl<Fn>(
            std::make_index_sequence<Traits::arity>{}
        );
    }
    template<typename T>
    DestructorInfo CreateDestructorInfo(std::string name = "Destructor") {
        return DestructorInfo(
                name,
                &DestructorThunk<T>,
                std::is_nothrow_destructible_v<T>,
                RTTIStorage::internalGetTypeOrPlaceholder(typeid(T).name())
        );
    }

    template<typename ReturnType, auto MemberPtr>
        requires std::is_member_function_pointer_v<decltype(MemberPtr)>
    FunctionMemberInfo CreateFunctionMemberInfo(
        std::string name
    )
    {
        using Traits = function_traits<decltype(MemberPtr)>;
        return FunctionMemberInfo(
            name,
            &Thunk<MemberPtr>,
            RTTIStorage::internalGetTypeOrPlaceholder(typeid(ReturnType).name()),
            GetFunctionParameterTypes<decltype(MemberPtr)>(),
            RTTIStorage::internalGetTypeOrPlaceholder(typeid(typename Traits::class_type).name()),
            Traits::is_const,
            Traits::is_noexcept,
            Traits::calling_convention

        );

    }
    template <typename T, typename ...Args>
        requires std::is_constructible_v<T, Args...>
    ConstructorInfo CreateConstructorInfo(std::string name = "Constructor") {
        constexpr auto lambda = +[](Args... args) -> T {
            return T(std::forward<Args>(args)...);
            };
        return  ConstructorInfo(
                  name,
                   &ThunkConstructor<T, lambda>,
                  std::vector<const SerializedTypeInfo*>(),
                  std::is_nothrow_constructible_v<T, Args...>,
                  RTTIStorage::internalGetTypeOrPlaceholder(typeid(T).name())
        );

    }
    struct MemberInfoAggregat {
        std::vector<MemberInfo> members;
        template <typename... MemberInfos>
            requires (std::is_same_v<MemberInfos, MemberInfo>&&...)
        MemberInfoAggregat(MemberInfos... infos) : members{ infos... } {}
    };
    struct FunctionMemberInfoAggregat {
        std::vector<FunctionMemberInfo> members;
        template <typename... MemberInfos>
            requires (std::is_same_v<MemberInfos, FunctionMemberInfo>&&...)
        FunctionMemberInfoAggregat(MemberInfos... infos) : members{ infos... } {}
    };
    struct ConstructorInfoAggregat {
        std::vector<ConstructorInfo> members;
        template <typename... MemberInfos>
            requires (std::is_same_v<MemberInfos, ConstructorInfo>&&...)
        ConstructorInfoAggregat(MemberInfos... infos) : members{ infos... } {}
    };
    template <typename T>

    class TypeRegistrar {
    public:



        TypeRegistrar(MemberInfoAggregat memberInfos = {}, FunctionMemberInfoAggregat functionMemberInfos = {}, ConstructorInfoAggregat constructorInfos = {}, DestructorInfo destructorInfo = {}) {

            SerializedTypeInfo typeInfo(
            typeid(T).name(),
            GetTypeClass<T>(),
            GetTypeCategory<T>(),
                []() {if constexpr (std::is_same_v<T, void>) {
                return 0ULL;
            }
                else {
                return alignof(T);
            }}(),
                []() {if constexpr (std::is_same_v<T, void>) {
                return 0ULL;
            }
                else {
                return sizeof(T);
            }}(),
                std::is_move_constructible_v<T>,
                std::is_copy_constructible_v<T>,
                std::is_default_constructible_v<T>,
                std::is_trivially_copyable_v<T>,
                std::is_copy_assignable_v<T>,
                std::is_move_assignable_v<T>,
                [&]()->std::unordered_map<std::string, std::unique_ptr<MemberInfo>> {
                std::unordered_map<std::string, std::unique_ptr<MemberInfo>> members;
                for (const MemberInfo& member : memberInfos.members) {
                    if (!members.emplace(member.Name(), std::make_unique<MemberInfo>(member)).second) {
                        throw std::runtime_error("Duplicate member name: " + member.Name());
                    }
                }
                return members;
                }(),
                    [&]()->std::unordered_map<std::string, std::unique_ptr<FunctionMemberInfo>> {
                    std::unordered_map<std::string, std::unique_ptr<FunctionMemberInfo>> functionMembers;
                    for (const FunctionMemberInfo& functionMember : functionMemberInfos.members) {
                        if (!functionMembers.emplace(functionMember.Name(), std::make_unique<FunctionMemberInfo>(functionMember)).second) {
                            throw std::runtime_error("Duplicate function member name: " + functionMember.Name());
                        }
                    }
                    return functionMembers;
                    }(),
                        [&]()->std::unordered_map<std::string, std::unique_ptr<ConstructorInfo>> {
                        std::unordered_map<std::string, std::unique_ptr<ConstructorInfo>> constructors;
                        for (const ConstructorInfo& constructorInfo : constructorInfos.members) {
                            if (!constructors.emplace(constructorInfo.Name(), std::make_unique<ConstructorInfo>(constructorInfo)).second) {
                                throw std::runtime_error("Duplicate constructor name: " + constructorInfo.Name());
                            }
                        }
                        return constructors;
                        }(),
                            destructorInfo.hasInvoker() ? std::make_unique<DestructorInfo>(destructorInfo) : nullptr
                            );


            RTTIStorage::RegisterType(std::move(typeInfo), typeid(T).name(), typeid(T).raw_name());
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
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildEnum:
                return "InbuildEnum";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildPointer:
                return "InbuildPointer";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildMemberPointer:
                return "InbuildMemberPointer";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildFunctionMemberPointer:
                return "InbuildFunctionMemberPointer";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::InbuildFunctionPointer:
                return "InbuildFunctionPointer";
            case UPRISE_ENGINE::SERIALISATION::TypeCategory::Undefined:

            default:
                return "Undefined";
        }
    }
}