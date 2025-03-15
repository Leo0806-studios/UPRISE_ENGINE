export module UPRISE_ENGINE_ECS:HEIGHTMAP_IMPL;
import :HEIGHTMAP;

export namespace UPRISE_ENGINE {
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