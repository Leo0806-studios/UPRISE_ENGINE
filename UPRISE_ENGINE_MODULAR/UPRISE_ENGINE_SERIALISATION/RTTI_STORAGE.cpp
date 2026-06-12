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
}

