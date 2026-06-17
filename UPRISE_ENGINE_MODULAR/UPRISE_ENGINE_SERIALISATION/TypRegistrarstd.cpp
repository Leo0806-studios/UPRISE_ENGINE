import UE_SERIALISATION;
import std;
using namespace UPRISE_ENGINE::SERIALISATION;

template <typename T>
using Registrar = UPRISE_ENGINE::SERIALISATION::TypeRegistrar<T>;
Registrar<std::string> strRegistrar{
    {

    },
    {
       CreateFunctionMemberInfo<const char*,&std::string::c_str>("c_str"),
       CreateFunctionMemberInfo<size_t, &std::string::size>("size"),
       CreateFunctionMemberInfo<size_t, &std::string::length>("length"),
       CreateFunctionMemberInfo<void, &std::string::clear>("clear"),
       CreateFunctionMemberInfo<bool, &std::string::empty>("empty"),
       CreateFunctionMemberInfo<std::string&, &std::string::operator=<const std::string&>>("operator=(const std::string&)"),
       CreateFunctionMemberInfo<std::string&, &std::string::operator=<std::string&&>>("operator=(std::string&&)")
    },
    {
        CreateConstructorInfo <std::string>(),
        CreateConstructorInfo<std::string, const char*>("Constructor(const char*)"),
            CreateConstructorInfo<std::string, const std::string&>("Constructor(const std::string&)"),
            CreateConstructorInfo<std::string, std::string&&>("Constructor(std::string&&)")
}

};

Registrar<std::unordered_map<std::string, UPRISE_ENGINE::SERIALISATION::SerializedTypeInfo>> mapRegistrar{
    {
    },
    {
        CreateFunctionMemberInfo<size_t, &std::unordered_map<std::string,SerializedTypeInfo>::size>("size"),
        CreateFunctionMemberInfo<bool, &std::unordered_map<std::string, SerializedTypeInfo>::empty>("empty"),
        CreateFunctionMemberInfo<void, &std::unordered_map<std::string, SerializedTypeInfo>::clear>("clear"),
        CreateFunctionMemberInfo< SerializedTypeInfo,static_cast<SerializedTypeInfo& (std::unordered_map<std::string, SerializedTypeInfo>::*)(const std::string&)>(&std::unordered_map<std::string, SerializedTypeInfo>::operator[])>("operator[]")
    },
    {
        CreateConstructorInfo<std::unordered_map<std::string, UPRISE_ENGINE::SERIALISATION::SerializedTypeInfo>>()
    }
};