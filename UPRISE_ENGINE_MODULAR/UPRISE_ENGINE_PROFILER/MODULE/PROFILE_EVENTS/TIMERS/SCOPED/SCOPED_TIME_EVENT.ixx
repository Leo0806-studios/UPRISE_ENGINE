export module UPRISE_ENGINE_PROFILER:SCOPED_TIME_EVENT;
import <string>;
import <sstream>;
import <unordered_map>;
import <mutex>;
import <algorithm>;
import :EVENT_BASE;
export namespace UPRISE_ENGINE {
    namespace PROFILER {
        namespace TIMERS {
            constexpr int BitSize = 64 * (sizeof(void*) * 8);

            class SCOPED_TIME_EVENT : public EVENT_BASE {
            private:
                const char* name;
                const char* file;
                const char* function;
                unsigned long long duration;
                void* frames[maxFrames];
                unsigned  int threadId;
                int line;
                unsigned long long Timestamp = 0;
                UPRISE_PROFILER_API std::string ResolveSybols() const;
                UPRISE_PROFILER_API  std::string GetStacktrace() const;
                struct Internal_Data {
                    unsigned long long MaxDuration = 0;
                    unsigned long long MinDuration = 0;
                    unsigned long long AvgDuration = 0;
                    size_t count = 0;
                    const char* name;
                    const char* file;
                    const char* function;
                    int line;
                    char PAD[4]{};//TODO: find a better way to align the struct or put data here //-V112
                    Internal_Data() = default;
                    Internal_Data(unsigned long long max, unsigned long long min, unsigned long long avg, size_t count, const char* name, const char* file, const char* function, int line) :
                        MaxDuration(max),
                        MinDuration(min),
                        AvgDuration(avg),
                        count(count),
                        name(name),
                        file(file),
                        function(function),
                        line(line) {
                    }
                    /*
                     //struct CompressedStackFrames {
                     //private:

                     //
                     //    void* _dataStart = nullptr;
                     //    size_t CompressedSize = 0;
                     //    size_t _size = 0;
                     //    std::bitset<BitSize> DeltaEncode(void* _Start, size_t len);
                     //    void* DeltaDecode(void* _Start, size_t len);
                     //    void* RunLengthEncode(std::bitset<BitSize> data);
                     //    void RunLengthDecode();
                     //public:


                     //    CompressedStackFrames(void* data, size_t size) {
                     //        _size = size;
                     //        std::bitset<BitSize> deltaEncodedData=DeltaEncode( data,  size);
                     //        _dataStart = RunLengthEncode(deltaEncodedData);
                     //    }
                     //} CompressedStackFrames_;
                     */
                };
                UPRISE_PROFILER_API static std::mutex dataMutex;
                UPRISE_PROFILER_API static std::unordered_map<const char*, Internal_Data> data;

            public:
                SCOPED_TIME_EVENT() = default;
                SCOPED_TIME_EVENT(const SCOPED_TIME_EVENT& other) = default;

                UPRISE_PROFILER_API SCOPED_TIME_EVENT(const char* name, const char* file, const char* function, int line, unsigned long long duration, void** frames, size_t countFrames, unsigned int threadid, unsigned long long timestamp);
                UPRISE_PROFILER_API  ~SCOPED_TIME_EVENT() = default;
                std::string What() override {
                    std::ostringstream s;
                    s << "{\n"
                        << "\t\"Event\" : { \n"
                        << "\"timestamp\" : " << std::to_string(Timestamp) << ",\n"
                        << "\t\t\"name\" : \"" << name << "\",\n"
                        << "\t\t\"Thread\" :  " << std::to_string(threadId) << ",\n";
                    std::string _file = this->file;
                    std::replace(_file.begin(), _file.end(), '\\', '/');
                    s << "\t\t\"_file\" : \" " << _file << "\",\n"
                        << "\t\t\"function\" : \" " << function << "\",\n"
                        << "\t\t\"line\" :  " << std::to_string(line) << ",\n"
                        << "\t\t\"duration\" : \t{\n";
                    //if (duration < 1000) {
                    s << "\t\t\t\t\"value\" : " << std::to_string(duration) << "\n";

                    //}
                    //else {
                    //    long double dur = duration / 1000;
                    //    if (dur < 1000) {
                    //        s << "\t\t\t\t\"value\" : " << std::to_string(dur) << ",\n"
                    //            << "\t\t\t\t\"unit\" : \"" << "us" << "\"\n";
                    //    }
                    //    else {
                    //        s << "\t\t\t\t\"value\" : " << std::to_string(dur / 1000) << ",\n"
                    //            << "\t\t\t\t\"unit\" : \"" << "ms" << "\"\n";
                    //    }
                    //}
                    s << "\t\t\t\t},\n";


                    s << "\t\t\"Stacktrace\" :\t[\n"

                        << ResolveSybols()
                        << "\t\t\t\t]\n"
                        << "\t\t}\n"
                        << "}\n";
                    return s.str();
                }
                static std::string Summary() {
                    std::unique_lock<std::mutex> lock(dataMutex);
                    std::ostringstream s;
                    s << "#=====================SUMMARY=====================";
                    for (auto& [key, val] : data) {

                        s << "=====================SCOPED_TIME_EVENT=====================\n"
                            << "Event: " << key << "\n"
                            << "Max Duration: ";

                        if (val.MaxDuration < 1000) {
                            s << std::to_string(val.MaxDuration) << " nanoseconds" << "\n";

                        }
                        else {
                            long double dur = static_cast<long double>(val.MaxDuration) / 1000.0;
                            if (dur < 1000.0F) {
                                s << std::to_string(dur) << " microseconds" << "\n";

                            }
                            else {
                                s << std::to_string(dur / 1000.0F) << " milliseconds" << "\n";


                            }
                        }










                        s << "Min Duration: ";
                        if (val.MinDuration < 1000) {
                            s << std::to_string(val.MinDuration) << " nanoseconds" << "\n";

                        }
                        else {
                            long double dur = static_cast<long double> (val.MinDuration) / 1000.0F;
                            if (dur < 1000.0F) {
                                s << std::to_string(dur) << " microseconds" << "\n";

                            }
                            else {
                                s << std::to_string(dur / 1000.0F) << " milliseconds" << "\n";


                            }
                        }










                        s << "Avg Duration: ";
                        if (val.AvgDuration < 1000) {
                            s << std::to_string(val.AvgDuration) << " nanoseconds" << "\n";

                        }
                        else {
                            long double dur = static_cast<long double>(val.AvgDuration) / 1000.0;
                            if (dur < 1000.0) {
                                s << std::to_string(dur) << " microseconds" << "\n";

                            }
                            else {
                                s << std::to_string(dur / 1000.0) << " milliseconds" << "\n";


                            }
                        }




                        s << "Count: " << std::to_string(val.count) << "\n"
                            << " in " << val.file << "\n"
                            << " at " << val.function << "\n"
                            << " at line " << std::to_string(val.line) << "\n"
                            << "==========================================================\n";
                    }
                    return s.str();
                }
            };
        }
    }
}