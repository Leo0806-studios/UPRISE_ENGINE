#pragma once
#ifndef _Log_
#define _Log_
#include "../pch.h"
import std;
namespace DEBUG{
	class Logger {
	private:
	public:
    public:
        UPRISE_DEBUG_API static void log(std::string  message);
        UPRISE_DEBUG_API static void log(char* message);
        UPRISE_DEBUG_API static void log(const char* message);
        UPRISE_DEBUG_API  static void LogExeption(const std::exception exception);
      //  static void LogError(Error error);
       // static void LogError(ErrorCode errorCode);
        UPRISE_DEBUG_API static void LogWarning();
        template<typename ... Args>
        static void log(const std::string& format, Args ... args) {
            std::string message = string_format(format, args...);
            log(message);
        }
	};
    class LogStream {
    public:
        LogStream() : stream() {}
        ~LogStream() {
            Logger::log(stream.str());
        }

        template<typename t>
        LogStream& operator<<(const t& value) {
            stream << value;
            return *this;
        }

    private:
        std::stringstream stream;
    };
}
#define Log DEBUG::LogStream()

#endif // !_Log_
