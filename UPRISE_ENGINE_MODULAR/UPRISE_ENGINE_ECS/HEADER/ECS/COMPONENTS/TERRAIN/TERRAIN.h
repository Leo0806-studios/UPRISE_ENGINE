// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Terrain_
#define UE_Terrain_
import REF_WRAPPER; //-V2575 //-V3549
#include "BEHAVIOUR/BEHAVIOUR.h";
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
        RefWrapper<TerrainData, true> data;
    public:
        /// <summary>
        /// UUID of component
        /// </summary>
        static UUID uid;
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
