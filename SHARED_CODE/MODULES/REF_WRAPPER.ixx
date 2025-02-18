// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
#include <atomic>

#define RW_DEBUG_LOGGING


    /*
    * Define RW_USE_CPP_EXCEPTIONS to use exceptions in SharedRef instead of error logging
    * Define RW_DEBUG_LOGGING to enable debug logging
    */
#ifdef RW_DEBUG_LOGGING
#define RW_DEBUG_LOG(x) std::cout << x << "\n";
#else
#define RW_DEBUG_LOG(x)
#endif // RW_DEBUG_LOGGING




    /// <summary>
    /// Nullable SharedRef
    /// Two versions of SharedRef exist one with null check and one without
    /// Common Behaviour:
    ///     Controllblock is null upon defaut construction
    ///     Controllblock is only deleted after all references are gone
    ///     Controllblock is null for a "moved from" object
    ///     Controllblock is not deleted when manualy deleting object
    ///     Controllblock internal pointer to obj is null upon default construction
    ///     Controllblock internal pointer to obj is deleted when object is deleted
    ///     Controllblock internal ref counters are atomicly incremented and decremented
    /// Nullchecked version:
    ///     Nullckeck upon get() if object is null it will throw a exception
    ///     Nullckeck upon operator-> if object is null it will throw a exception
    ///     Nullckeck upon operator= will log a warning if object is null in Debug mode
    ///     Nullckeck Move and Copy constructor will log a warning if object is null in Debug mode
    /// 
    /// Non-Nullchecked version:
    ///     No Nullckeck upon get() faster but insecure
    ///     No Nullckeck upon operator-> faster but insecure
    ///     No Nullckeck upon operator= faster but insecure
    ///     No Nullckeck Move and Copy constructor faster but insecure
    /// 
    /// A Nullckecked version can be converted to a Non-Nullchecked version but not the other way around
    /// both versions allow manual deletion of the object (dangerous with the non-nullchecked version)
    /// 
    /// 
    /// CreateSharedRef:
    ///     Creates a SharedRef with a new object
    ///     CreateSharedRef<T>() creates a SharedRef with a default constructed object
    ///     CreateSharedRef<T>(const T&&) creates a SharedRef with a moved object
    ///     WrapTef<T>(const T&) creates a SharedRef with a copied object
    /// 
    /// (now i have do rewrite the exisiting code to use this)(pain)
    ///     
    /// </summary>
    export module REF_WRAPPER;
import std; //-V2575 //-V3549

