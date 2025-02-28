// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include  "DATATYPES/TERRAINDATA/TerrainData.h"
#include "DATATYPES/HEIGHTMAP/HEIGHTMAP.h"
#include <Windows.h>
namespace UPRISE_ENGINE {
    inline UPRISE_ECS_API float TerrainData::GetHeight(size_t x, size_t y) { return Heightmap->GetHeight(x, y); }
    inline UPRISE_ECS_API float TerrainData::SetHeight(size_t x, size_t y, float height) { return Heightmap->SetHeight(x, y, height); }
    template<class _Ty, class _Arg>
    _Ty CallCSharpFunction(const WCHAR* patrh, char* functionName, _Arg argument) {
       // const WCHAR* addrs = L"C:\\Users\\leo08\\source\\repos\\Neuer Ordner(2)\\NativeLibrary\\bin\\release\\net8.0\\win - x64\\publish";
        HINSTANCE handle = LoadLibrary(patrh); //-V2001
        typedef _Ty((*externFuction)(_Arg));
        FARPROC func = symLoad(handle, functionName);
        static_assert(sizeof(FARPROC) == sizeof(externFuction));
        externFuction Function = static_cast<externFuction>(static_cast<void*>(func)); //-V2597 //-V206
        _Ty result = Function(argument);
        return result;
    }
    bool TerrainData::LoadHeightmap(const char* filename)
    {
        //int imgWidth, imgHeight, nrChannels;
        //unsigned char* data = stbi_load(filename.c_str(), &imgWidth, &imgHeight, &nrChannels, 0);
       // auto oooo = CallCSharpFunction(filename.c_str());
        const WCHAR* addrs = L"C:\\Users\\leo08\\source\\repos\\Neuer Ordner (2)\\NativeLibrary\\bin\\release\\net8.0-windows\\win-x64\\native\\NativeLibrary.dll";
        float* owow = CallCSharpFunction<float*, const char*>(addrs, const_cast<char*>("Heightmap"), filename);
        std::vector<float> heightValues(owow, owow + (512 * 512));
        //if (!data) {
        //    std::cerr << "Failed to load heightmap: " << filename << std::endl;
        //    return false;
        //}

        //width = imgWidth;
        //depth = imgHeight;
        std::vector<std::vector<float>> heightMap;
        heightMap.resize(512, std::vector<float>(512));

        for (unsigned long long z = 0; z < 512; ++z) {
            for (unsigned long long x = 0; x < 512; ++x) {
                float height = heightValues[z * 512 + x] * Maxheight;
                //if (heightValues[z * 512 + x] > 0) {
                //    float t = heightValues[z * 512 + x];
                //    std::cout << "island\n";
                //}
                SetHeight(x, z, height);
            }
        }

        //stbi_image_free(data);
        return true;
    }

    SharedRef<TerrainData, true> TerrainData::Create(const char* path, int w, int d, float mh, SharedRef<RENDER::Shader, true> shader)
    {
        SharedRef<TerrainData, true> tmp = CreateRefs::CreateSharedRef<TerrainData, true>();
        tmp->Maxheight = mh;
        tmp->depth = d;
        tmp->witdh = w;
        tmp->LoadHeightmap(path);
        //TODO tmp->data = RENDER::TerrainModel(&tmp, w, d, mh, shader);

        return tmp;
    }
}
