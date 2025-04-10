#pragma once
#ifndef UE_CONTROL_BASE_
#define UE_CONTROL_BASE_
#ifndef CORE_MODULE_BUILD
import std;
#endif
namespace UPRISE_ENGINE {
    class ControlBlock_Base {
    private:
        template<class T, bool NC > friend class WeakRef;
//#ifdef __INTELLISENSE__
  //  public:
//#else
    protected:
//#endif // __INTELLISENSE__

        std::atomic<unsigned long long> Refs = 1;
        std::atomic<unsigned long long> WeakRefs = 1;
        virtual void IncrementRefs()noexcept = 0;
        virtual void IncrementWeakRefs()noexcept = 0;
        virtual void DecrementRefs() noexcept = 0;
        virtual void DecrementWeakrefs()noexcept = 0;
        virtual void* get() = 0;
        virtual void DeleteManualy() = 0;
    public:
        ControlBlock_Base()noexcept = default;
        ControlBlock_Base(const ControlBlock_Base& other) = delete;
        ControlBlock_Base& operator=(const ControlBlock_Base& other) = delete;
        ControlBlock_Base(ControlBlock_Base&& other) = delete;
        ControlBlock_Base& operator=(ControlBlock_Base&& other) = delete;
        virtual ~ControlBlock_Base() = default;
    };
    template<size_t TypeSize>
    class EmptySizeClass {
        char filler[TypeSize];
    };
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
    constexpr unsigned long long MaxSpecialPointerVal = 20ULL;
}

#endif 