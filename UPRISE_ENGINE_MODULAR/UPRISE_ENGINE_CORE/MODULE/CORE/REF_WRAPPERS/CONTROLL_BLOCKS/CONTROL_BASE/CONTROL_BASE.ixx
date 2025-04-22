// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module UPRISE_ENGINE_CORE:CONTROL_BASE;
import <atomic>;
import <iostream>;
import <exception>;
import <string>;
import <stacktrace>;
import UPRISE_ENGINE_DEBUG;
export namespace UPRISE_ENGINE {
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
        Invalid = 4 //only used in non nullchecked versions

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
        std::atomic<unsigned long long> Refs = 1;
        std::atomic<unsigned long long> WeakRefs = 1;
        void Delete()noexcept {
            delete this; //-V2511
        }
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
 



    constexpr inline unsigned long long MaxSpecialPointerVal = 20ULL;
}