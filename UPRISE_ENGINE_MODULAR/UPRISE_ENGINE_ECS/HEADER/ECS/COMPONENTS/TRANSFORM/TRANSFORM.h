#pragma once
#ifndef _Transform_
#define _Transform_
#include "GLOBAL/GLINCLUDES.h"
#include "BEHAVIOUR/BEHAVIOUR.h"
#include "VECTOR/VECTOR3/FAST/VECTOR3_F.h"

#include "QUTERION/QUATERION.h"
/// <summary>
/// Transform component on Gameobjects
/// </summary>
class Transform :public CORE::Behaviour {
private:
	/// <summary>
    /// position of the gameobject
	/// </summary>
	Vector3 position;
	/// <summary>
    /// rotation as quaterion
	/// </summary>
	Quaternion rotation;
	/// <summary>
    /// rotation as vector3
	/// </summary>
	Vector3 vec3rot;
	/// <summary>
    /// local forwar vector
	/// </summary>
	Vector3 forward;
    /// <summary>
    /// local up vector
    /// </summary>
	Vector3 up;
    /// <summary>
/// local right vector
/// </summary>
/// 
	Vector3 right;
public:
	/// <summary>
	/// uuid of component
	/// </summary>
	static UUID uid;
#pragma region Constructor
	/// <summary>
    /// default constructor
	/// </summary>
	Transform() = default;

#pragma endregion
#pragma region destructor
	~Transform() {}

#pragma endregion

#pragma region funcs
	/// <summary>
	/// returns a modifyable vector 3 refference to the position
	/// </summary>
	/// <returns></returns>
	UPRISE_ECS_API Vector3& Position();
	/// <summary>
	/// provides a const refference to the local forward
	/// </summary>
	/// <returns></returns>
	UPRISE_ECS_API const Vector3& Forward();
	/// <summary>
/// provides a const refference to the local Up
/// </summary>
/// <returns></returns>
	UPRISE_ECS_API const Vector3& Up();
	/// <summary>
/// provides a const refference to the local right
/// </summary>
/// <returns></returns>
	UPRISE_ECS_API const Vector3& Right();
	/// <summary>
	/// sets the rotation to be equal to the supplied vector3
	/// </summary>
	/// <param name="vec"></param>
	/// <returns></returns>
	UPRISE_ECS_API void SetRotation(Vector3 vec);
	/// <summary>
	/// sets the rotation to be equal to the supplied quaterion
	/// </summary>
	/// <param name="vec"></param>
	/// <returns></returns>
	UPRISE_ECS_API void SetRotation(Quaternion quat);
	UPRISE_ECS_API void SetPosition(Vector3 pos);
	/// <summary>
	/// updates the direction vectors of the gameobject (ip forward right)
	/// </summary>
	/// <returns></returns>
	UPRISE_ECS_API void UpdateDirections();
    UPRISE_CORE_API void OnDestroy()override;
	UPRISE_ECS_API void Update()override;
	UPRISE_ECS_API void Awake()override;
	UPRISE_ECS_API void Start()override;
    UPRISE_ECS_API RefWrapper<CORE::Behaviour, true> Copy()override;
    UPRISE_ECS_API RefWrapper<CORE::Behaviour, true> DeepCopy()override;
    UPRISE_ECS_API void EditorWindow()override;
#pragma endregion


};
#endif // !_Transform_
