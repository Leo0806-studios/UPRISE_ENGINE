#pragma once
#ifndef _LAYER_
#define _LAYER_
import std;
/// <summary>
/// layer for GameObjects
/// </summary>
 class Layer {
private:
	/// <summary>
	/// layer id
	/// </summary>
	int id;
	/// <summary>
	/// layer name
	/// </summary>
	std::string name;
public:
#pragma region constructor
	/// <summary>
    /// default cosntructor
	/// </summary>
	Layer() = default;
	/// <summary>
    /// constructor that accsepts an id and name
	/// </summary>
	/// <param name="id"></param>
	/// <param name="name"></param>
	Layer(int id, std::string name) :id(id), name(name) {};
#pragma endregion
	/// <summary>
    /// getter for the name of the layer
    /// returns the name of the layer as a non const reference
	/// </summary>
	/// <returns></returns>
	__inline UPRISE_CORE_API std::string& Name() { return name; }

    /// <summary>
    /// getter for the id of the layer
    /// returns the id of the layer
    /// <summary>
	__inline UPRISE_CORE_API int ID() { return id; }
};
#endif // !1
