export module UE_SERIALISATION:JSON;
import std;
export namespace UPRISE_ENGINE::SERIALISATION {
    class Json {
        using JsonValue = std::variant<
            std::nullptr_t,
            bool,
            double,
            std::string,
            std::vector<Json>,
            std::unordered_map<std::string, Json>
        >;
        JsonValue value;
        std::string_view rawJsonView;
        std::uint64_t index = 0;
        char peekChar();
        char getChar();
        void skipWhitespace();
        bool matchChar(char expected);
        Json parseValue();
    public:
        Json() = default;
        Json(const std::string& inStr);
    };
    class JsonParse {
        std::string_view jsonView;
        std::uint64_t index = 0;
    public:
        JsonParse(const std::string& inStr) : jsonView(inStr) {}
        JsonParse() = delete;
        JsonParse(const JsonParse&) = delete;
        JsonParse(JsonParse&&) = delete;
        JsonParse& operator=(const JsonParse&) = delete;
        JsonParse& operator=(JsonParse&&) = delete;
        Json parse();
    };
}