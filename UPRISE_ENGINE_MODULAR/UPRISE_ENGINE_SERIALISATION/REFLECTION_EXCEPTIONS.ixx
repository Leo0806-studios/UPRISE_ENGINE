module;
#include    <IMPORT_DEFS.h>
export module UE_SERIALISATION:REFLECTION_EXCEPTIONS;
import std;
export namespace UPRISE_ENGINE::SERIALISATION {
    enum class MemberType {
        Constructor,
        Function,
        Member
    };
    class ReflectionException : public std::exception {
    public:
        UPRISE_SERIALISATION_API explicit ReflectionException(std::string message) : msg(std::move(message)) {}
        UPRISE_SERIALISATION_API const char* what() const noexcept override {
            return msg.c_str();
        }
    private:
        std::string msg;
    };
    class TypeNotFoundException : public ReflectionException {
    public:
        UPRISE_SERIALISATION_API  explicit TypeNotFoundException(std::string message) : ReflectionException(std::move(message)) {}
    };
    class MemberNotFoundException : public ReflectionException {
    public:
        UPRISE_SERIALISATION_API explicit MemberNotFoundException(std::string message, MemberType type) : ReflectionException(std::format("{} (Member Type: {})", message, static_cast<int>(type))) {}
        
    };
    class MismatchedTypeException : public ReflectionException {
    public:
        UPRISE_SERIALISATION_API  explicit MismatchedTypeException(std::string message) : ReflectionException(std::move(message)) {}
    };
    class AlignmentException : public ReflectionException {
    public:
        UPRISE_SERIALISATION_API explicit AlignmentException(std::string message) : ReflectionException(std::move(message)) {}
    };
}