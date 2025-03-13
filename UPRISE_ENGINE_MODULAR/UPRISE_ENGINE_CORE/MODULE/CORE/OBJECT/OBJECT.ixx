export module UPRISE_ENGINE_CORE:OBJECT;
import std;
import REF_WRAPPER;
#pragma warning(push)
#pragma warning(disable:4514)
export namespace UPRISE_ENGINE {
    
        class GameObject;
    
    namespace CORE {
        class Behaviour;
        class Component;
        class Object;
        using SR_Object = SharedRef<CORE::Object, true>;
        using OR_Object = OwnedRef<CORE::Object>;
        using WR_Object = WeakRef<CORE::Object, true>;
        class  Object {
        private:
            /// <summary>
            /// wss
            /// </summary>
            UPRISE_CORE_API  MockableStaticVar(ObjectsToBeDestroyedAtEndOfFrame,std::vector<WeakRef<CORE::Object,true>>)
        protected:
            UPRISE_CORE_API Object(const Object& other);
            UPRISE_CORE_API Object(const Object& other, bool);
            UPRISE_CORE_API Object& operator=(const Object& other);
            UPRISE_CORE_API   virtual  void OnDestroyInt(WeakRef<CORE::Object, true> obj) = 0;
/*            /// <summary>
            /// DO NOT OVERRIDE EXCEPT IN class GameObject
            /// its only here as a solution to a architectural problem
            /// </summary>
            UPRISE_CORE_API virtual void Gamobject_Internal_Component_Remove() = 0;
                 */       
            typedef void(* RemoveComponent)(UPRISE_ENGINE::GameObject*,WeakRef<CORE::Object, true> comp);
            UPRISE_CORE_API MockableStaticVar(RemoveBehaviourFromGameobject__internal, RemoveComponent)
        private:
            std::string name;
            std::atomic<bool> enabled;
            char PAD[7];   //TODO find a better way to align this or find data to put here
            UPRISE_CORE_API  static   void destroyBehaviour(WeakRef<CORE::Behaviour, true> Object);
            UPRISE_CORE_API   static  void destroyComponent(WeakRef<CORE::Component, true> Object);
            UPRISE_CORE_API  static void destroyObject(WeakRef<CORE::Object, true> Object);
        public:
            UPRISE_CORE_API   Object() :name(), enabled(true), PAD{ DEBUG_PAD_BITS_ZEROED } {}
            UPRISE_CORE_API   virtual ~Object() {}
            UPRISE_CORE_API virtual bool operator== (const Object& other) const {
                return this->enabled == other.enabled && this->name == other.name;
            }
            UPRISE_CORE_API virtual bool operator!=(const Object& other) const {
                return this->enabled != other.enabled || this->name != other.name;
            }
            UPRISE_CORE_API    virtual SharedRef<CORE::Object, true> Copy() = 0;
            UPRISE_CORE_API     virtual SharedRef<CORE::Object, true> DeepCopy() = 0;
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
            UPRISE_CORE_API static void Destroy(WeakRef<T,true> Obj) {
                if constexpr (std::is_same_v<T, CORE::Behaviour>||
                    std::is_convertible_v<T, CORE::Behaviour>
                    ) {
                    WeakRef<CORE::Behaviour, true> AsBehaviour = Obj;
                    destroyBehaviour(AsBehaviour);
                }
                else if constexpr (std::is_same_v<T, CORE::Component>||
                    std::is_convertible_v<T, CORE::Component>
                    ) {
                    WeakRef<CORE::Component, true> AsComponent = Obj;
                    destroyComponent(AsComponent);
                }
                else if constexpr (std::is_same_v<T, CORE::Object>) {
                    WeakRef<CORE::Object, true> AsObject = Obj;
                    destroyObject(AsObject);
                }
            }
        };
    }
}
#pragma warning(pop)