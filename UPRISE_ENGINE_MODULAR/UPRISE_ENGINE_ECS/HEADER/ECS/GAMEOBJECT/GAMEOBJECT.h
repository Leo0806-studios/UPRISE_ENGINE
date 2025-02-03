// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_GameObject_
#define UE_GameObject_
#include "GLOBAL.h"
#include "GLOBAL/GLINCLUDES.h"
#include "CORE/OBJECT/OBJECT.h";
#include "DATATYPES/TAG/TAG.h";
#include "DATATYPES/LAYER/LAYER.h";
#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h";
#include "DATATYPES/QUTERION/QUATERION.h";
import std;
import REF_WRAPPER;
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
        RefWrapper<Transform, true> transform;
        /// <summary>
        /// mesh of the gameobject
        /// cn be null
        /// </summary>
        RefWrapper<Mesh, true> mesh;
        /// <summary>
        /// vector of all scripts attatched to the gameobject
        /// </summary>
        std::vector < RefWrapper < CORE::Behaviour, true>> behaviours;

        GameObject(const GameObject& other) {
            tag = other.tag;
            layer = other.layer;
            transform = other.transform;
            mesh = other.mesh;
            behaviours = other.behaviours;       
                this->Enabled() = (other.EnabledC());
                mesh = other.mesh;
                transform = other.transform;
                Name() = other.NameC();
            
        }
        GameObject operator=(const GameObject& other) {
            tag = other.tag;
            layer = other.layer;
            transform = other.transform;
            mesh = other.mesh;
            behaviours = other.behaviours;
            this->Enabled() = (other.EnabledC());
            mesh = other.mesh;
            transform = other.transform;
            Name() = other.NameC();
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
        UPRISE_ECS_API void OnDestroyInt(RefWrapper<CORE::Object, true> obj) override;
        UPRISE_ECS_API RefWrapper<CORE::Object,true> Copy() override;
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
        UPRISE_ECS_API static RefWrapper<GameObject, true> Create(Vector3 position, Quaternion Rotation, RefWrapper<Mesh, true> mesh, int materialID);


#pragma endregion

#pragma endregion


    };
}

#endif // !_GameObject_