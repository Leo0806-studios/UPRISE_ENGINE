// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _HeightMap_
#define _HeightMap_
import REF_WRAPPER;
import std;
/// <summary>
/// storage class for terain heightmap
/// </summary>
 class HeightMap {
private:
	/// <summary>
    /// data storage
	/// </summary>
	std::vector<std::vector<float>> Data;
public:
	/// <summary>
    /// default constructor
	/// </summary>
	HeightMap() = default;
    ~HeightMap() = default;
	/// <summary>
    /// get heigfht at x,y
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	UPRISE_ECS_API float GetHeight(int x, int y);
	/// <summary>
    /// set heigth at x,y
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="height"></param>
	/// <returns></returns>
	UPRISE_ECS_API float SetHeight(int x, int y,float height);

};
#endif // !_HeightMap_
