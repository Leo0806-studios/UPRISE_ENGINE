#pragma once
#ifndef _OWNED_REF_
#define _OWNED_REF_
#include "CORE/REF_WRAPPERS/WEAK_REF/WEAK_REF.h"
namespace UPRISE_ENGINE {
    template <typename Type>
    class OwnedRef {

    public:
        WeakRef<Type, true> GetWeakRef();
    };
}
#endif // !_OWNED_REF_
