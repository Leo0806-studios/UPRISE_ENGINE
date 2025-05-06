#pragma once
#ifndef UE_GAMEOBJECT_INTERNAL_
#define UE_GAMEOBJECT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "OBJECT/OBJECT_INTERNAL.h"


#endif // 


namespace UPRISE_ENGINE {
    namespace CORE {
        class Behaviour;
    }
    class Transform;
    class Mesh;
    /// <summary>
    /// Gameobject class
    /// gameobjects are the objects that are in the scene
    /// components can be attatcht to gameobjects
    /// </summary>
    class GameObject :public Object {
    private:
        /// <summary>
        /// tag of the gameobject
        /// </summary>
        Tag tag;
        /// <summary>
        /// layer of the gameobject
        /// </summary>
        Layer layer;
        /// <summary>
        /// tha gameobjects transform
        /// </summary>
        SharedRef<Transform, true> transform;
        /// <summary>
        /// mesh of the gameobject
        /// cn be null
        /// </summary>
        SharedRef<Mesh, true> mesh;
        /// <summary>
        /// vector of all scripts attatched to the gameobject
        /// </summary>
        std::vector < WeakRef < CORE::Behaviour, true>> behaviours;

        GameObject(const GameObject& other) {
            tag = other.tag;
            layer = other.layer;
            transform = other.transform;
            mesh = other.mesh;
            behaviours = other.behaviours;
            this->SetEnabled(other.Enabled());
            mesh = other.mesh;
            transform = other.transform;
            this->SetName(other.Name());

        }
        GameObject operator=(const GameObject& other) {
            tag = other.tag;
            layer = other.layer;
            transform = other.transform;
            mesh = other.mesh;
            behaviours = other.behaviours;
            this->SetEnabled(other.Enabled());

            mesh = other.mesh;
            transform = other.transform;
            this->SetName(other.Name());

            return *this;
        }
    public:
#pragma region Constructors
        //default 

        /// <summary>
        /// default constructor
        /// </summary>
        GameObject() = default;
        /// <summary>
        /// copy constructor
        /// </summary>
        /// <param name="other"></param>




#pragma endregion
#pragma region  Destructors
        ~GameObject() {}

#pragma endregion
#pragma region Funcs
        UPRISE_ECS_API void OnDestroyInt(WeakRef<Object, true> obj) override;
        UPRISE_ECS_API SharedRef<Object, true> Copy() override;
        UPRISE_ECS_API SharedRef<Object, true> DeepCopy() override;
#pragma region Statics
        /// <summary>
        /// function to create a new gameobject from scratch
        /// 
        /// </summary>
        /// <param name="position"></param>
        /// <param name="Rotation"></param>
        /// <param name="mesh"></param>
        /// <param name="materialID"></param>
        /// <returns></returns>
        UPRISE_ECS_API static SharedRef<GameObject, true> Create(Vector3 position, Quaterion Rotation, SharedRef<Mesh, true> mesh);


#pragma endregion

#pragma endregion


    };
}
#endif