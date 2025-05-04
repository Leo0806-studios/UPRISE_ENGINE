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
/// Values for internal object pointers:
///     nullptr: object is null
///     1: object is moved from
///     2: object is deleted manualy
///     3: object type is abstract and default constructed
/// Values for internal ControlBlock pointers:
///     nullptr: object is null
///     1: object is moved from
///     2: object is default constructed and has never had a value
/// 
/// 
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




#pragma region settingsAndMacros
#ifdef UPRISE_TESTS
    //#define RW_USE_CPP_EXCEPTIONS
#endif // UPRISE_TESTING

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
    template<typename T, typename = void>
    struct is_complete_Type :std::false_type {

    };
    template<typename T>
    struct is_complete_Type<T, std::void_t<decltype(sizeof(T))>> :std::true_type {
    };


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
        std::atomic<unsigned long long> _Refs; ///initial ref count is 1 used for hardrefs (RefWrappers) //-V2573
        std::atomic<unsigned long long> _WeakRefs; ///initial weak ref count is 1 used for weakrefs (WeakRefWrappers) //-V2573

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
        controll_Base(const controll_Base&) = delete; //deleted copy constructor
        controll_Base(controll_Base&&) = delete; //deleted move constructor
        controll_Base& operator=(const controll_Base&) = delete; //deleted copy assignment
        controll_Base& operator=(controll_Base&&) = delete; //deleted move assignment
        controll_Base() noexcept :
            _Refs(1),
            _WeakRefs(1) {
        } //default constructor
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
    class OwnedControllBlock final:public controll_Base {
        friend class CreatedRefs;

    public:
        T* Obj; //-V122

        OwnedControllBlock(const OwnedControllBlock&) = delete;
        OwnedControllBlock(OwnedControllBlock&&) = delete;
        OwnedControllBlock& operator=(const OwnedControllBlock&) = delete;
        OwnedControllBlock& operator=(OwnedControllBlock&&) = delete;
        unsigned long long WeakRefs;
        unsigned long long StrongRefs;
        __inline OwnedControllBlock() noexcept :Obj(new T()),WeakRefs(1), StrongRefs(1) { //-V2511
        }
        void* get() override final {
            switch (reinterpret_cast<unsigned long long>(Obj))
            {
                //null object
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception");
                }
                else {
                    std::cout << "\nNull Ref Exception at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
                    //moved from object
            case 1UL: {
                if constexpr(RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Object moved from");
                }
                else {
                    std::cout << "\nObject moved from at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
                    //object deleted manualy
            case 2UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Object deleted manualy");
                }
                else {
                    std::cout << "\nObject deleted manualy at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
                    //abstract object
            case 3UL: {
                break;
            }
                    //default
            default: {
                return Obj;
                break;
            }
            }
            return nullptr;
        }
        void Destroy() {
            delete Obj;
            Obj = nullptr;
        }
        void Delete() {
            delete this;
        }
        void Incref()override final {
            StrongRefs++;
        }
        void Decref()override final {
            if (--StrongRefs == 0) {
                Destroy();
            }
        }
        void Increwf()override final {
            WeakRefs++;
        }
        void Decrewf()override final {
            if (--WeakRefs == 0) {
                if(StrongRefs==0){
                    Delete();
                }
                
            }
        }

        // Inherited via controll_Base
        void DeleteManualy() override
        {
        }
        void* _internalGET() override {
            if (reinterpret_cast<unsigned long long>(Obj) < 30) {
                return nullptr;
            }
            return Obj;
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
    class SharedControllBlockGeneric<T, true>final :public controll_Base {
    private:

        T* Obj;/// pointer to object. Null intialy //-V122
        template<class T, bool NC> friend class SharedRef; //friend to the SharedRef

    public:
        void* _internalGET()override final {
            if (reinterpret_cast<unsigned long long>(Obj) < 30) {
                return nullptr;
            }
            return Obj;
        }
        /// <summary>
        /// function to get pointer to the object. 
        /// if RW_USE_CPP_EXCEPTIONS_ is true it will throw a exception if the object is null
        /// otherwise it will return nullptr and log a warning and the stacktrace
        /// </summary>
        /// <returns>void* to obj</returns>
        void* get()override final {

            switch (reinterpret_cast<unsigned long long>(Obj))
            {
                //null object
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception");
                }
                else {
                    std::cout << "\nNull Ref Exception at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
                    //moved from object
            case 1UL: {
                return nullptr;
                break;
            }
                    //object deleted manualy
            case 2UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Object deleted manualy");
                }
                else {
                    std::cout << "\nObject deleted manualy at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
                    //abstract object
            case 3UL: {
                break;
            }
                    //default
            default: {
                return Obj;
                break;
            }
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
            switch (reinterpret_cast<unsigned long long>(Obj)) {
                //null object
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception");
                }
                else {
                    std::cout << "\nNull Ref Exception at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
                    //moved from object
            case 1UL: {
                break;
            }
                    //object deleted manualy
            case 2UL: {
                //if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                //    throw std::exception("Object deleted manualy");
                //}
                //else {
                //    std::cout << "\nObject deleted manualy at : " << std::stacktrace::current() << "\n";
                //}
                break;
            }
                    //abstract object
            case 3UL: {
                break;
            }
                    //default
            default: {
#if _DEBUG
                if (_CrtIsValidHeapPointer(Obj))
                {
                    delete Obj;
                }
                else
                {
                    NullChkFail("Nullckeck passed put pointer is invalid", "\n Nullckeck passed but pointer is invalid. pointer: " << Obj << " stacktrace: ");
                }
#else
                delete Obj;
#endif

                break;
            }

            }
            Obj = nullptr;

        }
        /// <summary>
        /// Method to delete the controll block
        /// </summary>
        void Delete() { delete this; }
        /// <summary>
        /// atocmically increment the ref counter
        /// </summary>
        void Incref()override final { 
            _Refs++;
             }
        /// <summary>
        /// atocmically decrement the ref counter
        /// </summary>
        void Decref()override final {
            if ((_Refs--) == 0) {
                Destroy();
            }
        }
        /// <summary>
        /// atocmically increment the weak ref counter
        /// </summary>
        void Increwf()override final {
            _WeakRefs++;
        }
        /// <summary>
        /// atocmically decrement the weak ref counter
        /// </summary>
        void Decrewf()override final {
            if ((_WeakRefs--) == 0) {
                Delete();
            }
        }
        /// <summary>
        /// Method for manual deletion of the object
        /// </summary>
        void DeleteManualy()override final {
            if (Obj) {

                delete Obj;
                Obj = reinterpret_cast<T*>(2ULL); //-V566 //-V2571
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
        SharedControllBlockGeneric(const SharedControllBlockGeneric&) = delete; //deleted copy constructor
        SharedControllBlockGeneric(SharedControllBlockGeneric&&) = delete; //deleted move constructor
        SharedControllBlockGeneric& operator=(const SharedControllBlockGeneric&) = delete; //deleted copy assignment
        SharedControllBlockGeneric& operator=(SharedControllBlockGeneric&&) = delete; //deleted move assignment
        SharedControllBlockGeneric() :controll_Base(), Obj(nullptr) {
            RW_DEBUG_LOG("creating controll block of type" << typeid(this).name());
            constexpr bool is_abstract = std::is_abstract<T>::value;

            if constexpr (is_abstract) {
                Obj = reinterpret_cast<T*>(3ULL); //-V566 //-V2571
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
        T* Obj{ nullptr }; /// pointer to object. Null intialy //-V122
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
            (_Refs++);
        }
        /// <summary>
        /// atocmically decrement the ref counter
        /// </summary>
        void Decref()override {
            if ((_Refs--) == 0) {
                Destroy();
            }
        }
        /// <summary>
        /// atocmically increment the weak ref counter
        /// </summary>
        void Increwf()override {
            (_WeakRefs++);
        }
        /// <summary>
        /// atocmically decrement the weak ref counter
        /// </summary>
        void Decrewf()override {
            if ((_WeakRefs--) == 0) {
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
        SharedControllBlockGeneric() :controll_Base(), Obj{ new T } {

            //Obj = new T;
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



#pragma endregion




#pragma region Exports
export  {




#pragma region CreateRefs
    class CreateRefs {
    public:
#pragma region CreateSharedRefs

        /// <summary>
        /// Creates a SharedRef with the value of a moved object
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="NullChk"></typeparam>
        /// <param name="__val"></param>
        /// <returns></returns>
        template<class T, bool NullChk>
       static SharedRef<T, NullChk> CreateSharedRef(const T&& __val) {
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
        static  SharedRef<T, NullChk> CreateSharedRef() {
            controll_Base* base = new SharedControllBlockGeneric<T, NullChk>();
            SharedRef<T, NullChk> ret;

            ret.contrl = base;
            return ret;
        }



#pragma endregion


#pragma region CreateOwnedRefs

        template <class T>
       static  OwnedRef<T> CreateOwnedRef() {
            OwnedControllBlock<T>* base = new OwnedControllBlock<T>();
            OwnedRef<T> ret;
            ret.ControllBlock = base;
            return ret;
        }


        template <class T>
        static OwnedRef<T> CreateOwnedRef( T&& __val) {
            OwnedControllBlock<T>* base = new OwnedControllBlock<T>();
            OwnedRef<T> ret;
            ret.ControllBlock = base;
            if constexpr (std::is_move_constructible<T>::value) {
                base->Obj = new T(std::move(__val));
            }
            else {
                base->Obj= new T(__val);
            }
            ret.ControllBlock = base;
            return ret;
        }


        template <class T>
       static OwnedRef<T> CreateOwnedRef(const T& __val) {
            controll_Base* base = new OwnedControllBlock<T>();
            OwnedRef<T> ret;
            ret.ControllBlock = base;
            *ret.Get() = __val;
            return ret;
        }
    };

#pragma endregion


#pragma endregion


#pragma region WeakRefs

    template<class T>
    class WeakRef<T, true> {

        controll_Base* contrl;
        template <class  T, bool NC> friend class SharedRef;
        template<class T> friend class OwnedRef;
        template<class T, bool NC> friend class SharedControllBlockGeneric;
        template<class T, bool NT> friend class WeakRef;
    public:
        WeakRef() :contrl(nullptr) { RW_DEBUG_LOG("creating WeakRef of type" << typeid(this).name()); }
        WeakRef(const WeakRef<T, true>& other) :
            contrl(other.contrl)
        {
            if ((contrl)) {
                (contrl)->Increwf();
            }
            else {
                NullChkFail("Null Ref Exception", "Null Ref Exception while coppying at : ");
            }
        }
        WeakRef( WeakRef<T, true>&& other) :
            contrl(other.contrl)
        {
            other.contrl = nullptr;
        }
        template<class T2>
        WeakRef(const WeakRef<T2, true> other) {
            if (contrl) {
                contrl->Decrewf();
            }
            contrl = other.contrl;
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
        template <class T2>
        WeakRef& operator=(const WeakRef<T2, true> other) {
            if (contrl) {
                contrl->Decrewf();
            }
            contrl = other.contrl;
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
                if (ret) {

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
        T* operator->() {
            switch (reinterpret_cast<unsigned long long>(contrl))
            {
            case 0UL: {
                NullChkFail("Null Ref Exception", "Null Ref Exception while getting at : ");
                break;
            }
            case 1UL: {
                NullChkFail("Null Ref Exception! Other is moved from", "Null Ref Exception while getting at : other is moved from");
                break;
            }
            case 2UL: {
                NullChkFail("Null Ref Exception! Other is deleted manualy", "Null Ref Exception while getting at : other is deleted manualy");
                break;
            }
            default: {
                T* ret = (T*)contrl->get();
                if (ret) {
                    return ret;
                }
                else {
                    NullChkFail("Null Ref Exception:", "Null Ref Exception  while getting at : ");
                }
                break;
            }
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
        template<class T, bool NC> friend class OwnedControlBlock;
        friend class CreateRefs;
        controll_Base* contrl;/// pointer to the controll block. null+1 intialy //-V122
        template<class T, bool NC> friend class WeakRef;
        template<class T2, bool NC> friend class SharedRef;

    public:
        WeakRef<T, true> GetWeakRef() {
            WeakRef<T, true> ret;
            ret.contrl = contrl;
            return ret;
        }
        SharedRef() :
            contrl(reinterpret_cast<controll_Base*>(2)) //-V2571
        {
            RW_DEBUG_LOG("creating SharedRef of type" << typeid(this).name());
        }
        /// <summary>
        /// copy constructor 
        /// enabled for same type and base/derived types
        /// </summary>
        /// <typeparam name="T2"></typeparam>
        /// <typeparam name="type"></typeparam>
        /// <param name="other"></param>
        template<class T2>
        SharedRef(const SharedRef<T2, true>& other) :
            contrl(other.contrl)
        {
            switch (reinterpret_cast<unsigned long long>(contrl))
            {
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception");
                }
                else
                {
                    std::cout << "Null Ref Exception while coppying at : " << std::stacktrace::current() << "\n";
                }
                break;
            }
            case 1UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception! Other is moved from");
                }
                else
                {
                    std::cout << "Null Ref Exception while coppying at : " << std::stacktrace::current() << "\n other is moved from" << "\n";
                }
                break;
            }
            case 2UL: {
                break;
            }
            default: {
                contrl->Incref();
                contrl->Increwf();
                break;
            }
            }

        }


        /// <summary>
        /// copy constructor with own type. with nullckeck
        /// </summary>
        /// <param name="other"></param>
        SharedRef(const SharedRef<T, true>& other) :
            contrl(other.contrl)
        {
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
            switch (reinterpret_cast<unsigned long long>(contrl)) //-V2520
            {
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    //throw std::exception("Null Ref Exception"); dont throw on destruction (i wish i could)
                }
                else
                {
                    std::cout << "Null Ref Exception while deleting at : " << std::stacktrace::current();
                }
                break;
            }
            case 1UL: {
                __fallthrough;

            }
            case 2UL: {
                return;
            }
            default: {
                contrl->Decref();
                contrl->Decrewf();
                break;
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
            switch (reinterpret_cast<unsigned long long>(contrl))
            {
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception");
                }
                else
                {
                    std::cout << "Null Ref Exception while assigning at : " << std::stacktrace::current();
                }
                break;
            }
            case 1UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception! Other is moved from");
                }
                else
                {
                    std::cout << "Null Ref Exception while assigning at : " << std::stacktrace::current() << "\n other is moved from" << "\n";
                }
                break;
            }
            case 2UL: {
                break;
            }

            default:
            {
                contrl->Incref();
                contrl->Increwf();
                break;
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
            return static_cast<T*>(contrl->get()); //-V2571
        }
        T* operator->() {
            return static_cast<T*>(contrl->get()); //-V2571
        }
        __inline operator bool() {
            return static_cast<bool>(contrl->_internalGET());
        }
        bool operator==(const SharedRef<T, true>& other) = delete;
        bool operator!=(const SharedRef<T, true>& other) = delete;
        bool IsSame(const SharedRef<T, true>& other) {
            return contrl->get() == other.contrl->get();
        }
        bool IsSameValue(const SharedRef<T, true>& other) {
            return *static_cast<T*>(contrl->get()) == *static_cast<T*>(other.contrl->get()); //-V2571
        }
    };


    template<class T>
    class SharedRef<T, false> {
    private:
        friend passer;
        template<class T, bool NC> friend class SharedControllBlockGeneric;
        friend class CreateRefs;
        //friend SharedRef<T, false> CreateSharedRef();
        controll_Base* contrl{ nullptr }; //-V122

    public:

        WeakRef<T, false> GetWeakRef() {
            WeakRef<T, false> ret;
            ret.contrl = contrl;
            return ret;
        }

        SharedRef() :contrl(nullptr) {};
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
        SharedRef(const SharedRef<T2, false>& other) :
            contrl(other.contrl)
        {
            contrl = other.contrl;
            contrl->Incref();
        }
        SharedRef(const SharedRef<T, false>& other) :
            contrl(other.contrl)
        {
            contrl = other.contrl;
            contrl->Incref();
        }
        //SharedRef<T, true> operator=(const T& other) {
        //	*(T*)contrl->get() = other;
        //}
        T* Get() {
            return static_cast<T*>(contrl->get()); //-V2571
        }
        T* operator->() {
            return static_cast<T*>(contrl->get()); //-V2571
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
        friend CreateRefs;
        controll_Base* ControllBlock; //-V122
        friend class WeakRef<T, true>;
        template<class T2> friend class OwnedRef;

    public:
        WeakRef<T, true> GetWeakRef() {
            WeakRef<T, true> ret;
            ret.contrl = ControllBlock;
            ret.contrl->Increwf();
            return ret;
        }
        ~OwnedRef() {
            switch (reinterpret_cast<unsigned long long>(ControllBlock))
            {
            case 0UL: {
                if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                    throw std::exception("Null Ref Exception");
                }
                else
                {
                    std::cout << "Null Ref Exception while deleting at : " << std::stacktrace::current();
                }
                break;
            }
            case 1UL: {
                __fallthrough;
            }
            case 2UL: {
                return;
            }
            default: {
                ControllBlock->Decref();
                ControllBlock->Decrewf();
                break;
            }
            }
        }
        OwnedRef() :ControllBlock(reinterpret_cast<controll_Base*>(2ULL)) {}
        OwnedRef(const OwnedRef<T>& other) = delete;
        template<class T2>
        OwnedRef(const OwnedRef<T2>& other) = delete;

        OwnedRef<T>& operator=(const OwnedRef<T>& other) = delete;
        template<class T2>
        OwnedRef(OwnedRef<T2>&& other) {
            ControllBlock = other.ControllBlock;
            other.ControllBlock = reinterpret_cast<controll_Base*>(1ULL);
        }
        OwnedRef( OwnedRef<T>&& other) :
            ControllBlock(other.ControllBlock)
        {
            other.ControllBlock = reinterpret_cast<controll_Base*>(1ULL);
        }
        OwnedRef<T>& operator=( OwnedRef<T>&& other) {
            ControllBlock = other.ControllBlock;
            other.ControllBlock = reinterpret_cast<controll_Base*>(1ULL);
            return *this;
        }
        __inline operator bool() {
            return static_cast<bool>(ControllBlock->_internalGET());
       }
        T* Get() {
            return static_cast<T*>(ControllBlock->get()); //-V2571

        }
        T* operator->() {
            return static_cast<T*>(ControllBlock->get()); //-V2571
        } 
    };
#pragma endregion

}

#pragma endregion



