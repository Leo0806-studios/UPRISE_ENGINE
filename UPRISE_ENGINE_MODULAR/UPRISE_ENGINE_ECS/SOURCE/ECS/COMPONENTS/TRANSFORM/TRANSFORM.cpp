// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "DATATYPES/QUTERION/QUATERION.h"
#include  "ECS/COMPONENTS/TRANSFORM/TRANSFORM.h"
namespace UPRISE_ENGINE {
    Vector3& Transform::Position()
    {
        return this->position;
    }
    const Vector3& Transform::Forward()
    {
        return this->forward;
    }
    const Vector3& Transform::Up()
    {
        return this->up;
    }
    const Vector3& Transform::Right()
    {
        return this->right;
    }
    void Transform::SetRotation(Vector3 vec)
    {
            vec3rot = vec;
        rotation = Quaterion::FromEulerAngles(vec);
        forward = rotation * Vector3(0.0F, 0.0F, 1.0F);
        right = rotation * Vector3(1.0F, 0.0F, 0.0F);
        up = rotation * Vector3(0.0F, 1.0F, 0.0F);
    }

    void Transform::SetRotation(Quaterion quat)
    {
            rotation = quat;
        auto o = quat.ToRotationVector();
        forward = rotation * Vector3(0.0F, 0.0F, 1.0F);
        right = rotation * Vector3(1.0F, 0.0F, 0.0F);
        up = rotation * Vector3(0.0F, 1.0F, 0.0F);

    }

    UPRISE_ECS_API void Transform::SetPosition(Vector3 pos)
    {
        position = pos;
    }
    void Transform::UpdateDirections()
    {
            forward = rotation * Vector3(0.0F, 0.0F, 1.0F);
        right = rotation * Vector3(1.0F, 0.0F, 0.0F);
        up = rotation * Vector3(0.0F, 1.0F, 0.0F);
    }

    UPRISE_ECS_API void Transform::OnDestroy()
    {
        return  void();
    }

    UPRISE_ECS_API SharedRef<CORE::Object, true> Transform::Copy()
    {

        SharedRef<CORE::Object,true> ret = CreateRefs::CreateSharedRef<Transform, true>((Transform(*this)));
        return ret;
    }

    SharedRef<CORE::Object, true> Transform::DeepCopy()
    {
        auto ret = CreateRefs::CreateSharedRef<Transform, true>(Transform(*this,true));
        return ret;
    }



    UPRISE_ECS_API void Transform::EditorWindow()
    {
    }
    UPRISE_ECS_API void Transform::Update() {}
    UPRISE_ECS_API void Transform::Awake() {}
    UPRISE_ECS_API void Transform::Start() {}
}
