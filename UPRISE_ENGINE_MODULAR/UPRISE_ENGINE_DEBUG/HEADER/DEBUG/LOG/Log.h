// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Log_
#define _Log_
#include "../pch.h"
import std;
 
namespace DEBUG{
    class LOG_STREAM;
    
    class Debug {
        static UPRISE_DEBUG_API LOG_STREAM _internal_Stream;
    public:

        UPRISE_DEBUG_API static void Log(std::string message);
    };
	class LOG_STREAM {
	private:
		std::mutex mutex;
		std::stringstream stream;
		unsigned long long length;
		unsigned long long autoFlushLength;
		bool autoFlush=true;
        std::filesystem::path LogPath;
        std::ofstream LogFile;

	public:
        UPRISE_DEBUG_API void Flush();
		bool toggleAutoFlush();
		LOG_STREAM() : stream(), length(0) {
            stream << "Log Started\n";
            length += strlen("Log Started\n");
            char buffer[MAX_PATH];
            DWORD length_ = GetModuleFileNameA(NULL, buffer, MAX_PATH);
            LogPath = std::string(buffer, length_ );
            
            std::string tmp = LogPath.string();//+= "Log.txt";

            tmp = tmp.substr(0, tmp.find_last_of('\\'));
            tmp += "\\Log.txt";
            LogPath = tmp;
            LogFile.open(LogPath);
            LogFile.close();
            autoFlushLength = 100;
        
        }
        ~LOG_STREAM() {
            Flush();
        }
		LOG_STREAM& operator<<(const std::string& value) {
			std::lock_guard<std::mutex> lock(mutex);
            stream << value;
            length += value.length();
			if (length >= autoFlushLength) {
				Flush();
			}

			return *this;
		}
		LOG_STREAM& operator<<(const char* value) {
			std::lock_guard<std::mutex> lock(mutex);
            stream << value;
            length += strlen(value);
			if (length >= autoFlushLength) {
				Flush();
			}

			return *this;
		}
		LOG_STREAM& operator<<( char* value) {
			std::lock_guard<std::mutex> lock(mutex);
            stream << value;
            length += strlen(value);
			if (length >= autoFlushLength) {
				Flush();
			}

			return *this;
		}

	};
	 UPRISE_DEBUG_API LOG_STREAM Log;
	 UPRISE_DEBUG_API LOG_STREAM LogExeption;
	 UPRISE_DEBUG_API LOG_STREAM LogWarning;
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
;
using namespace DEBUG;
//#define Log DEBUG::LogStream()

#endif // !_Log_
