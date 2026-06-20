// RandomBsTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstddef>
import UE_SERIALISATION; 
import std;

struct FOO {
    int a;
    float b;
    float* ptr;
    std::string* strPtr;
    std::vector<std::unordered_map<std::string, std::list<std::vector<int>>>>* complexContainerPTR;
    std::string c;
    FOO() : a(0), b(0.0f), ptr(nullptr), strPtr(nullptr), complexContainerPTR(nullptr), c("Hello") {}
    FOO(int a, float b, float* ptr, std::string* strPtr, std::vector<std::unordered_map<std::string, std::list<std::vector<int>>>>* complexContainerPTR, std::string c)
        : a(a), b(b), ptr(ptr), strPtr(strPtr), complexContainerPTR(complexContainerPTR), c(c) {}

    std::string Bar(const std::string& inStr, int& Inttt, float FFFF, char CCCC) {
        Inttt = 80085;
        return inStr + " MEOW MEOW MEOW";
    }
    ~FOO() {
        std::cout << "FOO destructor called for instance with a=" << a << ", b=" << b << ", c=" << c << std::endl;
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
 },
    {
        UPRISE_ENGINE::SERIALISATION::CreateConstructorInfo<FOO>(),
        UPRISE_ENGINE::SERIALISATION::CreateConstructorInfo<FOO, int, float, float*, std::string*, std::vector<std::unordered_map<std::string, std::list<std::vector<int>>>>*, std::string>("Constructor(int, float, float*, std::string*, std::vector<std::unordered_map<std::string, std::list<std::vector<int>>>>*, std::string)"),
        UPRISE_ENGINE::SERIALISATION::CreateConstructorInfo<FOO, const FOO&>("Constructor(const FOO&)"),
        UPRISE_ENGINE::SERIALISATION::CreateConstructorInfo<FOO, FOO&&>("Constructor(FOO&&)"),
    },
    {
        UPRISE_ENGINE::SERIALISATION::CreateDestructorInfo<FOO>()
    }
);
UPRISE_ENGINE::SERIALISATION::TypeRegistrar<int> intRegistrar;
UPRISE_ENGINE::SERIALISATION::TypeRegistrar<float> floatRegistrar;


int main()
{
    auto FooInfo = UPRISE_ENGINE::SERIALISATION::RTTIStorage::TryGetTypeInfo(typeid(FOO).name());
    FOO fooInstance2 = FooInfo->Constructors.at("Constructor").Invoke<FOO>();
    std::cout << "FOO instance created using constructor invoker: a=" << fooInstance2.a << ", b=" << fooInstance2.b << ", c=" << fooInstance2.c << std::endl;
    auto& bar = FooInfo->FunctionMembers.at("Bar");
    std::cout << "value before setting through MemberInfo: " << fooInstance2.a << std::endl;
    auto& Ainfo = FooInfo->Members.at("a");
    Ainfo.Set(&fooInstance2, 42);
    std::cout << "Value of a after setting through MemberInfo: " << fooInstance2.a << std::endl;
    std::cout << " value trough getter: " << Ainfo.Get<int>(&fooInstance2) << std::endl;
    auto& cinfo = FooInfo->Members.at("c");
    cinfo.Set(&fooInstance2, std::string("New Value"));
    std::cout << "Value of c after setting through MemberInfo: " << fooInstance2.c << std::endl;
    std::cout << " value trough getter: " << cinfo.Get<std::string>(&fooInstance2) << std::endl;
    auto Destructor = FooInfo->Destructor;
    Destructor.Invoker(&fooInstance2);
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
        for (const auto& Constructor : typeInfo->Constructors) {

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


