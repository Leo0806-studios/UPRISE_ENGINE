#pragma once
#ifndef _TerrainData_
#define _TerrainData_
import REF_WRAPPER;
class HeightMap;
namespace RENDER {
	class Shader;
	class TerrainModel;
}
class TerrainData {
private:
	int witdh;
	int depth;
	float Maxheight;
	RefWrapper<HeightMap,true> Heightmap;
	RefWrapper<RENDER::TerrainModel, true> data;
public:
	TerrainData() = default;
	~TerrainData(){}
	UPRISE_ECS_API bool LoadHeightmap(const char* filename);
	UPRISE_ECS_API float GetHeight(int x, int y);
	UPRISE_ECS_API float SetHeight(int x, int y,float height);
	UPRISE_ECS_API static RefWrapper<TerrainData, true> Create(const char* path, int w, int d, int mh, RefWrapper<RENDER::Shader, true> shader);
};
#endif // !_TerrainData_
