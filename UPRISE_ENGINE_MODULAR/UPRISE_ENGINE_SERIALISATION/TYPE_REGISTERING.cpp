import UE_SERIALISATION;
import std;
#pragma warning(push)
#pragma warning(disable:4868)
namespace UPRISE_ENGINE::SERIALISATION {
    TypeRegistrar<MemberInfo> memberInfoRegistrar{
        {

        CreateMemberInfo<MemberInfo>(std::string("name"), &MemberInfo::name, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("offset", &MemberInfo::offset, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("typeInfo", &MemberInfo::typeInfo, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("AccessModifier", &MemberInfo::AccessModifier, AccesebilityModifiers::Public),
}
    };
    TypeRegistrar<AccesebilityModifiers> accessModifierRegistrar;
    TypeRegistrar<TypeClass> typeClassRegistrar;
    TypeRegistrar<TypeCategory> typeCategoryRegistrar;
    TypeRegistrar<SerializedTypeInfo> serializedTypeInfoRegistrar{
        {
            CreateMemberInfo<SerializedTypeInfo>("typeName", &SerializedTypeInfo::Name, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("typeCategory", &SerializedTypeInfo::Category, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("typeClass", &SerializedTypeInfo::Class, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("size", &SerializedTypeInfo::Size, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("alignment", &SerializedTypeInfo::Alligment, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("members", &SerializedTypeInfo::Members, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("functions", &SerializedTypeInfo::FunctionMembers, AccesebilityModifiers::Public),
            CreateMemberInfo<SerializedTypeInfo>("constructors", &SerializedTypeInfo::Constructors, AccesebilityModifiers::Public)
        }
    };




}
#pragma warning(pop)