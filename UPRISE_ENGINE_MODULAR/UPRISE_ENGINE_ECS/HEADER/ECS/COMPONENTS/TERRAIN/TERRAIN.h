// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Terrain_
#define _Terrain_
import REF_WRAPPER;
#include "BEHAVIOUR/BEHAVIOUR.h";
//#include "Windows.h";
class TerrainData;
/// <summary>
/// Terrain Component
/// </summary>
class Terrain:public CORE::Behaviour {
private:
	/// <summary>
	/// internal Data   
	/// </summary>
	RefWrapper<TerrainData, true> data;
public:
	/// <summary>
	/// UUID of component
	/// </summary>
	static UUID uid;
	/// <summary>
    /// default constructor
	/// </summary>
	Terrain() = default;
	~Terrain(){}
#pragma region Funcs
	void Update()override;
	void Awake()override;
	void Start()override;
	/// <summary>
    /// Gennerate Terrrain Data
	/// </summary>
	/// <returns></returns>
	UPRISE_ECS_API void GenerateData();

#pragma endregion

};
#endif // !_Terrain_