#pragma region Internals
    void* operator new(size_t count); //-V3549 //-V2575
    void operator delete(void* ptr); //-V3549 //-V2575

    namespace UPRISE_ENGINE {


#pragma region settingsAndMacros
#ifdef RW_USE_CPP_EXCEPTIONS
        constexpr bool RW_USE_CPP_EXCEPTIONS_ = true;
#else
        constexpr bool RW_USE_CPP_EXCEPTIONS_ = false;
#endif // RW_USE_CPP_EXCEPTIONS


#define NullChkFail(ExceptionText,LogText)\
                     if constexpr (RW_USE_CPP_EXCEPTIONS_)\
                    {\
                    throw std::exception(##ExceptionText);\
                    }\
                    else\
                    {\
                    std::cout << ##LogText << std::stacktrace::current() << "\n";\
                    }
#define TryGetVar(var,OnSuccses,OnFail)\
                    if(var)\
                    {\
                    OnSuccses;\
                    }\
                    else\
                    {\
                    OnFail;\
                    }
#pragma endregion


#pragma region ForwardDeclares
        template<class T, bool NC>  class SharedControllBlockGeneric;
        template <class T, bool NC> class SharedRef;
        template<class T> class OwnedControllBlock;
        template<class T> class OwnedRef;
        template<class T, bool NullChk> class WeakRef;
#pragma endregion


#pragma region ControllBase
        /// <summary>
     /// Base class for the controll block not templated so it can be used in a vector
     /// </summary>
        class controll_Base {
        private:
#pragma region Friends
            template<class T, bool NC> friend class SharedControllBlockGeneric;
            template<class T, bool NC> friend class SharedRef;
            template <class T> friend class OwnedControllBlock;
            template <class T> friend class OwnedRef;
            template<class T, bool NC> friend class WeakRef;
#pragma endregion
            unsigned long long _Refs = 1; ///initial ref count is 1 used for hardrefs (RefWrappers)
            unsigned long long _WeakRefs = 1; ///initial weak ref count is 1 used for weakrefs (WeakRefWrappers)
            /// <summary>
            /// atomicly increment the ref counter
            /// </summary>
            virtual void Incref() {
            }
            /// <summary>
            /// atomicly decrement the ref counter
            /// </summary>
            virtual void Decref() {
            }
            /// <summary>
            /// atomicly increment the weak ref counter
            /// </summary>
            virtual void Increwf() {};
            /// <summary>
            /// atomicly decrement the weak ref counter
            /// </summary>
            virtual void Decrewf() {};

        public:
            virtual void* get() { return nullptr; }; //returns ptr to the object. nullptr if not overriden or if objis null
            virtual void* _internalGET() { return nullptr; }; //returns ptr to the object. nullptr if not overriden or if objis null
        private:
            virtual void DeleteManualy() = 0; // method to delete the object manualy

        public:
            virtual ~controll_Base() = default; //virtual destructor
        };
#pragma endregion


#pragma region EmptyTemplates


        /// <summary>
        /// Base template for controll block. empty because everything is done in the nullckecked and non-nullckecked specializations
        /// </summary>
        /// <typeparam name="TY">Type of wich object should be managed</typeparam>
        /// <typeparam name="NullChk"> nullckeck</typeparam>
        template<class TY, bool NullChk>
        class SharedControllBlockGeneric :public controll_Base {
        private:
        };


        /// <summary>
        /// Base template for controll block. empty because everything is done in the nullckecked and non-nullckecked specializations
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        export template<class T, bool NullChk>
            class SharedRef {
            private:
        };


        /// <summary>
        /// Base Template for a WeakRef. empty because everything is done in the nullckecked and non-nullckecked specializations
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        export template<class T, bool NullChk>
            class WeakRef {
            private:
        };


#pragma endregion


#pragma region ControllBlocks

#pragma region OwnedControllBlocks
        /// <summary>
/// Controll Block for OwnedRef
/// </summary>
/// <typeparam name="T"></typeparam>
        template<class T>
        class OwnedControllBlock :public controll_Base {
        public:
            T* Obj{ nullptr };
            unsigned long long WeakRefs = 1;
            unsigned long long StrongRefs = 1;
            T* get() {
                return Obj;
            }
            void Destroy() {
                delete Obj;
                Obj = nullptr;
            }
            void Delete() {
                delete this;
            }
            void Incref() {
                StrongRefs++;
            }
            void Decref() {
                if (--StrongRefs == 0) {
                    Destroy();
                }
            }
            void Increwf() {
                WeakRefs++;
            }
            void Decrewf() {
                if (--WeakRefs == 0) {
                    Delete();
                }
            }
        };
#pragma endregion

#pragma region SharedControllBlocks


#pragma region SharedControllBlockGeneric


        /// <summary>
        /// Controll Block with nullckeck
        /// </summary>
        /// <typeparam name="T"></typeparam>
        template<class T>
        class SharedControllBlockGeneric<T, true> :public controll_Base {
        private:

            T* Obj{ nullptr };/// pointer to object. Null intialy
            template<class T, bool NC> friend class SharedRef; //friend to the SharedRef

        public:
            void* _internalGET()override {
                return Obj;
            }
            /// <summary>
            /// function to get pointer to the object. 
            /// if RW_USE_CPP_EXCEPTIONS_ is true it will throw a exception if the object is null
            /// otherwise it will return nullptr and log a warning and the stacktrace
            /// </summary>
            /// <returns>void* to obj</returns>
            void* get()override {

                if (Obj) {
                    return Obj;

                }
                else {
                    NullChkFail("Null Ref Exception", "\nNull Ref Exception at : ");
                }
                return nullptr;
            }
        private:
            /// <summary>
            /// Destroy the managed obj with nullckeck
            /// RW_USE_CPP_EXCEPTIONS_ is true it will throw a exception if the object is null otherwise it will log a warning and the stacktrace
            /// if _DEBUG is defined it will check if the pointer is valid before deleting (with _CrtIsValidHeapPointer)
            /// </summary>
            void Destroy() {
                //TryGetVar(Obj,
                //    TryGetVar(_CrtIsValidHeapPointer(Obj),
                //        delete Obj; Obj = nullptr;,
                //        NullChkFail("Nullckeck passed put pointer is invalid", "\n Nullckeck passed but pointer is invalid. pointer: " << Obj << " stacktrace: "); Obj = nullptr;
                //        ),
                //    NullChkFail("deleting null object", "\ndeleting null object at: " << Obj << "\n this can indicate a memory leak or a error upstream\n stacktrace: ")
                //    )
                if (Obj) {
#if _DEBUG
                    if (_CrtIsValidHeapPointer(Obj))
                        {delete Obj;}
                    else 
                        {NullChkFail("Nullckeck passed put pointer is invalid", "\n Nullckeck passed but pointer is invalid. pointer: " << Obj << " stacktrace: ");}
#else
                    delete Obj;
#endif



                    Obj = nullptr;


                }
                else { NullChkFail("deleting null object", "\ndeleting null object at: " << Obj << "\n this can indicate a memory leak or a error upstream\n stacktrace: "); }
            }
            /// <summary>
            /// Method to delete the controll block
            /// </summary>
            void Delete() { delete this; }
            /// <summary>
            /// atocmically increment the ref counter
            /// </summary>
            void Incref()override { _MT_INCR(_Refs); }
            /// <summary>
            /// atocmically decrement the ref counter
            /// </summary>
            void Decref()override {
                if (_MT_DECR(_Refs) == 0) {
                    Destroy();
                }
            }
            /// <summary>
            /// atocmically increment the weak ref counter
            /// </summary>
            void Increwf()override {
                _MT_INCR(_WeakRefs);
            }

            /// <summary>
            /// atocmically decrement the weak ref counter
            /// </summary>
            void Decrewf()override {
                if (_MT_DECR(_WeakRefs) == 0) {
                    Delete();
                }
            }

            /// <summary>
            /// Method for manual deletion of the object
            /// </summary>
            void DeleteManualy()override {
                if (Obj) {

                    delete Obj;
                    Obj = nullptr;
                }
                else {
                    if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                        throw std::exception("deleting null object");
                    }
                    else {
                        std::cout << "\ndeleting null object at: " << Obj << "\n this can indicate a memory leak or a error upstream\n stacktrace: \n" << std::stacktrace::current() << "\n";
                    }

                }
            }
        public:
            SharedControllBlockGeneric() {
                RW_DEBUG_LOG("creating controll block of type" << typeid(this).name());
                constexpr bool is_abstract = std::is_abstract<T>::value;
                if constexpr (is_abstract) {
                    Obj = nullptr;
                }
                else {
                    Obj = new T;

                }
            }
        };


        /// <summary>
        /// Non -Nullckecked version of the controll block
        /// </summary>
        /// <typeparam name="T"></typeparam>
        template<class T>
        class SharedControllBlockGeneric<T, false> :public controll_Base {
        private:
            T* Obj{ nullptr }; /// pointer to object. Null intialy
            template<class T, bool NC> friend class SharedRef;
        public:
            /// <summary>
            /// non-nullckecked version of get
            /// simply returns the pointer to the object
            /// </summary>
            /// <returns></returns>
            void* get()override {
                return Obj;
            }
        private:
            /// <summary>
            /// non-nullckecked version of destroy
            /// provides no protection against deleting the same object multiple times
            /// </summary>
            void Destroy() {
                delete Obj;

            }
            /// <summary>
            /// delete the controll block
            /// </summary>
            void Delete() {
                delete this;
            }
            /// <summary>
            /// atocmically increment the ref counter
            /// </summary>
            void Incref()override {
                _MT_INCR(_Refs);
            }
            /// <summary>
            /// atocmically decrement the ref counter
            /// </summary>
            void Decref()override {
                if (_MT_DECR(_Refs) == 0) {
                    Destroy();
                }
            }
            /// <summary>
            /// atocmically increment the weak ref counter
            /// </summary>
            void Increwf()override {
                _MT_INCR(_WeakRefs);
            }
            /// <summary>
            /// atocmically decrement the weak ref counter
            /// </summary>
            void Decrewf()override {
                if (_MT_DECR(_WeakRefs) == 0) {
                    Delete();
                }
            }
            /// <summary>
            /// non-nullckecked version of manual deletion
            /// provides no protection against deleting the same object multiple times it sets the pointer to null
            /// </summary>
            void DeleteManualy()override {
                delete Obj;
                Obj = nullptr;
            }
        public:
            SharedControllBlockGeneric() {

                Obj = new T;
            }
        };


#pragma endregion


#pragma endregion




#pragma endregion


#pragma region helper
        class passer {
        public:
            template <class T, bool NullChk>
            inline static void* IGet(const SharedRef<T, NullChk>& obj) {
                return obj.contrl->_internalGET();
            }
        };
#pragma endregion
    }


