import UE_SERIALISATION;
namespace UPRISE_ENGINE::SERIALISATION {
    bool RTTIStorage::RegisterType(const SerializedTypeInfo& typeInfo, std::string name, std::string rawName) {
        const auto [it, succsess] = RegisteredTypes().try_emplace(name, std::make_shared<SerializedTypeInfo>(typeInfo));
        const auto [it2, succsess2] = RawTypeNameToRegisteredTypeNameMap().try_emplace(rawName, name);
        if (!succsess) {
            (*RegisteredTypes()[name]) = typeInfo;
        }
        return true;
    }
    std::weak_ptr<SerializedTypeInfo> RTTIStorage::TryGetTypeInfo(const std::string& name)
    {
        const auto it = RegisteredTypes().find(name);
        const auto& lst = RegisteredTypes();
        if (it == lst.end())
        {
            return RegisteredTypes()[name] = std::make_shared<SerializedTypeInfo>();
        }
        return it->second;

    }
     void RTTIStorage::PrintAll()
    {
         for (auto& [name, typeInfo] : RTTIStorage::RegisteredTypes()) {
             std::cout << "Type Name: " << typeInfo->Name << std::endl;
             std::cout << "Type Class: " << std::to_string(typeInfo->Class) << std::endl;
             std::cout << "Type Category: " << std::to_string(typeInfo->Category) << std::endl;
             std::cout << "Alignment: " << typeInfo->Alligment << std::endl;
             std::cout << "Size: " << typeInfo->Size << std::endl;
             for (const auto& [memberName, memberInfo] : typeInfo->Members) {
                 std::cout << "\tMember Name: " << memberName << ", Offset: " << memberInfo.offset
                     << ", Access Modifier: " << static_cast<int>(memberInfo.AccessModifier) << std::endl;
                 auto memberTypeInfo = memberInfo.typeInfo.lock();
                 if (memberTypeInfo) {
                     std::cout << "\t\tMember Type Name: " << memberTypeInfo->Name << std::endl;
                     std::cout << "\t\tMember Type Class: " << std::to_string(memberTypeInfo->Class) << std::endl;
                     std::cout << "\t\tMember Type Category: " << std::to_string(memberTypeInfo->Category) << std::endl;
                     std::cout << "\t\tMember Type Alignment: " << memberTypeInfo->Alligment << std::endl;
                     std::cout << "\t\tMember Type Size: " << memberTypeInfo->Size << std::endl;
                 }
                 else {
                     std::cout << "\t\tMember Type Info not found" << std::endl;
                 }
             }
         }
        
    }
}

