// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _PhysicsObject_
#define _PhysicsObject_
#include "CORE/BEHAVIOUR/BEHAVIOUR.h";
import REF_WRAPPER;
namespace PHYSICS {
	class PhysicsObjectInternal;
}
/// <summary>
/// physics object component
/// enables collision ,rigidbody and other physics related features
/// </summary>
class PhysicsObject : public CORE::Behaviour {
private:
	/// <summary>
    /// internal object
	/// </summary>
	RefWrapper< PHYSICS::PhysicsObjectInternal, true> object;
public:
	/// <summary>
    /// default constructor
	/// </summary>
	PhysicsObject() = default;
	~PhysicsObject(){}
	UPRISE_ECS_API void Awake()override;
	UPRISE_ECS_API void Update()override;
	UPRISE_ECS_API void Start()override;
};
#endif // !_PhysicsObject_
