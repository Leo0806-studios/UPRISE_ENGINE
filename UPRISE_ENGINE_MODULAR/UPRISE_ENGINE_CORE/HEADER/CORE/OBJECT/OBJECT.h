// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#ifndef UE_OBJECT_
#define UE_OBJECT_

//#include <string>

import REF_WRAPPER; //-V3549 //-V2575

import std; //-V3549 //-V2575


namespace UPRISE_ENGINE {
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
#pragma warning(disable:4514)
        /// <summary>
    /// Baseclass For nearly everything object related in the engine
    /// </summary>
        class  Object {
        private:
        protected:
            UPRISE_CORE_API Object(const Object& other);
            UPRISE_CORE_API Object(const Object& other, bool);
            UPRISE_CORE_API Object& operator=(const Object& other);
        private:
            std::string name;
            std::atomic<bool> enabled = true;
         
            char PAD[7];   //TODO find a better way to align this or find data to put here
            UPRISE_CORE_API  static   void destroyBehaviour(SharedRef<CORE::Behaviour, true> Object);
            UPRISE_CORE_API   static  void destroyComponent(SharedRef<CORE::Component, true> Object);
            UPRISE_CORE_API  static void destroyObject(SharedRef<CORE::Object, true> Object);

        public:
#pragma region Constuctors
            /// <summary>
            /// default constructor
            /// </summary>
            UPRISE_CORE_API   Object() = default;

#pragma endregion
#pragma region destructors
            /// <summary>
            /// virtual destructor to handle object destruction
            /// </summary>
            UPRISE_CORE_API   virtual ~Object() {}
#pragma endregion
#pragma region Functions
#pragma region OPERATORS
#pragma endregion

#pragma region statics
            /// <summary>
            /// function to destroy a CORE::Object or any derived class
            /// </summary>
            /// <typeparam name="T"></typeparam>
            /// <param name="Object"></param>
            /// <returns></returns>
            template<class T, typename = std::enable_if_t<std::is_same_v<T, CORE::Behaviour> || std::is_same_v<T, CORE::Component> || std::is_same_v<T, CORE::Object>>>
            __inline static bool Destroy(SharedRef<T, true> Object) {
                if constexpr (std::is_same_v<T, CORE::Behaviour>) {
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
            UPRISE_CORE_API   virtual  void OnDestroyInt(SharedRef<CORE::Object, true> obj) = 0;
            /// <summary>
            /// pure virtual base for copying the object
            /// </summary>
            UPRISE_CORE_API    virtual SharedRef<CORE::Object,true> Copy() = 0;
            UPRISE_CORE_API     virtual SharedRef<CORE::Object, true> DeepCopy() = 0;
            /// <summary>
            /// getter for the enable state of the object
            /// </summary>
            /// <returns></returns>
            __inline  bool Enabled() const{
                return enabled;
            }
            __inline bool SetEnabled(bool value) {
                enabled = value;
                return enabled;
            }
#pragma region  const
            /// <summary>
            /// getter for the name of the object
            /// returns the name of the object as a  const reference
            /// </summary>
            /// <returns></returns>
            __inline const std::string& Name()const {
                return name;
            }
            __inline  const std::string& SetName(const std::string& _name) {
                this->name = _name;
                return this->name;
            }

#pragma endregion

#pragma endregion
#pragma region virtuals
#pragma endregion

#pragma endregion



        };
#pragma warning(default:4514)
    };
}

 
#endif // !_OBJECT_ 
 