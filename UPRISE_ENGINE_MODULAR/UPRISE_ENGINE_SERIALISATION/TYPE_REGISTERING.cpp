import UE_SERIALISATION;
import std;
#pragma warning(push)
#pragma warning(disable:4868)
namespace UPRISE_ENGINE::SERIALISATION {
    TypeRegistrar<MemberInfo> members{
        CreateMemberInfo<MemberInfo>(std::string("name"), &MemberInfo::name, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("offset", &MemberInfo::offset, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("typeInfo", &MemberInfo::typeInfo, AccesebilityModifiers::Public),
        CreateMemberInfo<MemberInfo>("AccessModifier", &MemberInfo::AccessModifier, AccesebilityModifiers::Public)
    };
}
#pragma warning(pop)