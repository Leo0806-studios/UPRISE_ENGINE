#pragma once
#include "RENDER_BACKEND.h"
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {
    class Buffer {
    public:
        using CreatorFunk = std::unique_ptr<Buffer>(*)(int32_t bufferType/* Specific to the concrete backend*/);
    private:
        UPRISE_COMMON_RENDER_COMPS_API static std::unordered_map<Backend, CreatorFunk> RegisteredWindowTypes;

    public:
        virtual ~Buffer() = default;

        UPRISE_COMMON_RENDER_COMPS_API static std::unique_ptr<Buffer> CreateBuffer(int32_t bufferType/* Specific to the concrete backend*/);
    };





    template <typename T, Backend backend>
        requires std::derived_from<T, Buffer>&& requires (int32_t bufferType) {
            {
                T::CreateBuffer(bufferType)
            } -> std::same_as<std::unique_ptr<Buffer>>;
    }
    struct BackendClassRegistry {
    public:
        BackendClassRegistry() {
            RenderBackend::RegisterBackend(backend, [](int32_t bufferType) -> std::unique_ptr<Buffer> {
                return T::CreateBuffer(bufferType);
            });
        }
    };
}