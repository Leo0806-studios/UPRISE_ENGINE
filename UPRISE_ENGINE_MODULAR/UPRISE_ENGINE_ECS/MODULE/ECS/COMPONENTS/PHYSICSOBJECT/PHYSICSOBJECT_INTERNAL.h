#pragma once
#ifndef UE_PHYSICSOBJECT_INTERNAL_
#define UE_PHYSICSOBJECT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "BEHAVIOUR/BEHAVIOUR_INTERNAL.h"
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    namespace PHYSICS {
        class PhysicsObjectInternal;
    }
    /// <summary>
    /// physics object component
    /// enables collision ,rigidbody and other physics related features
    /// </summary>
    class PhysicsObject : public Behaviour {
    private:
        UE_InClassBoilerplate(UPRISE_ECS_API)
            /// <summary>
            /// internal object
            /// </summary>
            WeakRef< PHYSICS::PhysicsObjectInternal, true> object;
        bool isRigidBody;
        bool hasCollision;
        bool isStatic;
        bool hasMoved;
        char PAD[4]; //TODO find a way to better allign or but data here
    public:
        /// <summary>
        /// default constructor
        /// </summary>
        PhysicsObject() = default;
        ~PhysicsObject() {}
        UPRISE_ECS_API void Awake()override;
        UPRISE_ECS_API void Update()override;
        UPRISE_ECS_API void Start()override;
    };
}


#endif