#pragma endregion




#pragma region Exports
    export namespace UPRISE_ENGINE {




#pragma region CreateRefs

    #pragma region CreateSharedRefs

        /// <summary>
        /// Creates a SharedRef with the value of a moved object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <param name="__val"></param>
        /// <returns></returns>
        template<class T, bool NullChk>
        SharedRef<T, NullChk> CreateSharedRef(const T&& __val) {
            if constexpr (std::is_abstract<T>::value) {
                static_assert(std::is_abstract<T>::value, "Cannot create a SharedRef of an abstract class");
            }
            controll_Base* base = new SharedControllBlockGeneric<T, NullChk>();
            SharedRef<T, NullChk> ret;
            ret.contrl = base;
            //memcpy(ret.Get(), &__val, sizeof(T));
            if constexpr (std::is_move_constructible<T>::value) {
                *((T*)passer::IGet(ret)) = __val;

            }
            else {
                *((T*)passer::IGet(ret)) = std::move(__val);

            }
            //ret.Get() = __val;
            return ret;
        }


        /// <summary>
        /// creates a SharedRef with a default constructed object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <returns></returns>
        template<class T, bool NullChk>
        SharedRef<T, NullChk> CreateSharedRef() {
            controll_Base* base = new SharedControllBlockGeneric<T, NullChk>();
            SharedRef<T, NullChk> ret;

            ret.contrl = base;
            return ret;
        }


        /// <summary>
        /// Creates a SharedRef with the value of a copied object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <param name="__val"></param>
        /// <returns></returns>
        template<class T, bool NullChk>
        SharedRef<T, NullChk> CreateSharedRef(const T& __val) {
            controll_Base* base = new SharedControllBlockGeneric<T, NullChk>();
            SharedRef<T, NullChk> ret;
            ret.contrl = base;
            memcpy(ret.Get(), &__val, sizeof(T));
            //ret.Get() = __val;
            return ret;
        }
    #pragma endregion


    #pragma region CreateOwnedRefs

        template <class T>
        OwnedRef<T> CreateOwnedRef() {
            OwnedControllBlock<T>* base = new OwnedControllBlock<T>();
            OwnedRef<T> ret;
            ret.ControllBlock = base;
            return ret;
        }


        template <class T>
        OwnedRef<T> CreateOwnedRef(const T&& __val) {
            OwnedControllBlock<T>* base = new OwnedControllBlock<T>();
            OwnedRef<T> ret;
            ret.ControllBlock = base;
            if constexpr (std::is_move_constructible<T>::value) {
                ret.ControllBlock->Obj = new T(std::move(__val));
            }
            else {
                ret.ControllBlock->Obj = new T(__val);
            }
            return ret;
        }


        template <class T>
        OwnedRef<T> CreateOwnedRef(const T& __val) {
            OwnedControllBlock<T>* base = new OwnedControllBlock<T>();
            OwnedRef<T> ret;
            ret.ControllBlock = base;
            ret.ControllBlock->Obj = new T(__val);
            return ret;
        }


    #pragma endregion


#pragma endregion


#pragma region WeakRefs

        template<class T>
        class WeakRef<T,true> {

            controll_Base* contrl{ nullptr };
        public:
            WeakRef() { RW_DEBUG_LOG("creating WeakRef of type" << typeid(this).name()); }
            WeakRef(const WeakRef<T, true>& other) {
                contrl = other.contrl;
                if (contrl) {
                    contrl->Increwf();
                }
                else {
                    NullChkFail("Null Ref Exception", "Null Ref Exception while coppying at : ");
                }
            }
            WeakRef(const WeakRef<T, true>&& other) {
                contrl = other.contrl;
                other.contrl = nullptr;
            }
            WeakRef& operator=(const WeakRef<T, true>& other) {
                contrl = other.contrl;
                if (contrl) {
                    contrl->Increwf();
                    return *this;
                }
                else {
                    NullChkFail("Null Ref Exception", "Null Ref Exception while assigning at : ");
                }
                return *this;
            }
            WeakRef& operator=(const WeakRef<T, true>&& other) {
                contrl = other.contrl;
                other.contrl = nullptr;
                return *this;
            }
            ~WeakRef() {
                if (contrl) {
                    contrl->Decrewf();
                }
                else {
                    NullChkFail("Null Ref Exception", "Null Ref Exception while deleting at : ");

                }
            }
            T* Get() {
                if (contrl) {
                    T* ret = (T*)contrl->get();
                    if(ret) {
                        
                        return ret;
                    }
                else {
                    NullChkFail("Null Ref Exception:", "Null Ref Exception  while getting at : ");
                }
                }
                else {
                    NullChkFail("Null Ref Exception: Control base is null", "Null Ref Exception with null Control block while getting at : ");
                }
                return nullptr;
            }

        };


        template<class T>
        class WeakRef<T, false> {
        };
#pragma endregion


#pragma region SharedRefs


        /// <summary>
        /// Nullckecked version of the SharedRef
        /// </summary>
        /// <typeparam name="T"></typeparam>
        template<class T>
        class SharedRef<T, true> {
        private:
            friend passer;
            template<class T, bool NC> friend class SharedControllBlockGeneric;
            template <class T, bool NC> friend SharedRef<T, true> CreateSharedRef(const T&& __val);
            template <class T, bool NC> friend SharedRef<T, true> CreateSharedRef(const T& __val);
            template <class T, bool NC> friend SharedRef<T, true> CreateSharedRef();
        public:
            controll_Base* contrl{ (controll_Base*)1 };/// pointer to the controll block. null+1 intialy
            SharedRef() { RW_DEBUG_LOG("creating SharedRef of type" << typeid(this).name()); }
            /// <summary>
            /// copy constructor 
            /// enabled for same type and base/derived types
            /// </summary>
            /// <typeparam name="T2"></typeparam>
            /// <typeparam name="type"></typeparam>
            /// <param name="other"></param>
            template<class T2>
            SharedRef(const SharedRef<T2, true>& other) {
                contrl = other.contrl;
                if (contrl && (((uintptr_t)contrl) != 1)) {
                    contrl->Incref();
                    contrl->Increwf();
                }
                else {
                    if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while coppying at : " << std::stacktrace::current() << "\n";
                    }
                }
            }


            /// <summary>
            /// copy constructor with own type. with nullckeck
            /// </summary>
            /// <param name="other"></param>
            SharedRef(const SharedRef<T, true>& other) {
                contrl = other.contrl;
                if (contrl) {
                    contrl->Incref();
                    contrl->Increwf();
                }
                else {
                    if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while coppying at : " << std::stacktrace::current();
                    }
                }
            }



            /// <summary>
            /// Destructor
            /// </summary>
            ~SharedRef() {
                if (((uintptr_t)contrl) == 1) {
                    return;
                }
                if (contrl) {
                    contrl->Decref();
                    contrl->Decrewf();
                }
                else {
                    if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while deleting at : " << std::stacktrace::current();
                    }
                }

            }
            void Destroy() {
                if (contrl) {
                    contrl->DeleteManualy();
                }
                else {
                    if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while deleting at : " << std::stacktrace::current();
                    }
                }
            }

            SharedRef& operator=(const SharedRef<T, true>& other) {
                this->contrl = other.contrl;
                if (contrl) {
                    contrl->Incref();
                    contrl->Increwf();
                    return  *this;
                }
                else {
                    if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while assigning at : " << std::stacktrace::current();
                    }
                }

                return *this;
            }

            template<class T2>
            SharedRef<T, true> operator=(const SharedRef<T2, true>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }

            //SharedRef<T, true> operator=(const T& other) {
            //	*(T*)contrl->get() = other;
            //}
            T* Get() {
                return (T*)contrl->get();
            }
            T* operator->() {
                return (T*)contrl->get();
            }
        };


        template<class T>
        class SharedRef<T, false> {
        private:
            //friend SharedRef<T, false> CreateSharedRef();
        public:
            controll_Base* contrl{ nullptr };

            SharedRef() = default;
            ~SharedRef() {
                // std::cout << "deleting wtihuout nullchk\n";
                contrl->Decref();
            }
            void Destroy() {
                contrl->DeleteManualy();
            }
            SharedRef<T, true> operator=(const SharedRef<T, true>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            SharedRef<T, false> operator=(const SharedRef<T, false>& other) {
                //contrl->Decref();
                //std::cout << "assigning\n";
                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            template<class T2>
            SharedRef<T, true> operator=(const SharedRef<T2, true>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            template<class T2>
            SharedRef<T, true> operator=(const SharedRef<T2, false>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            template<class T2>
            SharedRef(const SharedRef<T2, false>& other) {
                contrl = other.contrl;
                contrl->Incref();
            }
            SharedRef(const SharedRef<T, false>& other) {
                contrl = other.contrl;
                contrl->Incref();
            }
            //SharedRef<T, true> operator=(const T& other) {
            //	*(T*)contrl->get() = other;
            //}
            T* Get() {
                return (T*)contrl->get();
            }
            T* operator->() {
                return (T*)contrl->get();
            }
        };


#pragma endregion






#pragma region OwnedRefs
        /// <summary>
/// Base Template for a OwnedRef. 
///allways nullckecked
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="NullChk"></typeparam>
        template<class T>
        class OwnedRef {
        private:
            template<class T>
            friend OwnedRef<T> CreateOwnedRef(const T&& __val);
            OwnedControllBlock<T>* ControllBlock{ nullptr };

        public:
            OwnedRef() = default;
            OwnedRef(const OwnedRef<T>& other) = delete;
            template<class T2>
            OwnedRef(const OwnedRef<T2>& other) = delete;

            OwnedRef<T>& operator=(const OwnedRef<T>& other) = delete;
            OwnedRef(const OwnedRef<T>&& other) {
                ControllBlock = other.ControllBlock;
                other.ControllBlock = nullptr;
            }
            OwnedRef<T>& operator=(const OwnedRef<T>&& other) {
                ControllBlock = other.ControllBlock;
                other.ControllBlock = nullptr;
                return *this;
            }

        };
#pragma endregion
    }
#pragma endregion



