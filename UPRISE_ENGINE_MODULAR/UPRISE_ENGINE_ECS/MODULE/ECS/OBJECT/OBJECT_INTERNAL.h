#pragma once
#pragma once
#ifndef UE_OBJECT_INTERNAL_
#define UE_OBJECT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include <memory>
#include <string>
#include <vector>
#include <atomic>
#endif

#ifdef UPRISEENGINECORE_EXPORTS
#define UPRISE_CORE_API __declspec(dllexport)
#endif


namespace UPRISE_ENGINE {

    class GameObject;
    
        class Object;
        class Behaviour;
    
    class FunctionTransporter {
        friend class GameObject;
        friend class Object;
        friend class Behaviour;
    public:
        using RemoveComponent = void (*)(UPRISE_ENGINE::GameObject*, WeakRef<Object, true> comp);
    private:
        UPRISE_CORE_API static RemoveComponent RemoveBehaviourFromGameobject__internal; //-V3547
    };
        class Component;
        using SR_Object = SharedRef<Object, true>;
        using OR_Object = OwnedRef<Object>;
        using WR_Object = WeakRef<Object, true>;
        class  Object {
        private:
            UPRISE_CORE_API  static std::vector<WeakRef<Object, true>> ObjectsToBeDestroyedAtEndOfFrame;
        protected:
            UPRISE_CORE_API Object(const Object& other);
            UPRISE_CORE_API Object(const Object& other, bool);
            UPRISE_CORE_API Object& operator=(const Object& other);
            UPRISE_CORE_API   virtual  void OnDestroyInt(WeakRef<Object, true> obj) = 0;


        private:
            std::string name;
            std::atomic<bool> enabled;
            char PAD[7];   //TODO find a better way to align this or find data to put here //Linter false positive. this is intended padding
            UPRISE_CORE_API  static   void destroyBehaviour(WeakRef<Behaviour, true> Object);
            UPRISE_CORE_API   static  void destroyComponent(WeakRef<Component, true> Object);
            UPRISE_CORE_API  static void destroyObject(WeakRef<Object, true> Object);
        public:
            UPRISE_CORE_API   Object() :name(), enabled(true), PAD{ DEBUG_PAD_BITS_ZEROED } {}
            UPRISE_CORE_API   virtual ~Object() = default;
            UPRISE_CORE_API virtual bool operator== (const Object& other) const {
                return this->enabled == other.enabled && this->name == other.name;
            }
            UPRISE_CORE_API virtual bool operator!=(const Object& other) const {
                return this->enabled != other.enabled || this->name != other.name;
            }
            UPRISE_CORE_API    virtual SharedRef<Object, true> Copy() = 0;
            UPRISE_CORE_API     virtual SharedRef<Object, true> DeepCopy() = 0;
            __inline  bool Enabled() const {
                return enabled;
            }
            __inline bool SetEnabled(bool value) {
                enabled = value;
                return enabled;
            }
            __inline const std::string& Name()const {
                return name;
            }
            __inline  const std::string& SetName(const std::string& _name) {
                this->name = _name;
                return this->name;
            }
            /// <summary>
            /// Dont Call in user code
            /// </summary>
            UPRISE_CORE_API static void AfterFrameDestroy();
            template<typename T>
            static void Destroy(WeakRef<T, true> Obj) {
                if constexpr (std::is_same_v<T, Behaviour> ||
                    std::is_convertible_v<T, Behaviour>
                    ) {
                    WeakRef<Behaviour, true> AsBehaviour = Obj;
                    destroyBehaviour(AsBehaviour);
                }
                else if constexpr (std::is_same_v<T, Component> ||
                    std::is_convertible_v<T, Component>
                    ) {
                    WeakRef<Component, true> AsComponent = Obj;
                    destroyComponent(AsComponent);
                }
                else if constexpr (std::is_same_v<T, Object>) { //-V2516 //-V3511
                    WeakRef<Object, true> AsObject = Obj;
                    destroyObject(AsObject);
                }
            }
        };
}


#endif