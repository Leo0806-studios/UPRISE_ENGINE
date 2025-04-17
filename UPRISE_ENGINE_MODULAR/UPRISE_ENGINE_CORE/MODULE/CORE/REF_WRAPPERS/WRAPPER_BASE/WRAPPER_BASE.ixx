export module UPRISE_ENGINE_CORE:WRAPPER_BASE;
import :CONTROL_BASE;
import <string>;
import <iostream>;
import <stacktrace>;
import UPRISE_ENGINE_DEBUG;
export namespace UPRISE_ENGINE {
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

        void NullSelf() {
            this->ControlBlock = nullptr;
        }
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
        void CaseDefaultConstructed(const char* msg) {
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
        void CaseSelfAsign(const char* msg) {
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



        template<bool null = true,
            bool mooved = true,
            bool defaultConstructed = true,
            typename SucsessFunction,
            typename = std::enable_if<std::is_function_v<SucsessFunction>>>
        void ControlBlockPreAssignCheck() {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                if constexpr (null) {
                    CaseNull("ControlBlock of \" this\" was null while trying to move assign from other. (function sig: WeakRef& operator=(WeakRef<Type, true>&& other) ");
                }
                break;
            }
            case 1: {
                if constexpr (mooved) {
                    CaseMoved("trying to copy a moved from object (func sig : WeakRef(const WeakRef<Type, true>& other)noexcept )");
                }
                break;
            }
            case 2: {
                if constexpr (defaultConstructed) {
                    if constexpr (WarningLevel >= 3) {
                        CaseDefaultConstructed("while it is legal to copy construct from a default constructed object this may indicate an error in the program");
                    }
                }
                break;
            }
            default: {
                ///assume that all other values are valid
                SucsessFunction();
                break;
            }
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

        template<
            bool null = true,
            bool mooved = true,
            bool defaultConstructed = true,
            void(*SuccsesFunction)() = nullptr>
        void  Nullcheck(const char* msgNull, const char* const msgMoved, const char* const msgDefaultConstructed) {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                if constexpr (null) {
                    CaseNull(msgNull);
                }
                break;
            }
            case 1: {
                if constexpr (mooved) {
                    CaseMoved(msgMoved);
                }
                break;
            }
            case 2: {
                if constexpr (defaultConstructed) {
                    if constexpr (WarningLevel >= 3) {
                        CaseDefaultConstructed(msgDefaultConstructed);
                    }
                }
                break;
            }
            default: {
                SuccsesFunction();
                break;
            }
            }
        }

    };
}