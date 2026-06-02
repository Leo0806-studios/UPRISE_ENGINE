// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//#include <tracy/Tracy.hpp>
//#include <tracy/TracyC.h>
#include "SCOPED_TIME_EVENT.h"

#define NOMINMAX
#include <Windows.h>

#include <DbgHelp.h>


HANDLE getHandle() {
    static HANDLE h = GetCurrentProcess();
    return h;
}
namespace UPRISE_ENGINE {
    namespace PROFILER {
        namespace TIMERS {
            std::unordered_map<const char*, SCOPED_TIME_EVENT::Internal_Data> SCOPED_TIME_EVENT::data;
            std::mutex SCOPED_TIME_EVENT::dataMutex;
            //std::bitset<BitSize> SCOPED_TIME_EVENT::Internal_Data::CompressedStackFrames::DeltaEncode(void* _Start, size_t len)
            //{
            //    uint8_t* start = static_cast<uint8_t*>(_Start); // Cast the void* to uint8_t*  
            //    std::bitset<BitSize> bitset;

            //    size_t bitIndex = 0;
            //    for (size_t i = 0; i < len; i++) {
            //        uint8_t byte = start[i];
            //        for (int bitpos = 0; bitpos < 8; ++bitpos) {
            //            bool bit = (byte >> (7 - bitpos)) & 1;
            //            if (bitIndex == 0) {
            //                bitset[bitIndex] = bit;
            //            }
            //            else {
            //                bool prevBit = bitset[bitIndex - 1];
            //                bitset[bitIndex] = bit ^ prevBit;
            //            }
            //            bitIndex++;
            //        }
            //    }
            //    return bitset;
            //}
            //void* SCOPED_TIME_EVENT::Internal_Data::CompressedStackFrames::RunLengthEncode(std::bitset<BitSize> data)
            //{
            //    void* buffer = malloc(BitSize / 8);
            //    uint32_t FinalBitAmmount = 0;
            //    return nullptr;
            //}
        }
    }
}
    std::string UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::ResolveSybols() const
    {
        std::string result;
        static bool symInitialized = false;
        if (!symInitialized) {
            SymInitialize(getHandle(), NULL, TRUE); //-V2547
            symInitialized = true;
        }
        static char symbolBuffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)]; //-V119
        char* symbolBufferPtr = symbolBuffer;
        PSYMBOL_INFO symbol = reinterpret_cast<PSYMBOL_INFO>(symbolBufferPtr);
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = MAX_SYM_NAME;
        static std::unordered_map<void*, std::string> symbolCache;
        for (size_t i = 0; i < maxFrames && frames[i] != nullptr; i++) {
            if (symbolCache.find(frames[i]) != symbolCache.end()) {
                result += symbolCache[frames[i]];
                continue;
                
            }
            DWORD64 displacement = 0;
            if (SymFromAddr(getHandle(), reinterpret_cast<DWORD64>(frames[i]), &displacement, symbol)) {
                std::ostringstream symbolInfo;

                symbolInfo
                    << "\t\t\t\t\t{\n"
                    << "\t\t\t\t\"Symbol\" :{\n"
                    << "\t\t\t\t\t\t\"name\": \"" << std::string(symbol->Name) << "\",\n"
                    << "\t\t\t\t\t\t\"Displacement\" :" + std::to_string(displacement) + "\n"
                    << "\t\t\t\t\t  }\n"
                    << "\t\t\t\t\t},\n";

                result += symbolInfo.str();
                symbolCache[frames[i]] = symbolInfo.str();
            }
            else {
                result += "Failed to get symbol\n";
            }
        }
        if (result.contains(","))
        {
            auto lastcomma = result.find_last_of(',');
            result.erase(lastcomma);
        }

        return result;
    }
    inline UPRISE_PROFILER_API std::string UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::GetStacktrace() const {
        std::ostringstream s;
        s << "Stacktrace:\n";
        for (size_t i = 0; i < maxFrames && frames[i] != nullptr; i++) {
            s << i << ": " << reinterpret_cast<size_t>(frames[i]) << "\n"; //-V128
        }
        return s.str();
    }

    inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::SCOPED_TIME_EVENT(const char* name, const char* file, const char* function, int line, unsigned long long duration, void** frames, size_t countFrames, unsigned int threadid,unsigned long long timestamp) :
        name(name),
        file(file),
        function(function),
        duration(duration),
        threadId(threadid),
        line(line),

        Timestamp(timestamp)
    {
        {

            std::unique_lock<std::mutex> lock(dataMutex);
            if (data.find(name) == data.end())
            {
                data[name] = Internal_Data(duration, duration, duration, 1, name, file, function, line);
                /*          data[name] = Internal_Data();
                          data[name].name = name;
                          data[name].file = file;
                          data[name].function = function;
                          data[name].line = line;
                          data[name].MaxDuration = duration;
                          data[name].MinDuration = duration;
                          data[name].AvgDuration = duration;
                          data[name].count = 1;*/

            }
            else {
                auto& Item = data[name];
               Item.count++;
               Item.AvgDuration = ((Item.AvgDuration * (Item.count-1)) + duration) / Item.count /*(data[name].AvgDuration + duration) / data[name].count*/;
               Item.MaxDuration = (std::max)(Item.MaxDuration, duration);
               Item.MinDuration = (std::min)(Item.MinDuration, duration);
            }
        }

        for (size_t i = 0; i < countFrames; i++) {

            this->frames[i] = frames[i]; //-V2563
        }
    }


