#pragma once
#ifndef _HeightMap_
#define _HeightMap_
import REF_WRAPPER;
import std;
class HeightMap {
private:
	std::vector<std::vector<float>> Data;
public:
	HeightMap() = default;
	~HeightMap(){}
	UPRISE_ECS_API float GetHeight(int x, int y);
	UPRISE_ECS_API float SetHeight(int x, int y,float height);

};
#endif // !_HeightMap_
