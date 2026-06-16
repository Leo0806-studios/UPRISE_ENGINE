// RandomBsTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstddef>
import UE_SERIALISATION; 
import std;

struct FOO:public UPRISE_ENGINE::SERIALISATION::IReflectable<FOO> {
    int a;
    float b;
    float* ptr;
    std::string* strPtr;
    std::vector<std::unordered_map<std::string, std::list<std::vector<int>>>>* complexContainerPTR;
    std::string c;
    std::string Bar(const std::string& inStr, int& Inttt, float FFFF, char CCCC) {
        Inttt = 80085;
        return inStr + " MEOW MEOW MEOW";
    }
};
template<typename T>
struct TypeProxy {
    using type = T;
};
UPRISE_ENGINE::SERIALISATION::TypeRegistrar<FOO> fooRegistrar(
    {

    UPRISE_ENGINE::SERIALISATION::CreateMemberInfo<FOO>("a", &FOO::a, UPRISE_ENGINE::SERIALISATION::AccesebilityModifiers::Public),
    UPRISE_ENGINE::SERIALISATION::CreateMemberInfo<FOO>("b", &FOO::b, UPRISE_ENGINE::SERIALISATION::AccesebilityModifiers::Public),
    UPRISE_ENGINE::SERIALISATION::CreateMemberInfo<FOO>("c", &FOO::c, UPRISE_ENGINE::SERIALISATION::AccesebilityModifiers::Public),
    UPRISE_ENGINE::SERIALISATION::CreateMemberInfo<FOO>("ptr", &FOO::ptr, UPRISE_ENGINE::SERIALISATION::AccesebilityModifiers::Public),
    UPRISE_ENGINE::SERIALISATION::CreateMemberInfo<FOO>("strPtr", &FOO::strPtr, UPRISE_ENGINE::SERIALISATION::AccesebilityModifiers::Public),    
    UPRISE_ENGINE::SERIALISATION::CreateMemberInfo<FOO>("complexContainerPTR", &FOO::complexContainerPTR, UPRISE_ENGINE::SERIALISATION::AccesebilityModifiers::Public)
},
{
    UPRISE_ENGINE::SERIALISATION::CreateFunctionMemberInfo<std::string, &FOO::Bar>("Bar"),
    UPRISE_ENGINE::SERIALISATION::CreateFunctionMemberInfo<FOO, &FOO::CopyAssign>("")
 }
);
UPRISE_ENGINE::SERIALISATION::TypeRegistrar<int> intRegistrar;
UPRISE_ENGINE::SERIALISATION::TypeRegistrar<float> floatRegistrar;
UPRISE_ENGINE::SERIALISATION::TypeRegistrar<std::string> stringRegistrar{
    {

},
{

 UPRISE_ENGINE::SERIALISATION::CreateFunctionMemberInfo<const char*, &std::string::c_str>("substr")
 }
};

int main()
{
    auto bar = UPRISE_ENGINE::SERIALISATION::RTTIStorage::TryGetTypeInfo(typeid(FOO).name())->FunctionMembers.at("Bar");
    std::string inStr = "Hello";
    int    ii = 0;
    FOO fooInstance;
    std::string result = bar.Invoke<std::string>(&fooInstance, inStr, ii, 3.14f, 'A');
    std::cout << "Result: " << result << std::endl;
    auto typeInfo = UPRISE_ENGINE::SERIALISATION::RTTIStorage::TryGetTypeInfo(typeid(FOO).name());
    if (typeInfo) {
        std::cout << "Type Name: " << typeInfo->Name << std::endl;
        std::cout << "Type Class: " << std::to_string(typeInfo->Class) << std::endl;
        std::cout << "Type Category: " << std::to_string(typeInfo->Category) << std::endl;
        std::cout << "Alignment: " << typeInfo->Alligment << std::endl;
        std::cout << "Size: " << typeInfo->Size << std::endl;
        for (const auto& [memberName, memberInfo] : typeInfo->Members) {
            std::cout << "Member Name: " << memberName << ", Offset: " << memberInfo.offset
                << ", Access Modifier: " << static_cast<int>(memberInfo.AccessModifier) << std::endl;
            auto memberTypeInfo = memberInfo.typeInfo;
            if (memberTypeInfo) {
                std::cout << "\tMember Type Name: " << memberTypeInfo->Name << std::endl;
                std::cout << "\tMember Type Class: " << std::to_string(memberTypeInfo->Class) << std::endl;
                std::cout << "\tMember Type Category: " << std::to_string(memberTypeInfo->Category) << std::endl;
                std::cout << "\tMember Type Alignment: " << memberTypeInfo->Alligment << std::endl;
                std::cout << "\tMember Type Size: " << memberTypeInfo->Size << std::endl;
            }
            else {
                std::cout << "\tMember Type Info not found" << std::endl;
            }
        }
    }
    else {
        std::cout << "Type info for FOO not found" << std::endl;
    }

    auto typeinfoMember = UPRISE_ENGINE::SERIALISATION::RTTIStorage::TryGetTypeInfo(typeid(UPRISE_ENGINE::SERIALISATION::MemberInfo).name());
    if (typeinfoMember) {
        std::cout << "Type Name: " << typeinfoMember->Name << std::endl;
        std::cout << "Type Class: " << std::to_string(typeinfoMember->Class) << std::endl;
        std::cout << "Type Category: " << std::to_string(typeinfoMember->Category) << std::endl;
        std::cout << "Alignment: " << typeinfoMember->Alligment << std::endl;
        std::cout << "Size: " << typeinfoMember->Size << std::endl;
        for (const auto& [memberName, memberInfo] : typeinfoMember->Members) {
            std::cout << "Member Name: " << memberName << ", Offset: " << memberInfo.offset
                << ", Access Modifier: " << static_cast<int>(memberInfo.AccessModifier) << std::endl;
            auto memberTypeInfo = memberInfo.typeInfo;
            if (memberTypeInfo) {
                std::cout << "\tMember Type Name: " << memberTypeInfo->Name << std::endl;
                std::cout << "\tMember Type Class: " << std::to_string(memberTypeInfo->Class) << std::endl;
                std::cout << "\tMember Type Category: " << std::to_string(memberTypeInfo->Category) << std::endl;
                std::cout << "\tMember Type Alignment: " << memberTypeInfo->Alligment << std::endl;
                std::cout << "\tMember Type Size: " << memberTypeInfo->Size << std::endl;
            }
            else {
                std::cout << "\tMember Type Info not found" << std::endl;
            }
        }

    }
    else {
        std::cout << "Type info for MemberInfo not found" << std::endl;
    }
    UPRISE_ENGINE::SERIALISATION::RTTIStorage::PrintAll();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
