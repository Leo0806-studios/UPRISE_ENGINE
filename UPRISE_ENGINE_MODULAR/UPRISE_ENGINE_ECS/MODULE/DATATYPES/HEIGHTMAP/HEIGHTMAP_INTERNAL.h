#pragma once
#ifndef UE_HEIGHTMAP_INTERNAL_
#define UE_HEIGHTMAP_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef UPRISEENGINEECS_EXPORTS
#define UPRISE_ECS_API __declspec(dllexport)
#endif
#ifdef __INTELLISENSE__
#include "vector"
#endif // __INTELLISENSE__
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


#endif