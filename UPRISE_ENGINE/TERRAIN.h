#pragma once
#ifndef _TERRAIN_
#define _TERRAIN_
#include "pch.h"
#include "HeaderE/CORE/C_BEHAVIOUR.h"
#include "HeaderE/DATATYPES/D_TERRAIN_DATA.h"
class Terrain : public CORE::Behaviour {
public :
	COPY(Terrain, Data = Terrain_Data(););
	DEEP_COPY(Terrain, a->Data = this->Data; , )
		I_WINDOW(ImGui::Text("Terrain Data");)
	Terrain_Data Data;
	void Update()override;
	void Awake()override;
	void Start()override;
	void GenerateData();


};
#endif // !_TERRAIN_
