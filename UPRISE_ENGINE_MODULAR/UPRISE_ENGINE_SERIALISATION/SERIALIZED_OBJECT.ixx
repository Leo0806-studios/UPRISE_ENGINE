module;
#include <MACROS.h>
export module UE_SERIALISATION:SERIALIZED_OBJECT;
import std;
import :SERIALIZED_TYPE_INFO;
export namespace UPRISE_ENGINE::SERIALISATION {
    
        struct SerializedObject {
        public:
            virtual ~SerializedObject() = default;
        };
    
}