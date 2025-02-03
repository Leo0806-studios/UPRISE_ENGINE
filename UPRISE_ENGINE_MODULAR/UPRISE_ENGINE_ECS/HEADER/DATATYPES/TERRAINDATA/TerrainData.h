// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_TerrainData_
#define UE_TerrainData_
import REF_WRAPPER; //-V2575
namespace UPRISE_ENGINE {
    class HeightMap;
    namespace RENDER {
        class Shader;
        class TerrainModel;
    }
    /// <summary>
    /// terrain data class
    /// </summary>
    class TerrainData {
    private:
        /// <summary>
        /// withd of the terrain
        /// </summary>
        int witdh;
        /// <summary>
        /// depth of the terrain
        /// </summary>
        int depth;
        /// <summary>
        /// max height of the terrain
        /// </summary>
        float Maxheight;
        /// <summary>
        /// Heightmap
        /// </summary>
        RefWrapper<HeightMap, true> Heightmap;
        /// <summary>
        /// model of the terrain
        /// </summary>
        RefWrapper<RENDER::TerrainModel, true> data;
    public:
        /// <summary>
        /// default constructor
        /// </summary>
        TerrainData() = default;
        ~TerrainData() = default;
        /// <summary>
        /// load heightmap
        /// uses a call to c# to load the heightmap
        /// </summary>
        /// <param name="filename"></param>
        /// <returns></returns>
        UPRISE_ECS_API bool LoadHeightmap(const char* filename);
        /// <summary>
        /// get height at x,y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        UPRISE_ECS_API float GetHeight(int x, int y);
        /// <summary>
        /// set height at x,y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="height"></param>
        /// <returns></returns>
        UPRISE_ECS_API float SetHeight(int x, int y, float height);
        /// <summary>
        /// static function to create a terrain data object
        /// </summary>
        /// <param name="path"></param>
        /// <param name="w"></param>
        /// <param name="d"></param>
        /// <param name="mh"></param>
        /// <param name="shader"></param>
        /// <returns></returns>
        UPRISE_ECS_API static RefWrapper<TerrainData, true> Create(const char* path, int w, int d, int mh, RefWrapper<RENDER::Shader, true> shader);
    };
}

#endif // !_TerrainData_
