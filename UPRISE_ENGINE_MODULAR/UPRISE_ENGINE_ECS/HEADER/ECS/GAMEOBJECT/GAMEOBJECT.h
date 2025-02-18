// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_GameObject_
#define UE_GameObject_
#include <GLOBAL/GLINCLUDES.h>
#include "CORE/OBJECT/OBJECT.h"
#include "DATATYPES/TAG/TAG.h"
#include "DATATYPES/LAYER/LAYER.h"
#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "DATATYPES/QUTERION/QUATERION.h"
import std;
import REF_WRAPPER;
#pragma warning(disable: 4514)
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
    class GameObject :public CORE::Object {
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
        std::vector < SharedRef < CORE::Behaviour, true>> behaviours;

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
        UPRISE_ECS_API void OnDestroyInt(SharedRef<CORE::Object, true> obj) override;
        UPRISE_ECS_API SharedRef<CORE::Object,true> Copy() override;
        UPRISE_ECS_API SharedRef<CORE::Object, true> DeepCopy() override;
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
        UPRISE_ECS_API static SharedRef<GameObject, true> Create(Vector3 position, Quaternion Rotation, SharedRef<Mesh, true> mesh);


#pragma endregion

#pragma endregion


    };
}
#pragma warning(default:4514)
#endif // !_GameObject_