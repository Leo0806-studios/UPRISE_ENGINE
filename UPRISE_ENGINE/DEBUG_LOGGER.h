#pragma once
#ifndef _DEBUG_LOGGER_
#define _DEBUG_LOGGER_

#include "pch.h"
#define ERROR Error
#define White system("COLOR 0F");
#define Red system("COLOR 0C");
#define Yellow system("COLOR 06");
#define RedException system("COLOR 04");

enum ErrorCode {
	LowMemory,
	NoMatchinngComponentFoud,


};
namespace Debug {
	class Error {
	public :
		Error(ErrorCode);

	};
	
	class Logger {
	public :
		static void log(std::string  message);
		static void log(char* message);
		static void log(const char* message);
		static void LogExeption(const std::exception exception);
		static void LogError(Error error);
		static void LogError(ErrorCode errorCode);
		static void LogWarning();

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
#define Log Debug::LogStream()


using namespace Debug;

#endif // !_DEBUG_LOGGER_
