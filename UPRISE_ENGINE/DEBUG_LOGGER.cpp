#include "DEBUG_LOGGER.h"

Debug::Error::Error(ErrorCode)
{
}

void Debug::Logger::log(std::string  message)
{
	White
		std::cout << message << "\n";
}

void Debug::Logger::log(char* message)
{
	White
		std::cout << message;
}
void Debug::Logger::log(const char* message)
{
	White
		std::cout << message<<"\n";
}

void Debug::Logger::LogExeption(const std::exception exception)
{
	RedException
		std::cout << exception.what() << "\n";
		White
}

void Debug::Logger::LogError(Error error)
{
	Red

		White
}

void Debug::Logger::LogError(ErrorCode errorCode)
{
	Red
		std::cout << errorCode << "\n";
		White
}

void Debug::Logger::LogWarning()
{
	Yellow

		White
}
