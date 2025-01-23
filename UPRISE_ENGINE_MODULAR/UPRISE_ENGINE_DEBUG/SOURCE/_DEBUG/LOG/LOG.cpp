// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "../HEADER/DEBUG/LOG/LOG.h"

//DEBUG::Error::Error(ErrorCode)
//{
//}



void DEBUG::Logger::log(std::string  message)
{
   // TrPr(ctx, "Log String")
        //White
        std::cout << message << "\n";
  //  TrPrE(ctx)
}

void DEBUG::Logger::log(char* message)
{
    //White
    std::cout << message;
}
void DEBUG::Logger::log(const char* message)
{
    //TrPr(ctx, "Log Char")

        //	White
        std::cout << message << "\n";
   // TrPrE(ctx);
}
void DEBUG::Logger::LogExeption(const std::exception exception)
{
   // TrPr(ctx, "Log Exception")
        //RedException
        std::cout << exception.what() << "\n";
    //White
   // TrPrE(ctx);
}

//void DEBUG::Logger::LogError(Error error)
//{
//  //  TrPr(ctx, "Log Error")
//        //	Red
//
//        //	White
//    //    TrPrE(ctx);
//}
//
//void DEBUG::Logger::LogError(ErrorCode errorCode)
//{
//   // TrPr(ctx, "Log Error")
//
//        //	Red
//        std::cout << errorCode << "\n";
//    //	White
//   // TrPrE(ctx);
//
//}

void DEBUG::Logger::LogWarning()
{
    //TrPr(ctx, "Log Warn")
        //	Yellow

        //		White
       // TrPrE(ctx)
}

void DEBUG::LOG_STREAM::Flush()
{
    LogFile.open(LogPath, std::ios::app);
       LogFile << stream.str();
        stream.str("");
        length = 0;
        LogFile.close();
}


