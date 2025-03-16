// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Terrain_
#define UE_Terrain_
#ifndef ECS_MODULE_BUILD
import UPRISE_ENGINE_CORE;
import REF_WRAPPER; //-V2575 //-V3549

#endif // !ECS_MODULE_BUILD

namespace UPRISE_ENGINE {
    //#include "Windows.h";
    class TerrainData;
    /// <summary>
    /// Terrain Component
    /// </summary>
    class Terrain :public CORE::Behaviour {
    private:

        /// <summary>
        /// internal Data   
        /// </summary>
        WeakRef<TerrainData, true> data;
        char PAD[8];//TODO Find a way to better align this or put data here
    public:
        UE_InClassBoilerplate(UPRISE_ECS_API)

        /// <summary>
        /// default constructor
        /// </summary>
        Terrain() = default;
        ~Terrain() {}
#pragma region Funcs
        void Update()override;
        void Awake()override;
        void Start()override;
        /// <summary>
        /// Gennerate Terrrain Data
        /// </summary>
        /// <returns></returns>
        UPRISE_ECS_API void GenerateData();

#pragma endregion

    };
}

#endif // !_Terrain_
