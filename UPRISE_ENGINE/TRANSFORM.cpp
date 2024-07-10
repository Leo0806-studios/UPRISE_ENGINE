#include "TRANSFORM.h"

//DATATYPES::TS_P_Vector3 Position;
//DATATYPES::TS_P_Vector3 Rotation;;
GUID Transform::UUID = GUID_NULL;

void Transform::SetRotation(DATATYPES::TS_P_Vector3 vec)
{

    rotation = DATATYPES::Quaternion::FromEulerAngles(vec);
    forward = rotation*DATATYPES::TS_P_Vector3(0,0,1);// rotation.Rotate(DATATYPES::TS_P_Vector3(0, 0, 1));
    right = rotation * DATATYPES::TS_P_Vector3(1, 0, 0);// rotation.Rotate(DATATYPES::TS_P_Vector3(1, 0, 0));
    up = rotation * DATATYPES::TS_P_Vector3(0, 1, 0); //rotation.Rotate(DATATYPES::TS_P_Vector3(0, 1, 0));
    //return DATATYPES::Quaternion();
}

void Transform::SetRotation(DATATYPES::Quaternion quat)
{
    rotation = quat;
    auto o = quat.ToRotationVector();
    forward = rotation * DATATYPES::TS_P_Vector3(0, 0, 1);// rotation.Rotate(DATATYPES::TS_P_Vector3(0, 0, 1));
    right = rotation * DATATYPES::TS_P_Vector3(1, 0, 0);// rotation.Rotate(DATATYPES::TS_P_Vector3(1, 0, 0));
    up = rotation * DATATYPES::TS_P_Vector3(0, 1, 0); //rotation.Rotate(DATATYPES::TS_P_Vector3(0, 1, 0));

}

void Transform::Update() {}

 void Transform::Awake() {}

 void Transform::Start() {}

 void Transform::UpdateDirections()
 {
     forward = rotation * DATATYPES::TS_P_Vector3(0, 0, 1);// rotation.Rotate(DATATYPES::TS_P_Vector3(0, 0, 1));
     right = rotation * DATATYPES::TS_P_Vector3(1, 0, 0);// rotation.Rotate(DATATYPES::TS_P_Vector3(1, 0, 0));
     up = rotation * DATATYPES::TS_P_Vector3(0, 1, 0); //rotation.Rotate(DATATYPES::TS_P_Vector3(0, 1, 0));
 }
