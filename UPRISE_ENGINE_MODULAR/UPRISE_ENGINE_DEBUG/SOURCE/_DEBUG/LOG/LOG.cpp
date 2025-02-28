// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "DEBUG/LOG/Log.h"
#include <Windows.h>
//DEBUG::Error::Error(ErrorCode)
//{
//}


namespace UPRISE_ENGINE {
    
    namespace DEBUG {
#ifndef UPRISE_TESTS
        DEBUG::LOG_STREAM   Debug::_internal_Stream;

#endif // !UPRISE_TESTS

    }

    void DEBUG::LOG_STREAM::Flush()
    {
        LogFile.open(LogPath, std::ios::app);
        LogFile << stream.str();
        stream.str("");
        length = 0;
        LogFile.close();
    }

    bool DEBUG::LOG_STREAM::toggleAutoFlush()
    {
        autoFlush = !autoFlush;
        return autoFlush;
    }

    inline DEBUG::LOG_STREAM::LOG_STREAM() {
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

    inline DEBUG::LOG_STREAM::~LOG_STREAM() {
        Flush();
    }

    UPRISE_ENGINE::DEBUG::LOG_STREAM& DEBUG::LOG_STREAM::operator<<(const std::string& value)
    {
        std::lock_guard<std::mutex> lock(mutex);
        stream << value;
        length += value.length();
        if (length >= autoFlushLength) {
            Flush();
        }

        return *this;
    }

    UPRISE_ENGINE::DEBUG::LOG_STREAM& DEBUG::LOG_STREAM::operator<<(const char* value) {
        std::lock_guard<std::mutex> lock(mutex);
        stream << value;
        length += strlen(value); //-V2513
        if (length >= autoFlushLength) {
            Flush();
        }

        return *this;
    }

    void DEBUG::Debug::Log(std::string message)
    {
        std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string s = std::to_string(a);
        AccsesStaticVar(_internal_Stream) << "[" << s << "]" << message << "\n";
    }

     void DEBUG::Debug::LogException(std::exception Exception)
    {
         ///TODO: implement
    }

}


