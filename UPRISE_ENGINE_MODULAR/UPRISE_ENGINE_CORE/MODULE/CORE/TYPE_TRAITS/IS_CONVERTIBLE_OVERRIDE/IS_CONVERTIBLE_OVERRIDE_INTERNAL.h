#pragma once
#ifndef UE_IS_CONVERTIBLE_OVERRIDE_INTERNAL_
#define UE_IS_CONVERTIBLE_OVERRIDE_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#define UE_DEFINE_BIDIRECTIONAL_CONVERSION(From, To) \
    template<> \
    struct IsConvertibleOverride<From, To> { \
        static constexpr bool value = true; \
    }; \
    template<> \
    struct IsConvertibleOverride<To, From> { \
        static constexpr bool value = true; \
    };

namespace UPRISE_ENGINE{
    class Object;
    class Behaviour;
    class Component;
    class GameObject;
    namespace TYPE_TRAITS {
    /// <summary>
    /// is convertible override. Defaults to no.only used for Ref wrappers to get around the issiue with forward declarations. provides specalisations for known good types.
    /// </summary>
    /// <typeparam name="From"></typeparam>
    /// <typeparam name="To"></typeparam>
    template<typename From, typename To>
    struct IsConvertibleOverride {
        static constexpr bool value = false;
    };
    UE_DEFINE_BIDIRECTIONAL_CONVERSION(Object, Behaviour)
    UE_DEFINE_BIDIRECTIONAL_CONVERSION(Object, Component)
    UE_DEFINE_BIDIRECTIONAL_CONVERSION(Object, GameObject)

    
} // namespace UPRISE_ENGINE::TYPE_TRAITS
}

#endif