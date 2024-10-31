#pragma once

#ifndef _OBJECT_
#define _OBJECT_

#include <string>

import REF_WRAPPER;

import std;
//UPRISE_CORE_API_EXPORTS namespace CORE {
//    class Behaviour;
//    class Component;
//};
/// <summary>
/// Namespace for core functionality
/// </summary>
 namespace CORE {
    /// <summary>
/// Baseclass For nearly everything object related in the engine
/// </summary>
    class Object {
    private:
        std::string name;
        bool enabled = true;
    public:
#pragma region Constuctors
        /// <summary>
        /// default constructor
        /// </summary>
        Object() = default;

#pragma endregion
#pragma region destructors
        /// <summary>
        /// virtual destructor to handle object destruction
        /// </summary>
        virtual ~Object() {}
#pragma endregion
#pragma region Functions
#pragma region statics
        /// <summary>
        /// function to destroy a CORE::Object or any derived class
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="Object"></param>
        /// <returns></returns>
        template<class T>
        UPRISE_CORE_API	__inline static bool Destroy(RefWrapper<T, true> Object);


#pragma endregion
#pragma region Members
        /// <summary>
        /// internal base virtual function for object destruction
        /// </summary>
        
        virtual UPRISE_CORE_API void OnDestroyInt(RefWrapper<CORE::Object,true> obj) = 0;
        /// <summary>
        /// getter for the name of the object
        /// returns the name of the object as a non const reference
        /// </summary>
        /// <returns></returns>
        UPRISE_CORE_API __inline std::string& Name() {
            return name;
        }
        /// <summary>
        /// getter for the enable state of the object
        /// returns a non const reference to the enabled state of the object
        /// </summary>
        /// <returns></returns>
        UPRISE_CORE_API __inline  bool& Enabled() {
            return enabled;
        }
        __inline bool& SetEnabled(bool value) {
            enabled = value;
            return enabled;
        }
#pragma region  const
        /// <summary>
        /// getter for the name of the object
        /// returns the name of the object as a  const reference
        /// </summary>
        /// <returns></returns>
        UPRISE_CORE_API __inline const std::string& NameC()const {
            return name;
        }
        /// <summary>
    /// getter for the enable state of the object
    /// returns a  const reference to the enabled state of the object
    /// </summary>
    /// <returns></returns>
        UPRISE_CORE_API __inline const bool& EnabledC() const {
            return enabled;
        }
#pragma endregion

#pragma endregion
#pragma region virtuals
#pragma endregion

#pragma endregion



    };
}

#endif // !_OBJECT_
