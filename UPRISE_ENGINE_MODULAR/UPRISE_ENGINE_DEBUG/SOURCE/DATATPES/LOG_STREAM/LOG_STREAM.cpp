import UPRISE_ENGINE_DEBUG;



#include <Windows.h>
import std;


namespace UPRISE_ENGINE {
    namespace DEBUG {
        void LOG_STREAM::Flush()
        {
            LogFile.open(LogPath, std::ios::app);
            LogFile << stream.str();
            stream.str("");
            length = 0;
            LogFile.close();
        }
        bool LOG_STREAM::toggleAutoFlush()
        {
            autoFlush = !autoFlush;
            return autoFlush;
        }

        inline LOG_STREAM::LOG_STREAM() {
            stream = std::stringstream();
            length = 0;
            stream << "Log Started\n";
            length += constevalstrlen("Log Started\n"); //-V2578
            char buffer[MAX_PATH]{};
            DWORD length_ = GetModuleFileNameA(NULL, static_cast<char*>(buffer), MAX_PATH);
            LogPath = std::string(buffer, length_);

            std::string tmp = LogPath.string();

            tmp = tmp.substr(0, tmp.find_last_of('\\'));
            tmp += "\\Log.txt";
            LogPath = tmp;
            LogFile.open(LogPath);
            LogFile.close();
            autoFlushLength = 100;

        }
        inline LOG_STREAM::~LOG_STREAM() {
            Flush();
        }
        LOG_STREAM& LOG_STREAM::operator<<(const std::string& value)
        {
            std::lock_guard<std::mutex> lock(mutex);
            stream << value;
            length += value.length();
            if (length >= autoFlushLength) {
                Flush();
            }

            return *this;
        }
        LOG_STREAM& LOG_STREAM::operator<<(const char* value) {
            std::lock_guard<std::mutex> lock(mutex);
            stream << value;
            length += strlen(value); //-V2513
            if (length >= autoFlushLength) {
                Flush();
            }

            return *this;
        }

    }
}