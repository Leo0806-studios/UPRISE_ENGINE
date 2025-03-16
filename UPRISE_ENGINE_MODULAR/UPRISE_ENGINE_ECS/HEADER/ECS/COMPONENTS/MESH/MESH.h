// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Mesh_
#define UE_Mesh_
#ifndef ECS_MODULE_BUILD
import UPRISE_ENGINE_CORE;

#endif // !ECS_MODULE_BUILD;

namespace UPRISE_ENGINE {
    namespace RENDER {
        class Model;
    }
    /// <summary>
/// class for Mesh Component
/// </summary>
    class Mesh :public CORE::Behaviour {
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

#endif // !_Mesh_
