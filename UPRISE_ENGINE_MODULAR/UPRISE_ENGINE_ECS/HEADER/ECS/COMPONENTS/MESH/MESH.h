#pragma once
#ifndef _Mesh_
#define _Mesh_
#include "CORE/BEHAVIOUR/BEHAVIOUR.h";

/// <summary>
/// class for Mesh Component
/// </summary>
class Mesh :public CORE::Behaviour{
private:
public:
	/// <summary>
    /// UUID for the Mesh Component
	/// </summary>
	static UUID uid;
	/// <summary>
    /// default constructor
	/// </summary>
	Mesh() = default;
	~Mesh(){}
#pragma region Funcs
	UPRISE_ECS_API void Update()override;
	UPRISE_ECS_API void Awake()override;
	UPRISE_ECS_API void Start()override;
#pragma endregion

};
#endif // !_Mesh_
