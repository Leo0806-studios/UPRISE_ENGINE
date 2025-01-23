// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
#include "atomic"

#define RW_DEBUG_LOGGING


/*
* Define RW_USE_CPP_EXCEPTIONS to use exceptions in RefWrapper instead of error logging
* Define RW_DEBUG_LOGGING to enable debug logging
*/
#ifdef RW_DEBUG_LOGGING
#define RW_DEBUG_LOG(x) std::cout << x << "\n";
#else
#define RW_DEBUG_LOG(x)
#endif // RW_DEBUG_LOGGING

#ifdef RW_USE_CPP_EXCEPTIONS
constexpr bool _RW_USE_CPP_EXCEPTIONS = true;
#else
constexpr bool _RW_USE_CPP_EXCEPTIONS = false;
#endif // RW_USE_CPP_EXCEPTIONS


/// <summary>
/// Nullable RefWrapper
/// Two versions of RefWrapper exist one with null check and one without
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
/// WrapRef:
///     Creates a RefWrapper with a new object
///     WrapRef<T>() creates a RefWrapper with a default constructed object
///     WrapRef<T>(const T&&) creates a RefWrapper with a moved object
///     WrapTef<T>(const T&) creates a RefWrapper with a copied object
/// 
/// (now i have do rewrite the exisiting code to use this)(pain)
///     
/// </summary>
export module REF_WRAPPER;
import std;


///Forward declarations

template<class T, bool NC>  class Controll_Block;
template <class T, bool NC> class RefWrapper;

/// <summary>
/// Base class for the controll block not templated so it can be used in a vector
/// </summary>
class controll_Base {
private:
   // bool null;//might not be neccesary if i do the nullckeck with nullptr
    template<class T, bool NC> friend class Controll_Block; //friend to the controll block
    template<class T, bool NC> friend class RefWrapper; //friend to the RefWrapper

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
};
/// <summary>
/// Base template for controll block. empty because everything is done in the nullckecked and non-nullckecked specializations
/// </summary>
/// <typeparam name="TY">Type of wich object should be managed</typeparam>
/// <typeparam name="NullChk"> nullckeck</typeparam>
template<class TY, bool NullChk>

class Controll_Block :public controll_Base {
private:
};

/// <summary>
/// Base template for controll block. empty because everything is done in the nullckecked and non-nullckecked specializations
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="NullChk"></typeparam>
export template<class T, bool NullChk>
class RefWrapper {
private:
};

