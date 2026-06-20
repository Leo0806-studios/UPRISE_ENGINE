export module UE_SERIALISATION:TYPE_REGISTRAR_PARTIAL_STD_SPEC;
import :RTTI_STORAGE;
import :SERIALIZED_TYPE_INFO;
export namespace UPRISE_ENGINE::SERIALISATION {
    template <typename T>
    struct VectorRegistrar {
        VectorRegistrar(UPRISE_ENGINE::SERIALISATION::FunctionMemberInfoAggregat funcs = {}, UPRISE_ENGINE::SERIALISATION::ConstructorInfoAggregat ctors = {}) {
            std::is_default_constructible<std::vector<T>>::value ? ctors.members.push_back(CreateConstructorInfo<std::vector<T>>()) : (void)0;
            std::is_copy_constructible<std::vector<T>>::value ? ctors.members.push_back(CreateConstructorInfo<std::vector<T>, const std::vector<T>&>(std::format("Constructor(const {}&)", typeid(std::vector<T>).name()))) : (void)0;
            //std::is_move_constructible_v < std::vector<T>> ? ctors.members.push_back(CreateConstructorInfo<std::vector<T>, std::vector<T>&&>(std::format("Constructor({}&&)", typeid(std::vector<T>).name()))) : (void)0;
            std::is_copy_assignable_v<std::vector<T>> ? funcs.members.push_back(CreateFunctionMemberInfo < std::vector<T>&,static_cast<std::vector<T>&(std::vector<T>::*)(const std::vector<T>&)>( & std::vector<T>::operator=)>(std::format("operator=(const {}&)", typeid(std::vector<T>).name()))) : (void)0;
            //std::is_move_assignable_v<std::vector<T>> ? funcs.members.push_back(CreateFunctionMemberInfo<std::vector<T>&,static_cast<std::vector<T>&(std::vector<T>::*)(std::vector<T>&&)>( & std::vector<T>::operator=)>(std::format("operator=({}&&)", typeid(std::vector<T>).name()))) : (void)0;
            funcs.members.push_back(CreateFunctionMemberInfo<size_t, &std::vector<T>::size>("size"));
            funcs.members.push_back(CreateFunctionMemberInfo<bool, &std::vector<T>::empty>("empty"));
            funcs.members.push_back(CreateFunctionMemberInfo<void, &std::vector<T>::clear>("clear"));
            funcs.members.push_back(CreateFunctionMemberInfo<void,static_cast<void(std::vector<T>::*)(const T&)>(&std::vector<T>::push_back)>(std::format("push_back(const {}&)", typeid(T).name())));
            //funcs.members.push_back(CreateFunctionMemberInfo<void,static_cast<void(std::vector<T>::*)( T&&)>(&std::vector<T>::push_back)>(std::format("push_back( {}&&)", typeid(T).name())));
            if constexpr (!std::is_same_v<T, bool>) {//fuck std::vector<bool>
            funcs.members.push_back(CreateFunctionMemberInfo<const T*, static_cast<const T* (std::vector<T>::*)()const noexcept>(&std::vector<T>::data)>("const data"));
            funcs.members.push_back(CreateFunctionMemberInfo<T*, static_cast<T*(std::vector<T>::*)()noexcept>(&std::vector<T>::data)>("data"));
            }
            TypeRegistrar<std::vector<T>> registrar{
               {},
               std::move(funcs),
               std::move(ctors)
            };
        }
    };

    template<typename Key, typename Value>
    struct UnorderedMapRegistrar {
        UnorderedMapRegistrar(UPRISE_ENGINE::SERIALISATION::FunctionMemberInfoAggregat funcs = {}, UPRISE_ENGINE::SERIALISATION::ConstructorInfoAggregat ctors = {}) {
            std::is_default_constructible<std::unordered_map<Key, Value>>::value ? ctors.members.push_back(CreateConstructorInfo<std::unordered_map<Key, Value>>()) : (void)0;
            std::is_copy_constructible<std::unordered_map<Key, Value>>::value ? ctors.members.push_back(CreateConstructorInfo<std::unordered_map<Key, Value>, const std::unordered_map<Key, Value>&>(std::format("Constructor(const {}&)", typeid(std::unordered_map<Key, Value>).name()))) : (void)0;
            std::is_move_constructible_v < std::unordered_map<Key, Value>> ? ctors.members.push_back(CreateConstructorInfo<std::unordered_map<Key, Value>, std::unordered_map<Key, Value>&&>(std::format("Constructor({}&&)", typeid(std::unordered_map<Key, Value>).name()))) : (void)0;
            std::is_copy_assignable_v<std::unordered_map<Key, Value>> ? funcs.members.push_back(CreateFunctionMemberInfo < std::unordered_map<Key, Value>&, &std::unordered_map<Key, Value>::operator=>(std::format("operator=(const {}&)", typeid(std::unordered_map<Key, Value>).name()))) : (void)0;
            std::is_move_assignable_v<std::unordered_map<Key, Value>> ? funcs.members.push_back(CreateFunctionMemberInfo<std::unordered_map<Key, Value>&, &std::unordered_map<Key, Value>::operator=>(std::format("operator=({}&&)", typeid(std::unordered_map<Key, Value>).name()))) : (void)0;
            funcs.members.push_back(CreateFunctionMemberInfo<size_t, &std::unordered_map<Key, Value>::size>("size"));
            funcs.members.push_back(CreateFunctionMemberInfo<bool, &std::unordered_map<Key, Value>::empty>("empty"));
            funcs.members.push_back(CreateFunctionMemberInfo<void, &std::unordered_map<Key, Value>::clear>("clear"));
            funcs.members.push_back(CreateFunctionMemberInfo<Value&, static_cast<Value & (std::unordered_map<Key, Value>::*)(const Key&)>(&std::unordered_map<Key, Value>::operator[])>(std::format("operator[](const {}&)", typeid(Key).name())));
            TypeRegistrar<std::unordered_map<Key, Value>> registrar{
               {},
               std::move(funcs),
               std::move(ctors)
            };
        }
    };
}