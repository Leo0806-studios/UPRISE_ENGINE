// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#ifndef _OBJECT_
#define _OBJECT_

//#include <string>

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
    class Behaviour;
    class Component;
    /// <summary>
/// Baseclass For nearly everything object related in the engine
/// </summary>
      class UPRISE_CORE_API Object {
    private:
        std::string name;
        bool enabled = true;
          static  void destroyBehaviour(RefWrapper<CORE::Behaviour, true> Object);
          static  void destroyComponent(RefWrapper<CORE::Component, true> Object);
          static void destroyObject(RefWrapper<CORE::Object, true> Object);

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
        template<class T, typename = std::enable_if_t<std::is_same_v<T, CORE::Behaviour> || std::is_same_v<T, CORE::Component> || std::is_same_v<T, CORE::Object>>>
        __inline static bool Destroy(RefWrapper<T, true> Object) {
            if constexpr(std::is_same_v<T, CORE::Behaviour>) {
                destroyBehaviour(Object);
                return true;
            }
            else if constexpr (std::is_same_v<T, CORE::Component>) {
                destroyComponent(Object);
                return true;
            }
            else {
                destroyObject(Object);
                return true;
            }
        }


#pragma endregion
#pragma region Members
        /// <summary>
        /// internal base virtual function for object destruction
        /// </summary>

        virtual  void OnDestroyInt(RefWrapper<CORE::Object, true> obj) = 0;
        /// <summary>
        /// getter for the name of the object
        /// returns the name of the object as a non const reference
        /// </summary>
        /// <returns></returns>
         __inline std::string& Name() {
            return name;
        }
        /// <summary>
        /// getter for the enable state of the object
        /// returns a non const reference to the enabled state of the object
        /// </summary>
        /// <returns></returns>
         __inline  bool& Enabled() {
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
         __inline const std::string& NameC()const {
            return name;
        }
        /// <summary>
    /// getter for the enable state of the object
    /// returns a  const reference to the enabled state of the object
    /// </summary>
    /// <returns></returns>
         __inline const bool& EnabledC() const {
            return enabled;
        }
#pragma endregion

#pragma endregion
#pragma region virtuals
#pragma endregion

#pragma endregion



    };
};
 
#endif // !_OBJECT_ 
 