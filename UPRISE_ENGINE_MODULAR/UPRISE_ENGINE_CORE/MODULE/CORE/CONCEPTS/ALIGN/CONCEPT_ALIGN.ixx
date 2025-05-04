// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
export module UPRISE_ENGINE_CORE:CONCEPT_ALIGN;
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