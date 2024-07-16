#pragma once
#ifndef _TERRAIN_
#define _TERRAIN_
#include "pch.h"
#include "BEHAVIOUR.h"
#include "TERRAIN_DATA.h"
class Terrain : public CORE::Behaviour {
public :
	Terrain_Data Data;
	void Update()override;
	void Awake()override;
	void Start()override;
	void GenerateData();


};
#endif // !_TERRAIN_
