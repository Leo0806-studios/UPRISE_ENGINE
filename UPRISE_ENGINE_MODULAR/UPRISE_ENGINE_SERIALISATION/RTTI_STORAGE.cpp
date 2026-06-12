import UE_SERIALISATION;
namespace UPRISE_ENGINE::SERIALISATION {
    bool RTTIStorage::RegisterType(const SerializedTypeInfo& typeInfo,std::string name, std::string rawName) {
        // Implementation of type registration logic goes here
        // This could involve storing the type information in a map or database for later retrieval
        return true; // Return true if registration is successful, false otherwise
    }
     std::weak_ptr<SerializedTypeInfo> RTTIStorage::TryGetTypeInfo(const std::string& name)
    {

    }
}

