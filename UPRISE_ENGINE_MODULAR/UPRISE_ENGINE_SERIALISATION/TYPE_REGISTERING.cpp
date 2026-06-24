import UE_SERIALISATION;
import std;
#pragma warning(push)
#pragma warning(disable:4868)
namespace UPRISE_ENGINE::SERIALISATION {
    TypeRegistrar<MemberInfo> memberInfoRegistrar{
        {


},
        {
            //CreateFunctionMemberInfo<const std::string&, &MemberInfo::Name>("Name"),//TODO: implemment Const refs and overhaul the parameter/return system to accpet r and l value refs
            //CreateFunctionMemberInfo<const SerializedTypeInfo*, &MemberInfo::TypeInfo>("TypeInfo"),
}
    };
    TypeRegistrar<AccesebilityModifiers> accessModifierRegistrar;
    TypeRegistrar<TypeClass> typeClassRegistrar;
    TypeRegistrar<TypeCategory> typeCategoryRegistrar;
    TypeRegistrar<SerializedTypeInfo> serializedTypeInfoRegistrar{
        {

        }
    };




}
#pragma warning(pop)