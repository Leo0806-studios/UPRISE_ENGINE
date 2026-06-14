import UE_SERIALISATION;
template <typename T>
using Registrar= UPRISE_ENGINE::SERIALISATION::TypeRegistrar<T>;
Registrar<char> charRegistrar;
Registrar <unsigned char> ucharRegistrar;
Registrar<wchar_t> wcharRegistrar;
Registrar<bool> boolRegistrar;
Registrar<void> voidRegistrar;
Registrar<short> shortRegistrar;
Registrar<unsigned short> ushortRegistrar;
Registrar<int> intRegistrar;
Registrar<unsigned int> uintRegistrar;
Registrar<long> longRegistrar;
Registrar<unsigned long> ulongRegistrar;
Registrar<long long> longlongRegistrar;
Registrar<unsigned long long> ulonglongRegistrar;
Registrar<float> floatRegistrar;
Registrar<double> doubleRegistrar;
