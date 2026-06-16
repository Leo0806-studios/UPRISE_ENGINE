export module UE_SERIALISATION:TYPE_TRAITS;
import std;
export namespace UPRISE_ENGINE::SERIALISATION {
    enum class CallingConvention {
        StdCall,
        Cdecl,
        FastCall,
        VectorCall,
        ThisCall
    };
    template <typename T>
    struct member_traits {

    };
    template<typename T, typename C>
    struct member_traits<T C::*> {
        using type = T;
        using Class = C;
    };
    template<typename T>
    struct function_traits {

    };
    template<typename R, typename... Args>
    struct function_traits<R(_cdecl*)(Args...)>
    {
        using return_type = R;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::Cdecl;
        constexpr static bool is_noexcept = false;
        constexpr static bool is_const = false;
    };


    template<typename R, typename... Args>
    struct function_traits<R(__vectorcall*)(Args...)>
    {
        using return_type = R;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::VectorCall;
        constexpr static bool is_noexcept = false;
        constexpr static bool is_const = false;
    };
    





    template<typename R, typename... Args>
    struct function_traits<R(_cdecl*)(Args...) noexcept>
    {
        using return_type = R;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::Cdecl;
        constexpr static bool is_noexcept = true;
        constexpr static bool is_const = false; 

    };


    template<typename R, typename... Args>
    struct function_traits<R(__vectorcall*)(Args...)noexcept>
    {
        using return_type = R;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::VectorCall;
        constexpr static bool is_noexcept = true;
        constexpr static bool is_const = false;
    };






    template<typename R, typename T, typename... Args>
    struct function_traits<R(_cdecl T::*)(Args...)>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::Cdecl;
        constexpr static bool is_noexcept = false;
        constexpr static bool is_const = false;
    };

    template<typename R, typename T, typename... Args>
    struct function_traits<R(__vectorcall T::*)(Args...)>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::VectorCall;
        constexpr static bool is_noexcept = false;
        constexpr static bool is_const = false;
    };

    template<typename R, typename T, typename... Args>
    struct function_traits<R(_cdecl T::*)(Args...)noexcept>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::Cdecl;
        constexpr static bool is_noexcept = true;
        constexpr static bool is_const = false; 
    };

    template<typename R, typename T, typename... Args>
    struct function_traits<R(__vectorcall T::*)(Args...)noexcept>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::VectorCall;
        constexpr static bool is_noexcept = true;
    };




    template<typename R, typename T, typename... Args>
    struct function_traits<R(_cdecl T::*)(Args...)const>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::Cdecl;
        constexpr static bool is_noexcept = false;
        constexpr static bool is_const = true;
    };

    template<typename R, typename T, typename... Args>
    struct function_traits<R(__vectorcall T::*)(Args...)const>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::VectorCall;
        constexpr static bool is_noexcept = false;
        constexpr static bool is_const = true;
    };

    template<typename R, typename T, typename... Args>
    struct function_traits<R(_cdecl T::*)(Args...)const noexcept>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::Cdecl;
        constexpr static bool is_noexcept = true;
        constexpr static bool is_const = true;
    };

    template<typename R, typename T, typename... Args>
    struct function_traits<R(__vectorcall T::*)(Args...)const noexcept>
    {
        using return_type = R;
        using class_type = T;
        using args_tuple = std::tuple<Args...>;
        static constexpr size_t arity = sizeof...(Args);
        template<size_t N>
        using arg = std::tuple_element_t<N, std::tuple<Args...>>;
        constexpr static CallingConvention calling_convention = CallingConvention::VectorCall;
        constexpr static bool is_noexcept = true;
        constexpr static bool is_const = true;
    };


}
export namespace std {
    std::string to_string(const UPRISE_ENGINE::SERIALISATION::CallingConvention& convention) {
        switch (convention) {
            case UPRISE_ENGINE::SERIALISATION::CallingConvention::StdCall:
                return "StdCall";
            case UPRISE_ENGINE::SERIALISATION::CallingConvention::Cdecl:
                return "Cdecl";
            case UPRISE_ENGINE::SERIALISATION::CallingConvention::FastCall:
                return "FastCall";
            case UPRISE_ENGINE::SERIALISATION::CallingConvention::VectorCall:
                return "VectorCall";
            case UPRISE_ENGINE::SERIALISATION::CallingConvention::ThisCall:
                return "ThisCall";
            default:
                return "Unknown";
        }
    }
}