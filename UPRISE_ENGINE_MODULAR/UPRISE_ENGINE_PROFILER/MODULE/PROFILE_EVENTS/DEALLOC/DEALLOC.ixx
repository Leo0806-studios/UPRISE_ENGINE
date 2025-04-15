export module UPRISE_ENGINE_PROFILER:DEALLOC;
import <string>;
import :EVENT_BASE;
export namespace UPRISE_ENGINE {
    namespace PROFILER {
#pragma warning(push)
#pragma warning(disable: 4820)

        class DEALLOC :public EVENT_BASE {
        private:
            size_t size;
            void* ptr;
            const char* Type;
            const char* File;
            int Line;
            const char* message;
        public:
            std::string What() {
                std::string a = "#Dealloc at ";
                a += std::to_string(reinterpret_cast<unsigned long long>(ptr));
                a += " size: ";
                a += std::to_string(size);
                a += " with message: ";
                a += message;
                return a.c_str();
            }
            DEALLOC() = default;
            DEALLOC(size_t size, void* ptr, const char* Type, const char* File, int Line, const char* message) {
                this->size = size;
                this->ptr = ptr;
                this->Type = Type;
                this->File = File;
                this->Line = Line;
                this->message = message;
            }

        };
#pragma warning(pop)
    }
}