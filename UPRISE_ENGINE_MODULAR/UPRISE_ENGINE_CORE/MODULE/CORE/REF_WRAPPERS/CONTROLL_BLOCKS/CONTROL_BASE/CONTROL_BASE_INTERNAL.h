#pragma once
#pragma once
#ifndef UE_CONTROL_BASE_INTERNAL_
#define UE_CONTROL_BASE_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <atomic>
#include <iostream>
#include <exception>
#include <string>
#include <stacktrace>
import UPRISE_ENGINE_DEBUG;
#endif
namespace UPRISE_ENGINE {
#ifdef RW_USE_CPP_EXCEPTIONS
    constexpr bool RW_USE_CPP_EXCEPTIONS_ = true;
#else 
    constexpr bool RW_USE_CPP_EXCEPTIONS_ = false;
#endif // RW_USE_CPP_EXCEPTIONS

    enum class RefState {
        Null = 0,
        Moved = 1,
        DefaultConstructed = 2,
        Valid = 3,
        Invalid = 4 //signifies thatthe ref is in some kind of invalid state only used in non nullchecked versions.

    };
    enum class ObjState {
        Null = 0,
        ManualyDeleted = 1,
        Valid = 2,
        Invalid = 3//signifies that the object pointed to is in some kind of invalid state.mainlyused in non nullchecked version but is used in checked version if controlblock is invalid
    };
    class ControlBlock_Base {
    private:
        template<class T, bool NC > friend class WeakRef;
        template<class T> friend class OwnedRef;
        friend class WrapperBase;

    protected:

        void CaseMoved(const char* msg) {
            if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                throw std::exception(out.c_str());
            }
            else {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                std::cout << out;
                DEBUG::Debug::Log(std::move(out));
            }
        }
        void CaseNull(const char* msg) {
            if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                throw std::exception(out.c_str());
            }
            else {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                std::cout << out;
                DEBUG::Debug::Log(std::move(out));
            }

        }
        void CaseDeletedManualy(const char* msg) {
            if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                throw std::exception(out.c_str());
            }
            else {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                std::cout << out;
                DEBUG::Debug::Log(std::move(out));

            }
        }


        /// <summary>
/// only fopr use in non nullchecked versions
/// </summary>
/// <param name="msg"></param>
        void CaseInvalid(const char* msg) {
            if constexpr (RW_USE_CPP_EXCEPTIONS_) {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                throw std::exception(out.c_str());
            }
            else {
                std::string out = msg;
                out += std::move(std::to_string(std::stacktrace::current()));
                out += '\n';
                std::cout << out;
                DEBUG::Debug::Log(std::move(out));
            }
        }
        std::atomic<unsigned long long> Refs = 1;
        std::atomic<unsigned long long> WeakRefs = 1;
        void Delete()noexcept {
            delete this; //linter false positive. this is part of a smart pointer implementation //-V2511
        }
        virtual void IncrementRefs()noexcept = 0;
        virtual void IncrementWeakRefs()noexcept = 0;
        virtual void DecrementRefs() noexcept = 0;
        virtual void DecrementWeakrefs()noexcept = 0;
        virtual void* get() = 0;
        virtual void DeleteManualy() = 0;
        virtual ObjState GetObjectState() = 0;
    public:
        ControlBlock_Base()noexcept = default;
        ControlBlock_Base(const ControlBlock_Base& other) = delete;
        ControlBlock_Base& operator=(const ControlBlock_Base& other) = delete;
        ControlBlock_Base(ControlBlock_Base&& other) = delete;
        ControlBlock_Base& operator=(ControlBlock_Base&& other) = delete;
        virtual ~ControlBlock_Base() = default;
    };




    constexpr inline unsigned long long MaxSpecialPointerVal = 20ULL;
}


#endif