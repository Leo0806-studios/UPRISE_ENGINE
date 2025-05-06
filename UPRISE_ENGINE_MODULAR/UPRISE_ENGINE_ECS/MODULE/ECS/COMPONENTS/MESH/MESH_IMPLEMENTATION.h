#pragma once
#ifndef UE_MESH_INTERNAL_
#define UE_MESH_INTERNAL_
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
    namespace RENDER {
        class Model;
    }
    /// <summary>
/// class for Mesh Component
/// </summary>
    class Mesh :public Behaviour {
    private:
    public:
        /// <summary>
        /// UUID for the Mesh Component
        /// </summary>


        UE_InClassBoilerplate(UPRISE_ECS_API)
            /// <summary>
            /// default constructor
            /// </summary>
            Mesh() = default;
        ~Mesh() {}
#pragma region Funcs
        UPRISE_ECS_API void Update()override;
        UPRISE_ECS_API void Awake()override;
        UPRISE_ECS_API void Start()override;
#pragma endregion

    };
}


#endif