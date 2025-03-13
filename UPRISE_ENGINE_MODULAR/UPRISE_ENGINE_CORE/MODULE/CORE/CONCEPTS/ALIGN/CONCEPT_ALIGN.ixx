module;
export module UPRISE_ENGINE_CORE:CONCEPT_ALIGN;
import std;
export namespace UPRISE_ENGINE {
    namespace CORE {
        namespace CONCEPTS {
            template <typename T, size_t Align_>
            concept Align = requires(T t) {
                { alignof(T) == Align_ };
            };
        }
    }
}