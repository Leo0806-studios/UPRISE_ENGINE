import UE_SERIALISATION;
import std;
#pragma warning(push)
#pragma warning(disable:4868)
namespace UPRISE_ENGINE::SERIALISATION {
    TypeRegistrar<MemberInfo> memberInfoRegistrar{
        CreateMemberInfo<MemberInfo>(std::string("name"), &MemberInfo::name, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("offset", &MemberInfo::offset, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("typeInfo", &MemberInfo::typeInfo, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("AccessModifier", &MemberInfo::AccessModifier, AccesebilityModifiers::Public)
    };
    TypeRegistrar<AccesebilityModifiers> accessModifierRegistrar;
    TypeRegistrar< std::weak_ptr<SerializedTypeInfo>> weakPtrTypeInfoRegistrar;





}
#pragma warning(pop)