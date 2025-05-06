// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_ECS;
import UPRISE_ENGINE_CORE;
#endif // __INTELLISENSE__
//TODO Finish reimplementing
namespace UPRISE_ENGINE {
    UE_OutClassBoilerplate(PhysicsObject)
    UPRISE_ECS_API void PhysicsObject::Awake()
    {
    }

    UPRISE_ECS_API void PhysicsObject::Update()
    {
    }

    UPRISE_ECS_API void PhysicsObject::Start()
    {
    }

}

