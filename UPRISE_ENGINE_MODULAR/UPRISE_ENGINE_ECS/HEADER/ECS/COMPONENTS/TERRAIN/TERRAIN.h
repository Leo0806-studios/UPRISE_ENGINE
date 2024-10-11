#pragma once
#ifndef _Terrain_
#define _Terrain_
import REF_WRAPPER;
#include "BEHAVIOUR/BEHAVIOUR.h"
class TerrainData;
class Terrain:public CORE::Behaviour {
private:
	RefWrapper<TerrainData, true> data;
public:
	static UUID uid;

	Terrain() = default;
	~Terrain(){}
#pragma region Funcs
	void Update()override;
	void Awake()override;
	void Start()override;
	UPRISE_ECS_API void GenerateData();

#pragma endregion

};
#endif // !_Terrain_
