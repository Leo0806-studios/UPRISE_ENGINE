// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Mesh_
#define UE_Mesh_
#include "CORE/BEHAVIOUR/BEHAVIOUR.h"
namespace UPRISE_ENGINE {
    /// <summary>
/// class for Mesh Component
/// </summary>
    class Mesh :public CORE::Behaviour {
    private:
    public:
        /// <summary>
        /// UUID for the Mesh Component
        /// </summary>
        static UUID uid;
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

#endif // !_Mesh_
