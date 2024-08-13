#include "pch.h"
#include "HeaderE/DATATYPES/D_TERRAIN_DATA.h"
//#import "ManagedUtills.tlb" named_guids

//#include "ManagedUtills.tlh"
Terrain_Data::Terrain_Data()
{
}
void ssharp_methcall() {

    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM library" << std::endl;
        

    }
   // ManagedUtills::IHeightmapProccesorPtr pHeightmapProc;
    //hr = pHeightmapProc.CreateInstance(__uuidof(ManagedUtills::IHeightmapProccesor));
    //if (FAILED(hr)) {
     //   std::cerr << "Failed to create instance of HeightmapProccesor: 0x" << std::hex << hr << std::endl;
        
    //}




}

bool Terrain_Data::LoadHeightmap(const char* filename)
{
    int imgWidth, imgHeight, nrChannels;
    //unsigned char* data = stbi_load(filename.c_str(), &imgWidth, &imgHeight, &nrChannels, 0);
   // auto oooo = CallCSharpFunction(filename.c_str());
    const WCHAR* addrs = L"C:\\Users\\leo08\\source\\repos\\Neuer Ordner (2)\\NativeLibrary\\bin\\release\\net8.0-windows\\win-x64\\native\\NativeLibrary.dll";
    float* owow = CallCSharpFunction<float*,const char*>(addrs,(char*)"Heightmap",filename);
    std::vector<float> heightValues(owow, owow + (512 * 512));
    //if (!data) {
    //    std::cerr << "Failed to load heightmap: " << filename << std::endl;
    //    return false;
    //}

    //width = imgWidth;
    //depth = imgHeight;
    heightMap.resize(512, std::vector<float>(512));

    for (int z = 0; z < 512; ++z) {
        for (int x = 0; x < 512; ++x) {
            float height = heightValues[z * 512 + x] * maxHeight;
            if (heightValues[z * 512 + x] > 0) {
                float t = heightValues[z * 512 + x];
                std::cout << "island\n";
            }
            SetHeight(x, z, height);
        }
    }

    //stbi_image_free(data);
    return true;
}

std::shared_ptr<Terrain_Data> Terrain_Data::Create(const char* path,int w,int d,int mh,PAIN::Shader* shader)
{
    Terrain_Data tmp;
    tmp.maxHeight = mh;
    tmp.depth = d;
    tmp.width = w;
    tmp.LoadHeightmap(path);
    tmp.model = PAIN::TerrainModel(&tmp, w, d, mh,shader);
    
    return std::make_shared<Terrain_Data>(tmp);
}

