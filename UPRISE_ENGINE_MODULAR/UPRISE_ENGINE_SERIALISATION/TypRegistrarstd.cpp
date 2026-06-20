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

VectorRegistrar<char> vectorCharRegistrar;
VectorRegistrar<unsigned char> vectorUnsignedCharRegistrar;
VectorRegistrar<wchar_t> vectorWCharRegistrar;
VectorRegistrar<bool> vectorBoolRegistrar;
VectorRegistrar<short> vectorShortRegistrar;
VectorRegistrar<unsigned short> vectorUnsignedShortRegistrar;
VectorRegistrar<int> vectorIntRegistrar;
VectorRegistrar<unsigned int> vectorUnsignedIntRegistrar;
VectorRegistrar<long> vectorLongRegistrar;
VectorRegistrar<unsigned long> vectorUnsignedLongRegistrar;
VectorRegistrar<long long> vectorLongLongRegistrar;
VectorRegistrar<unsigned long long> vectorUnsignedLongLongRegistrar;
VectorRegistrar<float> vectorFloatRegistrar;
VectorRegistrar<double> vectorDoubleRegistrar;
VectorRegistrar<long double> vectorLongDoubleRegistrar;
VectorRegistrar<std::string> vectorStringRegistrar;
