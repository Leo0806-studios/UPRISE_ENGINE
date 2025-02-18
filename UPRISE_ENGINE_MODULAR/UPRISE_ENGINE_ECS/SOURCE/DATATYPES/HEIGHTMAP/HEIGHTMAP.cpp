// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "DATATYPES/HEIGHTMAP/HEIGHTMAP.h"
namespace UPRISE_ENGINE {
    UPRISE_ECS_API float HeightMap::GetHeight(Index x, Index y)
    {
        return Data[x][y];
    }

    UPRISE_ECS_API float HeightMap::SetHeight(Index x, Index y, float height)
    {
        Data[x][y] = height;
        return Data[x][y];
    }

}
