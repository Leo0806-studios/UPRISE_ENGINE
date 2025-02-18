#pragma once
#ifndef _MUTEX_
#define _MUTEX_
#include "Windows.h"
namespace  UPRISE_ENGINE {
    class MUTEX {
        CRITICAL_SECTION mutex;
    };
}

#endif // !_MUTEX_
