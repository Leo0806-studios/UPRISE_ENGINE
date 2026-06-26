export module UE_SERIALISATION:JSON_EXCEPTIONS;
import std;
export namespace UPRISE_ENGINE::SERIALISATION {
    class JsonException : public std::exception {
        std::string message;
    public:
        explicit JsonException(std::string msg) : message(std::move(msg)) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}