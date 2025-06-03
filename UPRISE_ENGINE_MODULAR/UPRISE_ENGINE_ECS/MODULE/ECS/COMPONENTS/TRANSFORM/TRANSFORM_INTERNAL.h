#pragma once
#ifndef UE_TRANSFORM_INTERNAL_
#define UE_TRANSFORM_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "BEHAVIOUR/BEHAVIOUR_INTERNAL.h"
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    class Transform;

    /// <summary>
/// Transform component on Gameobjects
/// </summary>
    class Transform :public Behaviour {
    private:

        //template<class T, bool r>

        //friend SharedRef<T, r> CreateSharedRef<T, r>();
        
        /// <summary>
        /// position of the gameobject
        /// </summary>
        Vector3 position;
        /// <summary>
        /// rotation as quaterion
        /// </summary>
        Quaterion rotation;
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
        Transform(const Transform& other) {
            (void)other;
            UE_THROW_NOT_IMPLEMENTED; //TODO rework onwnership in ECS and deal with copy() and moves
        }
        Transform& operator=(const Transform& other) {
            (void)other;
            UE_THROW_NOT_IMPLEMENTED; //TODO rework onwnership in ECS and deal with copy() and moves
            return *this;
        }
#pragma endregion
#pragma region destructor
        ~Transform() = default;


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
        UPRISE_ECS_API void SetRotation(Quaterion quat);
        UPRISE_ECS_API void SetPosition(Vector3 pos);
        /// <summary>
        /// updates the direction vectors of the gameobject (ip forward right)
        /// </summary>
        /// <returns></returns>
        UPRISE_ECS_API void UpdateDirections();
        UPRISE_ECS_API void OnDestroy()override;
        UPRISE_ECS_API void Update()override;
        UPRISE_ECS_API void Awake()override;
        UPRISE_ECS_API void Start()override;
        UPRISE_ECS_API SharedRef<Object, true> Copy()override;
        UPRISE_ECS_API SharedRef<Object, true> DeepCopy()override;
        UPRISE_ECS_API void EditorWindow()override;
#pragma endregion


    };
}

#endif