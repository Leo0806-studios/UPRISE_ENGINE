#pragma once
#ifndef _TERRAIN_DATA_
#define _TERRAIN_DATA_
#include "RENDER_MATERIAL.h"
#include "stb_image.h"
namespace PAIN {
	class Shader;
	class TerrainModel;
}
class Terrain_Data {
public:
	int width;
	int depth;
	float maxHeight;
	Terrain_Data();
	PAIN:: TerrainModel model;
	std::vector<std::vector<float>> heightMap;
	bool LoadHeightmap(const char* filename);
	float GetHeight(int x, int z) const {
		if (x >= 0 && x < 512 && z >= 0 && z < 512) {
			return heightMap[x][z];
		}
		return 0.0F;
	}
	void SetHeight(int x, int z, float height) {
		if (x >= 0 && x < 512 && z >= 0 && z < 512) {
			heightMap[x][z] = height;
		}
	}
	static std::shared_ptr<Terrain_Data> Create(const char* path,int w, int d, int mh, PAIN::Shader* shader);
};
#endif // !_TERRAIN_DATA_
