// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_PhysicsObject_
#define UE_PhysicsObject_
#ifndef ECS_MODULE_BUILD
import UPRISE_ENGINE_CORE;
import REF_WRAPPER; //-V2575 //-V3549

#endif // !ECS_MODULE_BUILD

namespace UPRISE_ENGINE {
    namespace PHYSICS {
        class PhysicsObjectInternal;
    }
    /// <summary>
    /// physics object component
    /// enables collision ,rigidbody and other physics related features
    /// </summary>
    class PhysicsObject : public CORE::Behaviour {
    private:
        UE_InClassBoilerplate(UPRISE_ECS_API)
        /// <summary>
        /// internal object
        /// </summary>
        WeakRef< PHYSICS::PhysicsObjectInternal,true> object;
        bool isRigidBody,
            hasCollision,
            isStatic,
            hasMoved;
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

#endif // !_PhysicsObject_
