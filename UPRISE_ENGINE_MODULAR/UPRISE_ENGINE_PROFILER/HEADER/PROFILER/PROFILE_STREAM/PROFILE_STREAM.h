#pragma once
#ifndef UE_PROFILE_STREAM_
#define UE_PROFILE_STREAM_
import std; //-V3549 //-V2575
import REF_WRAPPER; //-V3549 //-V2575
#include <cstring>
namespace UPRISE_ENGINE {
    namespace PROFILER {
        class PROFILE_STREAM;
        class PROFILE_EVENT;
#pragma warning(push)
#pragma warning(disable: 4820)

        class PROFILE_STREAM {

        private:
            std::mutex mutex;
            std::stringstream stream;
            unsigned long long length{0};
            unsigned long long autoFlushLength{ 100000 };
            bool autoFlush = true;
            std::filesystem::path LogPath;
            std::ofstream LogFile;

        public:
            PROFILE_STREAM(const PROFILE_STREAM&) = delete;
            PROFILE_STREAM& operator=(const PROFILE_STREAM&) = delete;
            void Flush();
            bool toggleAutoFlush();
            PROFILE_STREAM(bool init);
            PROFILE_STREAM() = default;
            PROFILE_STREAM(PROFILE_STREAM&& other) noexcept {
                if (this != &other) {
                    stream = std::move(other.stream);
                    length = other.length;
                    autoFlushLength = other.autoFlushLength;
                    autoFlush = other.autoFlush;
                    LogPath = std::move(other.LogPath);
                    LogFile = std::move(other.LogFile);
                }
            }
            PROFILE_STREAM& operator=(PROFILE_STREAM&& other) noexcept {
                if (this != &other) {
                    stream = std::move(other.stream);
                    length = other.length;
                    autoFlushLength = other.autoFlushLength;
                    autoFlush = other.autoFlush;
                    LogPath = std::move(other.LogPath);
                    LogFile = std::move(other.LogFile);
                }
                return *this;
            }
            PROFILE_STREAM& operator<<(const std::string& value) {
                //std::lock_guard<std::mutex> lock(mutex);
                stream << value;
                length += value.length();
                if (length >= autoFlushLength) {
                    Flush();
                }

                return *this;
            }
            PROFILE_STREAM& operator<<(const char* value) {
                std::lock_guard<std::mutex> lock(mutex);
                stream << value;
                length += strlen(value); //-V2513
                if (length >= autoFlushLength) {
                    Flush();
                }

                return *this;
            }
            ~PROFILE_STREAM() {
                Flush();

            }




        };
#pragma warning(pop)
    }
}

#endif // !_PROFILE_STREAM_
