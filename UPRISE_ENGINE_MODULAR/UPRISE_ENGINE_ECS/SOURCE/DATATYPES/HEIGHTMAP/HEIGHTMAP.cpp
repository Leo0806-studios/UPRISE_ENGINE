// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "DATATYPES/HEIGHTMAP/HEIGHTMAP.h"

UPRISE_ECS_API float HeightMap::GetHeight(int x, int y)
{
    return Data[x][y];
}

UPRISE_ECS_API float HeightMap::SetHeight(int x, int y, float height)
{
    return Data[x][y]=height;
}
