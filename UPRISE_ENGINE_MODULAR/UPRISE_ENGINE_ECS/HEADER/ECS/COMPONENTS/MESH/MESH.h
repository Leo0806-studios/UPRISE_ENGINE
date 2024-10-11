#pragma once
#ifndef _Mesh_
#define _Mesh_
#include "BEHAVIOUR/BEHAVIOUR.h"
class Mesh :public CORE::Behaviour{
private:
public:
	static UUID uid;

	Mesh() = default;
	~Mesh(){}
#pragma region Funcs
	UPRISE_ECS_API void Update()override;
	UPRISE_ECS_API void Awake()override;
	UPRISE_ECS_API void Start()override;
#pragma endregion

};
#endif // !_Mesh_
