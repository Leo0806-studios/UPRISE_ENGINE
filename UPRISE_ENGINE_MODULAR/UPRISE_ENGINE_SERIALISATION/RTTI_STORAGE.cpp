import UE_SERIALISATION;
namespace UPRISE_ENGINE::SERIALISATION {
    bool RTTIStorage::RegisterType( SerializedTypeInfo typeInfo, std::string name, std::string rawName) {
        auto& registeredTypes = RegisteredTypes();  
        
        auto itt = registeredTypes.find(name);
        if (itt == registeredTypes.end()) {
            auto* obj = new SerializedTypeInfo(std::move(typeInfo));
            registeredTypes.emplace(name, std::make_unique<SerializedTypeInfo*>(obj));
        }
        else {
            **(*itt).second = std::move(typeInfo);
        }
        auto& rrr = RegisteredTypes();
        (void)rrr;
        RawTypeNameToRegisteredTypeNameMap()[rawName] = name;
        return true;




    }
     const SerializedTypeInfo* RTTIStorage::Get(const std::string& name)
    {
         const auto& lst = RegisteredTypes();
         auto it = lst.find(name);
         if (it != lst.end()) {
             return *(it->second);
         }
         return nullptr;
    }
    const SerializedTypeInfo*  RTTIStorage::internalGetTypeOrPlaceholder(const std::string& name)
    {
        const auto& lst = RegisteredTypes();
        const auto it = lst.find(name);
        if (it == lst.end())
        {
            auto newInfo = new SerializedTypeInfo();
            
            return*(RegisteredTypes()[name] = std::make_unique<SerializedTypeInfo*>(newInfo));
        }
        return *it->second;

    }
    void RTTIStorage::PrintAll()
    {
        for (auto& [name, typeInfo] : RTTIStorage::RegisteredTypes()) {
            std::cout << "Type Name: " << (*typeInfo)->Name() << std::endl;
            std::cout << "Type Class: " << std::to_string((*typeInfo)->Class()) << std::endl;
            std::cout << "Type Category: " << std::to_string((*typeInfo)->Category()) << std::endl;
            std::cout << "Alignment: " << (*typeInfo)->Alignment() << std::endl;
            std::cout << "Size: " << (*typeInfo)->Size() << std::endl;
            for (const auto& [memberName, memberInfo] : (*typeInfo)->Members()) {
                std::cout << "\tMember Name: " << memberName << ", Offset: " << memberInfo->Name()
                    << ", Access Modifier: " << static_cast<int>(memberInfo->AccessModifier()) << std::endl;
                auto memberTypeInfo = memberInfo->TypeInfo();
                if (memberTypeInfo) {
                    std::cout << "\t\tMember Type Name: " << memberTypeInfo->Name() << std::endl;
                    std::cout << "\t\tMember Type Class: " << std::to_string(memberTypeInfo->Class()) << std::endl;
                    std::cout << "\t\tMember Type Category: " << std::to_string(memberTypeInfo->Category()) << std::endl;
                    std::cout << "\t\tMember Type Alignment: " << memberTypeInfo->Alignment() << std::endl;
                    std::cout << "\t\tMember Type Size: " << memberTypeInfo->Size() << std::endl;
                }
                else {
                    std::cout << "\t\tMember Type Info not found" << std::endl;
                }
            }
            for (const auto& [functionMemberName, functionMemberInfo] : (*typeInfo)->FunctionMembers()) {
                std::cout << "\tFunction Member Name: " << functionMemberName << ", Const: " << functionMemberInfo->Const()
                    << ", Noexcept: " << functionMemberInfo->Noexcept()
                    << ", Calling Convention: " << std::to_string(functionMemberInfo->CallingConvention()) << std::endl;
                auto returnTypeInfo = functionMemberInfo->ReturnType()  ;
                if (returnTypeInfo) {
                    std::cout << "\t\tReturn Type Name: " << returnTypeInfo->Name() << std::endl;
                    std::cout << "\t\tReturn Type Class: " << std::to_string(returnTypeInfo->Class()) << std::endl;
                    std::cout << "\t\tReturn Type Category: " << std::to_string(returnTypeInfo->Category()) << std::endl;
                    std::cout << "\t\tReturn Type Alignment: " << returnTypeInfo->Alignment() << std::endl;
                    std::cout << "\t\tReturn Type Size: " << returnTypeInfo->Size() << std::endl;
                }
                else {
                    std::cout << "\t\tReturn Type Info not found" << std::endl;
                }
                for (const auto& paramTypeWeakPtr : functionMemberInfo->Parameters()) {
                    auto paramTypeInfo = paramTypeWeakPtr;
                    if (paramTypeInfo) {
                        std::cout << "\t\tParameter Type Name: " << paramTypeInfo->Name() << std::endl;
                        std::cout << "\t\tParameter Type Class: " << std::to_string(paramTypeInfo->Class()) << std::endl;
                        std::cout << "\t\tParameter Type Category: " << std::to_string(paramTypeInfo->Category()) << std::endl;
                        std::cout << "\t\tParameter Type Alignment: " << paramTypeInfo->Alignment() << std::endl;
                        std::cout << "\t\tParameter Type Size: " << paramTypeInfo->Size() << std::endl;
                    }
                    else {
                        std::cout << "\t\tParameter Type Info not found" << std::endl;
                    }
                }
            }
            for (const auto& [constructorName, constructorInfo] : (*typeInfo)->GetConstructors()) {
                std::cout << "\tConstructor Name: " << constructorName << std::endl;
                for (const auto& paramTypeWeakPtr : constructorInfo->GetParameters()) {
                    auto paramTypeInfo = paramTypeWeakPtr;
                    if (paramTypeInfo) {
                        std::cout << "\t\tParameter Type Name: " << paramTypeInfo->Name() << std::endl;
                        std::cout << "\t\tParameter Type Class: " << std::to_string(paramTypeInfo->Class()) << std::endl;
                        std::cout << "\t\tParameter Type Category: " << std::to_string(paramTypeInfo->Category()) << std::endl;
                        std::cout << "\t\tParameter Type Alignment: " << paramTypeInfo->Alignment() << std::endl;
                        std::cout << "\t\tParameter Type Size: " << paramTypeInfo->Size() << std::endl;
                    }
                    else {
                        std::cout << "\t\tParameter Type Info not found" << std::endl;
                    }
                }
            }
        }

    }
}

