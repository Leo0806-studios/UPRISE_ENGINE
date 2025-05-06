#pragma once
#ifndef UE_TERRAIN_INTERNAL_
#define UE_TERRAIN_INTERNAL_
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
    //#include "Windows.h";
    class TerrainData;
    /// <summary>
    /// Terrain Component
    /// </summary>
    class Terrain :public Behaviour {
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
#endif