#pragma once
#pragma once
#ifndef UE_CONCEPT_ALIGN_INTERNAL_INTERNAL_
#define UE_CONCEPT_ALIGN_INTERNAL_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
namespace UPRISE_ENGINE::CORE::CONCEPTS {

            template <typename T, size_t Align_>
            concept Align = requires(T t) {
                { alignof(T) == Align_ };
            };
        
}


#endif