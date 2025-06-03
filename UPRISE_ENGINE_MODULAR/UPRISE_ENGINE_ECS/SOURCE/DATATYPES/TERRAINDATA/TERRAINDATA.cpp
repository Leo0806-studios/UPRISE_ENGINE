// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else


import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_ECS;


#endif
namespace UPRISE_ENGINE {
    inline UPRISE_ECS_API float TerrainData::GetHeight(size_t x, size_t y) {
        return Heightmap->GetHeight(x, y);
    }
    inline UPRISE_ECS_API float TerrainData::SetHeight(size_t x, size_t y, float height) { return Heightmap->SetHeight(x, y, height); }

    TerrainData& UPRISE_ENGINE::TerrainData::operator=(TerrainData&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) //NOSONAR
    {
        witdh = other.witdh;
        depth = other.depth;
        Heightmap = std::move(other.Heightmap);
        data = std::move(other.data);
        Maxheight = other.Maxheight;
        other.witdh = 0;
        other.depth = 0;
        other.Maxheight = 0.0F;

        return *this;
        
    }
    TerrainData::TerrainData(TerrainData&& other)noexcept(RW_USE_CPP_EXCEPTIONS_==false) : //-V2537
        witdh(other.witdh),
        depth(other.depth),
        Heightmap(std::move(other.Heightmap)),
        data(std::move(other.data)),
        Maxheight(other.Maxheight)

    {
    }

    bool TerrainData::LoadHeightmap(const char* filename)
    {
        (void)filename;
        UE_THROW_NOT_IMPLEMENTED;

        return true;
    }

    OwnedRef<TerrainData> TerrainData::Create(const char* path, int w, int d, float mh, WeakRef<RENDER::Shader, true> shader)
    {
        OwnedRef<TerrainData> tmp = OwnedRef<TerrainData>::Create();
        tmp->Maxheight = mh;
        tmp->depth = d;
        tmp->witdh = w;
        tmp->LoadHeightmap(path);
        UE_THROW_NOT_IMPLEMENTED;
        UE_UNUSED_PARAMETER(shader);
        //TODO tmp->data = RENDER::TerrainModel(&tmp, w, d, mh, shader);//NOSONAR

        return tmp;
    }
}