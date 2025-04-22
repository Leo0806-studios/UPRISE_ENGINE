// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
export module UPRISE_ENGINE_CORE:CONCEPT_SIZE;
import std;
export namespace UPRISE_ENGINE {
    namespace CORE {
        namespace CONCEPTS {
            template<typename T, size_t MaxSize>
            concept SizeLeq = requires(T t) {
                { sizeof(t) <= MaxSize };
            };
            template<typename T, size_t MaxSize>
            concept SizeLess = requires(T t) {
                { sizeof(t) < MaxSize };
            };
        }
    }
}