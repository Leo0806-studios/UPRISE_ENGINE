// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "../HEADER/DEBUG/LOG/LOG.h"
#include "Windows.h"
//DEBUG::Error::Error(ErrorCode)
//{
//}


namespace UPRISE_ENGINE {
    void DEBUG::Logger::log(std::string  message)
    {
        // TrPr(ctx, "Log String")
             //White
        std::cout << message << "\n";
        //  TrPrE(ctx)
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
    namespace DEBUG {
        DEBUG::LOG_STREAM   Debug::_internal_Stream;
    }

    void DEBUG::LOG_STREAM::Flush()
    {
        LogFile.open(LogPath, std::ios::app);
        LogFile << stream.str();
        stream.str("");
        length = 0;
        LogFile.close();
    }

    inline DEBUG::LOG_STREAM::LOG_STREAM() {
        stream = std::stringstream();
        length = 0;
        stream << "Log Started\n";
        length += constevalstrlen("Log Started\n"); //-V2578
        char buffer[MAX_PATH]{};
        DWORD length_ = GetModuleFileNameA(NULL, static_cast<char*>(buffer), MAX_PATH);
        LogPath = std::string(buffer, length_);

        std::string tmp = LogPath.string();//+= "Log.txt";

        tmp = tmp.substr(0, tmp.find_last_of('\\'));
        tmp += "\\Log.txt";
        LogPath = tmp;
        LogFile.open(LogPath);
        LogFile.close();
        autoFlushLength = 100;

    }

    void DEBUG::Debug::Log(std::string message)
    {
        std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        unsigned long long aaa = a;
        std::string s = std::to_string(a);
        _internal_Stream << "[" << s << "]" << message << "\n";
    }

}
