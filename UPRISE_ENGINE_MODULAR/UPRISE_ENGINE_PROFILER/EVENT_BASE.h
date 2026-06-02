#pragma once
#include <string>
 namespace UPRISE_ENGINE {
    namespace PROFILER {

        class EVENT_BASE {
        private:
        public:
            EVENT_BASE() = default;
            virtual ~EVENT_BASE() = default;
            EVENT_BASE(const EVENT_BASE& other) = default;
            virtual std::string What() {
                return "std::string what() is not overriden";


            }


        };
    }
}