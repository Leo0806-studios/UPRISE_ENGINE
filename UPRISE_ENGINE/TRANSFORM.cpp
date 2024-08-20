#include "pch.h"
#include "TRANSFORM.h"

//DATATYPES::TS_P_Vector3 Position;
//DATATYPES::TS_P_Vector3 Rotation;;
GUID Transform::UUID = GUID_NULL;

void Transform::SetRotation(DATATYPES::TSPVector3 vec)
{
   TrPr(ctx, __func__)
    Vec3Rotation = vec;
    rotation = DATATYPES::Quaternion::FromEulerAngles(vec);
    forward = rotation*DATATYPES::TSPVector3(0,0,1);// rotation.Rotate(DATATYPES::TS_P_Vector3(0, 0, 1));
    right = rotation * DATATYPES::TSPVector3(1, 0, 0);// rotation.Rotate(DATATYPES::TS_P_Vector3(1, 0, 0));
    up = rotation * DATATYPES::TSPVector3(0, 1, 0); //rotation.Rotate(DATATYPES::TS_P_Vector3(0, 1, 0));
    //return DATATYPES::Quaternion();
    TrPrE(ctx);
}

void Transform::SetRotation(DATATYPES::Quaternion quat)
{
   TrPr(ctx, __func__)
    rotation = quat;
    auto o = quat.ToRotationVector();
    forward = rotation * DATATYPES::TSPVector3(0, 0, 1);// rotation.Rotate(DATATYPES::TS_P_Vector3(0, 0, 1));
    right = rotation * DATATYPES::TSPVector3(1, 0, 0);// rotation.Rotate(DATATYPES::TS_P_Vector3(1, 0, 0));
    up = rotation * DATATYPES::TSPVector3(0, 1, 0); //rotation.Rotate(DATATYPES::TS_P_Vector3(0, 1, 0));
    TrPrE(ctx);

}

void Transform::Update() {}

 void Transform::Awake() {}

 void Transform::Start() {}

 void Transform::UpdateDirections()
 {
    TrPr(ctx, __func__)
     forward = rotation * DATATYPES::TSPVector3(0, 0, 1);// rotation.Rotate(DATATYPES::TS_P_Vector3(0, 0, 1));
     right = rotation * DATATYPES::TSPVector3(1, 0, 0);// rotation.Rotate(DATATYPES::TS_P_Vector3(1, 0, 0));
     up = rotation * DATATYPES::TSPVector3(0, 1, 0); //rotation.Rotate(DATATYPES::TS_P_Vector3(0, 1, 0));
     TrPrE(ctx);
 }