/// <summary>
/// Controll Block with nullckeck
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class Controll_Block<T, true> :public controll_Base {
private:

    T* Obj{ nullptr };/// pointer to object. Null intialy
    template<class T, bool NC> friend class RefWrapper; //friend to the RefWrapper

public:
    void* _internalGET()override {
        return Obj;
    }
    /// <summary>
    /// function to get pointer to the object. 
    /// if _RW_USE_CPP_EXCEPTIONS is true it will throw a exception if the object is null
    /// otherwise it will return nullptr and log a warning and the stacktrace
    /// </summary>
    /// <returns>void* to obj</returns>
    void* get()override {

        if (Obj) {
            return Obj;

        }
        else {
            if constexpr (_RW_USE_CPP_EXCEPTIONS) {
                throw std::exception("Null Ref Exception");
            }
            else
            {
                std::cout << "\nNull Ref Exception at : " << std::stacktrace::current() << "\n";
            }
        }
        return nullptr;
    }
private:
    /// <summary>
    /// Destroy the managed obj with nullckeck
    /// _RW_USE_CPP_EXCEPTIONS is true it will throw a exception if the object is null otherwise it will log a warning and the stacktrace
    /// </summary>
    void Destroy() {
        //std::cout << "destroying " << Obj << "\n";
        if (Obj) {
            delete Obj; //delete the object
        }
        else {
            if constexpr (_RW_USE_CPP_EXCEPTIONS) {
                throw std::exception("deleting null object");
            }
            else {
                std::cout << "\ndeleting null object at: " << Obj << "\n this can indicate a memory leak or a error upstream\n stacktrace: " << std::stacktrace::current() << "\n";
            }

        }
    }
    /// <summary>
    /// Method to delete the controll block
    /// </summary>
    void Delete() {
        ///if(this) lol
        delete this;
    }

    /// <summary>
    /// atocmically increment the ref counter
    /// </summary>
    void Incref()override {
        //std::cout << "incref\n";
        //  std::cout << "old" << _Refs << "\n";
        _MT_INCR(_Refs);
        //  std::cout << "new" << _Refs << "\n";
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
    /// Method for manual deletion of the object
    /// </summary>
    void DeleteManualy()override {
        if (Obj) {

            delete Obj;
            Obj = nullptr;
        }
        else {
            if constexpr (_RW_USE_CPP_EXCEPTIONS) {
                throw std::exception("deleting null object");
            }
            else {
                std::cout << "\ndeleting null object at: " << Obj << "\n this can indicate a memory leak or a error upstream\n stacktrace: \n" << std::stacktrace::current() << "\n";
            }

        }
    }
    public:
        Controll_Block() {
            RW_DEBUG_LOG("creating controll block of type"<<typeid(this).name());
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
    class Controll_Block<T, false> :public controll_Base {
    private:
        T* Obj{ nullptr }; /// pointer to object. Null intialy
        template<class T, bool NC> friend class RefWrapper;
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
        Controll_Block() {

            Obj = new T;
        }
    };




    export {
    };
    class passer {
    public:
        template <class T, bool NullChk>
        inline static void* IGet(const RefWrapper<T, NullChk>& obj) {
            return obj.contrl->_internalGET();
        }
    };

    export{
        /// <summary>
        /// Creates a RefWrapper with the value of a moved object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <param name="__val"></param>
        /// <returns></returns>
        template<class T, bool NullChk>
        RefWrapper<T, NullChk> WrapRef(const T&& __val) {
            if constexpr (std::is_abstract<T>::value) {
                static_assert(std::is_abstract<T>::value, "Cannot create a RefWrapper of an abstract class");
            }
            controll_Base* base = new Controll_Block<T, NullChk>();
            RefWrapper<T, NullChk> ret;
            ret.contrl = base;
            //memcpy(ret.Get(), &__val, sizeof(T));
            *((T*)passer::IGet(ret)) = __val;
            //ret.Get() = __val;
            return ret;
        }
        /// <summary>
        /// creates a RefWrapper with a default constructed object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <returns></returns>
        template<class T, bool NullChk>
        RefWrapper<T, NullChk> WrapRef() {
            controll_Base* base = new Controll_Block<T, NullChk>();
            RefWrapper<T, NullChk> ret;

            ret.contrl = base;
            return ret;
        }

        /// <summary>
        /// Creates a RefWrapper with the value of a copied object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <param name="__val"></param>
        /// <returns></returns>
        template<class T, bool NullChk>
        RefWrapper<T, NullChk> WrapRef(const T& __val) {
            controll_Base* base = new Controll_Block<T, NullChk>();
            RefWrapper<T, NullChk> ret;
            ret.contrl = base;
            memcpy(ret.Get(), &__val, sizeof(T));
            //ret.Get() = __val;
            return ret;
        }



        /// <summary>
        /// Nullckecked version of the RefWrapper
        /// </summary>
        /// <typeparam name="T"></typeparam>
        template<class T>
        class RefWrapper<T, true> {
        private:

            friend passer;


        public:
            controll_Base* contrl{ (controll_Base*)1 };/// pointer to the controll block. null+1 intialy

            RefWrapper() {
                RW_DEBUG_LOG("creating RefWrapper of type" << typeid(this).name());

            }
            //template<class T2>
            //RefWrapper(const RefWrapper<T2, true>& other) {
            //    contrl = other.contrl;
            //    contrl->Incref();
            //}


            /// <summary>
            /// copy constructor 
            /// enabled for same type and base/derived types
            /// </summary>
            /// <typeparam name="T2"></typeparam>
            /// <typeparam name="type"></typeparam>
            /// <param name="other"></param>
            template<class T2, typename std::enable_if<std::is_convertible<T2*, T*>::value, int>::type = 0>
            RefWrapper(const RefWrapper<T2, true>& other) {
                contrl = other.contrl;
                if (contrl&&(((uintptr_t)contrl) !=1)) {
                    contrl->Incref();
                    contrl->Increwf();
                }
                else {
                    if constexpr (_RW_USE_CPP_EXCEPTIONS) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while coppying at : " << std::stacktrace::current() << "\n";
                    }
                }
            }
            //template<class T2>                                            invalid. cant convert from non-nullckecked to nullckecked
            //RefWrapper(const RefWrapper<T2, false>& other) {
            //    contrl = other.contrl;
            //    contrl->Incref();
            //}


            /// <summary>
            /// copy constructor with own type. with nullckeck
            /// </summary>
            /// <param name="other"></param>
            RefWrapper(const RefWrapper<T, true>& other) {
                contrl = other.contrl;
                if (contrl) {
                    contrl->Incref();
                    contrl->Increwf();
                }
                else {
                    if constexpr (_RW_USE_CPP_EXCEPTIONS) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while coppying at : " << std::stacktrace::current();
                    }
                }
            }
                //RefWrapper(const RefWrapper<T, false>& other) { //invalid. cant convert from non-nullckecked to nullckecked
            //    contrl = other.contrl;
            //    contrl->Incref();
            //}


            /// <summary>
            /// Destructor
            /// </summary>
            ~RefWrapper() {
                if (((uintptr_t)contrl) == 1) {
                    return;
                }
                if(contrl){
                    contrl->Decref();
                    contrl->Decrewf();
                }
                else{
                    if constexpr (_RW_USE_CPP_EXCEPTIONS) {
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
                    if constexpr (_RW_USE_CPP_EXCEPTIONS) {
                        throw std::exception("Null Ref Exception");
                    }
                    else
                    {
                        std::cout << "Null Ref Exception while deleting at : " << std::stacktrace::current();
                    }
                }
            }
            //RefWrapper<T, false> operator=(const RefWrapper<T, false>& other) { invalid. cant convert from non-nullckecked to nullckecked
            //    //contrl->Decref();
            //   // std::cout << "assigning\n";

            //    contrl = other.contrl;
            //    contrl->Incref();
            //    return*this;
            //}
            RefWrapper& operator=(const RefWrapper<T, true>& other) {
                this->contrl = other.contrl;
                if (contrl) {
                    contrl->Incref();
                    contrl->Increwf();
                    return  *this;
                }
                else {
                    if constexpr (_RW_USE_CPP_EXCEPTIONS) {
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
            RefWrapper<T, true> operator=(const RefWrapper<T2, true>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }

            //RefWrapper<T, true> operator=(const T& other) {
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
        class RefWrapper<T, false> {
        private:
            //friend RefWrapper<T, false> WrapRef();
        public:
            controll_Base* contrl{ nullptr };

            RefWrapper() = default;
            ~RefWrapper() {
                // std::cout << "deleting wtihuout nullchk\n";
                contrl->Decref();
            }
            void Destroy() {
                contrl->DeleteManualy();
            }
            RefWrapper<T, true> operator=(const RefWrapper<T, true>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            RefWrapper<T, false> operator=(const RefWrapper<T, false>& other) {
                //contrl->Decref();
                //std::cout << "assigning\n";
                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            template<class T2>
            RefWrapper<T, true> operator=(const RefWrapper<T2, true>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            template<class T2>
            RefWrapper<T, true> operator=(const RefWrapper<T2, false>& other) {
                //contrl->Decref();
               // std::cout << "assigning\n";

                contrl = other.contrl;
                contrl->Incref();
                return*this;
            }
            template<class T2>
            RefWrapper(const RefWrapper<T2, false>& other) {
                contrl = other.contrl;
                contrl->Incref();
            }
            RefWrapper(const RefWrapper<T, false>& other) {
                contrl = other.contrl;
                contrl->Incref();
            }
            //RefWrapper<T, true> operator=(const T& other) {
            //	*(T*)contrl->get() = other;
            //}
            T* Get() {
                return (T*)contrl->get();
            }
            T* operator->() {
                return (T*)contrl->get();
            }
        };
    }