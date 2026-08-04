import UE_SERIALISATION;
import std;
namespace UPRISE_ENGINE::SERIALISATION {

    char JsonParse::peekChar() const {
        if (index >= jsonView.size()) {
            throw std::runtime_error("Unexpected end of JSON");
        }

        return jsonView[index];
    }

    char JsonParse::getChar() {

        return peekChar(), jsonView[index++];
    }

    void JsonParse::skipWhitespace() {
        while (index < jsonView.size() &&
               std::isspace(static_cast<unsigned char>(jsonView[index]))) {
            ++index;
        }
    }

    bool JsonParse::matchChar(char expected) {
        skipWhitespace();

        if (index < jsonView.size() &&
            jsonView[index] == expected) {
            ++index;
            return true;
        }

        return false;
    }

    Json JsonParse::parseValue() {
        skipWhitespace();

        switch (peekChar()) {
            case '{':
                return parseObject();

            case '[':
                return parseArray();

            case '"':
                return Json(parseString());

            case 't':
                expectLiteral("true");
                return Json(true);

            case 'f':
                expectLiteral("false");
                return Json(false);

            case 'n':
                expectLiteral("null");
                return Json(nullptr);

            default:
                return parseNumber();
        }
    }
    void Json::Traverse(const std::function<void(const Json&)>& func) const {
        std::ignore = func;
        auto lambda = [](auto&&) {};
        std::visit(lambda, value);
    }
    void Json::Emplace(const std::string& key, Json&& val)
    {
        std::ignore = key;
        std::ignore = val;
    
    }
    Json JsonParse::parseObject() {
        getChar(); // {

        Json::JsonObject obj;

        skipWhitespace();

        if (matchChar('}'))
            return Json(std::move(obj));

        while (true) {
            skipWhitespace();

            if (peekChar() != '"')
                throw std::runtime_error("Expected object key");

            std::string key = parseString();

            skipWhitespace();

            if (!matchChar(':'))
                throw std::runtime_error("Expected ':'");

            obj.emplace(std::move(key), parseValue());

            skipWhitespace();

            if (matchChar('}'))
                break;

            if (!matchChar(','))
                throw std::runtime_error("Expected ','");
        }

        return Json(std::move(obj));
    }

    Json JsonParse::parseArray() {
        getChar(); // [

        Json::JsonArray arr;

        skipWhitespace();

        if (matchChar(']'))
            return Json(std::move(arr));

        while (true) {
            arr.push_back(parseValue());

            skipWhitespace();

            if (matchChar(']'))
                break;

            if (!matchChar(','))
                throw std::runtime_error("Expected ','");
        }

        return Json(std::move(arr));
    }

    std::string JsonParse::parseString() {
        if (getChar() != '"')
            throw std::runtime_error("Expected string");

        std::string result;

        while (true) {
            char c = getChar();

            if (c == '"')
                break;

            if (c == '\\') {
                c = getChar();

                switch (c) {
                    case '"':  result.push_back('"');  break;
                    case '\\': result.push_back('\\'); break;
                    case '/':  result.push_back('/');  break;
                    case 'b':  result.push_back('\b'); break;
                    case 'f':  result.push_back('\f'); break;
                    case 'n':  result.push_back('\n'); break;
                    case 'r':  result.push_back('\r'); break;
                    case 't':  result.push_back('\t'); break;

                    default:    
                        throw std::runtime_error("Invalid escape");
                }
            }
            else {
                result.push_back(c);
            }
        }

        return result;
    }

    Json JsonParse::parseNumber() {
        skipWhitespace();

        std::size_t start = index;

        bool negative = false;
        bool isFloating = false;

        if (peekChar() == '-') {
            negative = true;
            ++index;
        }

        while (index < jsonView.size() &&
               std::isdigit(static_cast<unsigned char>(jsonView[index]))) {
            ++index;
        }

        if (index < jsonView.size() &&
            jsonView[index] == '.') {

            isFloating = true;
            ++index;

            while (index < jsonView.size() &&
                   std::isdigit(static_cast<unsigned char>(jsonView[index]))) {
                ++index;
            }
        }

        if (index < jsonView.size() &&
            (jsonView[index] == 'e' || jsonView[index] == 'E')) {

            isFloating = true;
            ++index;

            if (index < jsonView.size() &&
                (jsonView[index] == '+' || jsonView[index] == '-')) {
                ++index;
            }

            while (index < jsonView.size() &&
                   std::isdigit(static_cast<unsigned char>(jsonView[index]))) {
                ++index;
            }
        }

        std::string str(jsonView.substr(start, index - start));

        if (isFloating) {
            return Json(std::stod(str));
        }

        if (negative) {
            return Json(std::stoll(str));
        }

        return Json(std::stoull(str));
    }

    void JsonParse::expectLiteral(std::string_view literal) {
        for (char c : literal) {
            if (getChar() != c)
                throw std::runtime_error("Invalid literal");
        }
    }

    Json JsonParse::parse()&&
    {
        Json result = parseValue();

        skipWhitespace();

        if (index != jsonView.size())
            throw std::runtime_error("Trailing characters");

        return result;
    }

}