// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include  "ECS/COMPONENTS/TRANSFORM/TRANSFORM.h";
void Transform::SetRotation(Vector3 vec)
{
    TrPr(ctx, __func__)
        vec3rot = vec;
    rotation = Quaternion::FromEulerAngles(vec);
    forward = rotation * Vector3(0, 0, 1);
    right = rotation * Vector3(1, 0, 0);
    up = rotation *Vector3(0, 1, 0); 
    TrPrE(ctx);
}

void Transform::SetRotation(Quaternion quat)
{
    TrPr(ctx, __func__)
        rotation = quat;
    auto o = quat.ToRotationVector();
    forward = rotation * Vector3(0, 0, 1);
    right = rotation * Vector3(1, 0, 0);
    up = rotation * Vector3(0, 1, 0); 
    TrPrE(ctx);

}

UPRISE_ECS_API void Transform::SetPosition(Vector3 pos)
{
    position = pos;
}
void Transform::UpdateDirections()
{
    TrPr(ctx, __func__)
        forward = rotation * Vector3(0, 0, 1);
    right = rotation * Vector3(1, 0, 0);
    up = rotation * Vector3(0, 1, 0); 
    TrPrE(ctx);
}

UPRISE_ECS_API void Transform::OnDestroy()
{
    return  void();
}

UPRISE_ECS_API RefWrapper<CORE::Behaviour, true> Transform::Copy()
{
    return  RefWrapper<CORE::Behaviour, true>();
}

UPRISE_ECS_API RefWrapper<CORE::Behaviour, true> Transform::DeepCopy()
{
    return  RefWrapper<CORE::Behaviour, true>();
}

UPRISE_ECS_API void Transform::EditorWindow()
{
}
UPRISE_ECS_API void Transform::Update(){}
UPRISE_ECS_API void Transform::Awake(){}
UPRISE_ECS_API void Transform::Start(){}