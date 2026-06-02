#pragma once
#include <mutex>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <IMPORT_DEFS.h>
namespace UPRISE_ENGINE {
    namespace  DEBUG {
        class LOG_STREAM;
        class LOG_STREAM {
        private:
            std::mutex mutex;
            std::stringstream stream;
            unsigned long long length;
            unsigned long long autoFlushLength;
            std::filesystem::path LogPath;
            std::ofstream LogFile;
            bool autoFlush = true;
            char PAD[7];   //TODO find a better way to align this or find data to put here
        public:
            LOG_STREAM(const LOG_STREAM&) = delete;
            LOG_STREAM& operator=(const LOG_STREAM&) = delete;
            UPRISE_DEBUG_API void Flush();
            bool toggleAutoFlush();
            UPRISE_DEBUG_API LOG_STREAM();
            UPRISE_DEBUG_API ~LOG_STREAM();
            UPRISE_DEBUG_API LOG_STREAM& operator<<(const std::string& value);
            UPRISE_DEBUG_API LOG_STREAM& operator<<(const char* value);
        };
    }

}