// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_HeightMap_
#define UE_HeightMap_
#ifndef ECS_MODULE_BUILD

import REF_WRAPPER; //-V2575 //-V3549
import std; //-V2575 //-V3549
#endif // !ECS_MODULE_BUILD

namespace UPRISE_ENGINE {
    /// <summary>
/// storage class for terain heightmap
/// </summary>
    class HeightMap {
    private:
        /// <summary>
        /// data storage
        /// </summary>
        std::vector<std::vector<float>> Data;
    public:
        /// <summary>
        /// default constructor
        /// </summary>
        HeightMap() = default;
        ~HeightMap() = default;
        /// <summary>
        /// get heigfht at x,y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        UPRISE_ECS_API float GetHeight(Index x, Index y);
        /// <summary>
        /// set heigth at x,y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="height"></param>
        /// <returns></returns>
        UPRISE_ECS_API float SetHeight(Index x, Index y, float height);

    };
}

#endif // !_HeightMap_
