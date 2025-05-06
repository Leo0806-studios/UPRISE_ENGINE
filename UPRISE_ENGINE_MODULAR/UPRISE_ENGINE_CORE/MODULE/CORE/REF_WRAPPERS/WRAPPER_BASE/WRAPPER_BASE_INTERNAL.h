#pragma once
#ifndef WRAPPER_BASE_INTERNAL
#define WRAPPER_BASE_INTERNAL
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "string"
#include "iostream"
#include "stacktrace"
#include "REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE_INTERNAL.h"
#endif // __INTELLISENSE__



namespace UPRISE_ENGINE {

    class WrapperBase {
    private:

    protected:
        /// <summary>
/// possible values
/// 0 : null
/// 1 : object is moved from
/// 2 : default Constructed and never had a value
/// </summary>
        ControlBlock_Base* ControlBlock = reinterpret_cast<ControlBlock_Base*>(2ull);

        void NullSelf()noexcept {
            this->ControlBlock = nullptr;
        }
        static   void CaseMoved(const char* msg) {
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
        static  void CaseNull(const char* msg) {
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
        static  void CaseDeletedManualy(const char* msg) {
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
        static   void CaseDefaultConstructed(const char* msg) {
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
        /// depending on the value of RW_USE_CPP_EXCEPTIONS it either logs to a file and to the console or throws an exception
        /// </summary>
        /// <param name="msg"></param>
        static  void CaseSelfAsign(const char* msg) {
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
        static  void CaseInvalid(const char* msg) {
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
        inline void DecrementRefs()noexcept {
            ControlBlock->DecrementRefs();
        }
        inline void DecrementWeakRefs()noexcept {
            ControlBlock->DecrementWeakrefs();
        }

        inline void IncrementRefs()noexcept {
            ControlBlock->IncrementRefs();
        }
        inline void IncrementWeakRefs()noexcept {
            ControlBlock->IncrementWeakRefs();
        }
        inline void* _Get() {
            return ControlBlock->get();
        }
    };
}
#endif