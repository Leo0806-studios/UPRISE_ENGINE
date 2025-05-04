#pragma once
#ifndef UE_SHARED_REF_INTERNAL_
#define UE_SHARED_REF_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif

#ifdef __INTELLISENSE__
#include "REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE_INTERNAL.h"
#include "REF_WRAPPERS/WRAPPER_BASE/WRAPPER_BASE_INTERNAL.h"
#endif
namespace UPRISE_ENGINE {
    template<typename T, bool NullChk>
    class SharedRef : public WrapperBase{

    };
    //TODO implement
}
#endif