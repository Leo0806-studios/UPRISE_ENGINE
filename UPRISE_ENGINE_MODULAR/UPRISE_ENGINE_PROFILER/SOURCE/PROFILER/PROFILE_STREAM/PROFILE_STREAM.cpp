// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma warning(push)
#pragma warning(disable: 4100)
#include "PROFILER/PROFILE_STREAM/PROFILE_STREAM.h"
#include <Windows.h>
namespace UPRISE_ENGINE {
    namespace PROFILER {

         PROFILE_STREAM::PROFILE_STREAM(bool init) : stream(), length(0) { //-V2537 //-V3523
            
            stream << "#Profiling started\n";
            length += constevalstrlen("#Profiling started\n"); //-V2578 //-V3551
            char buffer[MAX_PATH]{};
            DWORD length_ = GetModuleFileNameA(NULL, static_cast<char*>(buffer), MAX_PATH);
            LogPath = std::string(buffer, length_);

            std::string tmp = LogPath.string();//+= "Log.txt";

            tmp = tmp.substr(0, tmp.find_last_of('\\'));
            tmp += "\\Profiling.txt";
            LogPath = tmp;
            LogFile.open(LogPath);
            LogFile.close();
            autoFlushLength = 10000;

        }

         void PROFILE_STREAM::Flush() {
             //std::lock_guard<std::mutex> lock(mutex);
             LogFile.open(LogPath, std::ios::app);
             LogFile << stream.str();
             LogFile.close();
             stream.str("");
             length = 0;
         }
#pragma warning(pop)
         bool PROFILE_STREAM::toggleAutoFlush()
         {
             autoFlush = !autoFlush;
             return autoFlush;
         }


    }
}
