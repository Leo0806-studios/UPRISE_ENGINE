#include "pch.h"

#include "DEBUG_LOGGER.h"

Debug::Error::Error(ErrorCode)
{
}

void Debug::Logger::log(std::string  message)
{
	TrPr(ctx,"Log String")
	//White
		std::cout << message << "\n";
	TrPrE(ctx)
}

void Debug::Logger::log(char* message)
{
	//White
		std::cout << message;
}
void Debug::Logger::log(const char* message)
{
	TrPr(ctx, "Log Char")

//	White
		std::cout << message<<"\n";
	TrPrE(ctx);
}

void Debug::Logger::LogExeption(const std::exception exception)
{
	TrPr(ctx,"Log Exception")
	//RedException
		std::cout << exception.what() << "\n";
	//White
		TrPrE(ctx);
}

void Debug::Logger::LogError(Error error)
{
	TrPr(ctx, "Log Error")
	//	Red

	//	White
		TrPrE(ctx);
}

void Debug::Logger::LogError(ErrorCode errorCode)
{
	TrPr(ctx, "Log Error")

//	Red
		std::cout << errorCode << "\n";
	//	White
			TrPrE(ctx);

}

void Debug::Logger::LogWarning()
{
	TrPr(ctx,"Log Warn")
//	Yellow

//		White
		TrPrE(ctx)
}
