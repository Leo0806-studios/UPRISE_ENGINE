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
        explicit ReflectionException(std::string message) : msg(std::move(message)) {}
        const char* what() const noexcept override {
            return msg.c_str();
        }
    private:
        std::string msg;
    };
    class TypeNotFoundException : public ReflectionException {
    public:
        explicit TypeNotFoundException(std::string message) : ReflectionException(std::move(message)) {}
    };
    class MemberNotFoundException : public ReflectionException {
    public:
        explicit MemberNotFoundException(std::string message, MemberType type) : ReflectionException(std::format("{} (Member Type: {})", message, static_cast<int>(type))) {}
        
    };
    class MismatchedTypeException : public ReflectionException {
    public:
        explicit MismatchedTypeException(std::string message) : ReflectionException(std::move(message)) {}
    };
    class AlignmentException : public ReflectionException {
    public:
        explicit AlignmentException(std::string message) : ReflectionException(std::move(message)) {}
    };
}