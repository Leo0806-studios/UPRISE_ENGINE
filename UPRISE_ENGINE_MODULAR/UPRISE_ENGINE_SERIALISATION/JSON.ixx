export module UE_SERIALISATION:JSON;
import std;
export namespace UPRISE_ENGINE::SERIALISATION {
    class Json {
    public:
        using JsonObject = std::unordered_map<std::string, Json>;
        using JsonArray = std::vector<Json>;
    private:
        using JsonValue = std::variant<
            std::nullptr_t,
            bool,
            double,
            std::uint64_t,
            std::int64_t,
            std::string,
            JsonArray,
            JsonObject
        >;
        JsonValue value;

    public:
        explicit Json(std::nullptr_t) : value(nullptr) {}
        explicit Json(bool v) : value(v) {}
        explicit Json(double v) : value(v) {}
        explicit Json(std::uint64_t v) : value(v) {}
        explicit Json(std::int64_t v) : value(v) {}
        explicit Json(std::string v) : value(std::move(v)) {}
        explicit Json(JsonArray v) : value(std::move(v)) {}
        explicit Json(JsonObject v) : value(std::move(v)) {}

        template<typename T>
        bool is() const {
            return std::holds_alternative<T>(value);
        }

        template<typename T>
        const T& get() const {
            return std::get<T>(value);
        }

        template<typename T>
        T& get() {
            return std::get<T>(value);
        };
        void Traverse(const std::function<void(const Json&)>& func) const;
        
    };
    class JsonParse {
        std::string_view jsonView;
        std::size_t index = 0;

        char peekChar() const;
        char getChar();

        void skipWhitespace();

        bool matchChar(char expected);

        Json parseValue();
        Json parseObject();
        Json parseArray();

        std::string parseString();
        Json parseNumber();

        void expectLiteral(std::string_view literal);

    public:
        explicit JsonParse(std::string_view inStr)
            : jsonView(inStr) {}

        JsonParse() = delete;
        JsonParse(const JsonParse&) = delete;
        JsonParse(JsonParse&&) = delete;
        JsonParse& operator=(const JsonParse&) = delete;
        JsonParse& operator=(JsonParse&&) = delete;

        Json parse()&&;
    };





}