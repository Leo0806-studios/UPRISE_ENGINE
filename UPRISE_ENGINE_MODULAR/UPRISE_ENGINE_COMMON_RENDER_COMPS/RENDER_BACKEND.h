#pragma once
#include <MACROS.h>
#include <memory>
#include <string>
#include <unordered_map>

namespace UPRISE_ENGINE::RENDER {
    namespace OPENGL_RENDER {
        class OpenGlBackend;
    }
    namespace  DIRECTX11_RENDER {
        class DIRECTX11_BACKEND;
    }
    namespace  DIRECTX12_RENDER {
        class DIRECTX12_BACKEND;
    }
    namespace VULKAN_RENDER {
        class VULKAN_BACKEND;
    }
    class Render;
    namespace RENDER_COMMON
    {


        class Key {
            uint64_t key;
        public:
            explicit Key(uint64_t key) : key(key) {}
            explicit Key(const std::string& key) : key(std::hash<std::string>{}(key)) {}
            uint64_t get() const {
                return key;
            }
            uint64_t operator()() const {
                return key;
            }
        };
        class Window;
        class Context;
        class Buffer;
        enum Backend {//NOSONAR
            B_OPENGL = 0,
            B_VULKAN = 1,
            B_DIRECTX11 = 2,
            B_DIRECTX12 = 3,

        };

        class RenderBackend {//NOSONAR
        public:
            using CreatorFunk = std::unique_ptr<RenderBackend>(*)(std::string Title, int Width, int Height);

            RenderBackend() = default;
            virtual  ~RenderBackend() = default;
        private:
            UPRISE_COMMON_RENDER_COMPS_API  static  std::array<CreatorFunk, 4> backendCreators;
            UPRISE_COMMON_RENDER_COMPS_API  static std::shared_ptr<RenderBackend> internal_backend;
            UPRISE_COMMON_RENDER_COMPS_API static Backend backendType;
            UPRISE_COMMON_RENDER_COMPS_API  static std::unordered_map<Key, std::shared_ptr<Window>> windows;
            UPRISE_COMMON_RENDER_COMPS_API  static std::unordered_map<Key, std::shared_ptr<Buffer>> buffers;
            UPRISE_COMMON_RENDER_COMPS_API  static std::unordered_map<Key, std::shared_ptr<Context>> contexts;



            UPRISE_COMMON_RENDER_COMPS_API virtual void internalUpdateDrawFrame() = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual Key internalRegisterWindow(std::unique_ptr<Window> window);
        public:
            UPRISE_COMMON_RENDER_COMPS_API static void CreateBackend(Backend backend);

            UPRISE_COMMON_RENDER_COMPS_API static std::weak_ptr<RenderBackend> GetBackend(); 
            UPRISE_COMMON_RENDER_COMPS_API static Backend GetBackendType();


            UPRISE_COMMON_RENDER_COMPS_API static Key RegisterWindow(std::unique_ptr<Window> window);
            UPRISE_COMMON_RENDER_COMPS_API static std::weak_ptr<Window> GetWindow(Key key);
            UPRISE_COMMON_RENDER_COMPS_API static void DestroyWindow(Key key);
            UPRISE_COMMON_RENDER_COMPS_API static void DestroyAllWindows();

            UPRISE_COMMON_RENDER_COMPS_API static Key RegisterBuffer(std::unique_ptr<Buffer> buffer);
            UPRISE_COMMON_RENDER_COMPS_API static std::weak_ptr<Buffer> GetBuffer(Key key);
            UPRISE_COMMON_RENDER_COMPS_API static void DestroyBuffer(Key key);
            UPRISE_COMMON_RENDER_COMPS_API static void DestroyAllBuffers();

            UPRISE_COMMON_RENDER_COMPS_API static Key RegisterContext(std::unique_ptr<Context> context);
            UPRISE_COMMON_RENDER_COMPS_API static std::weak_ptr<Context> GetContext(Key key);
            UPRISE_COMMON_RENDER_COMPS_API static void DestroyContext(Key key);
            UPRISE_COMMON_RENDER_COMPS_API static void DestroyAllContexts();




            UPRISE_COMMON_RENDER_COMPS_API static void UpdateDrawFrame();


            UPRISE_COMMON_RENDER_COMPS_API static void RegisterBackend(Backend backend, CreatorFunk functor);
        };









        template <typename T, Backend backend>
            requires std::derived_from<T, RenderBackend>&& requires () {
                {
                    T::CreateBackend()
                } -> std::same_as<std::unique_ptr<Window>>;
        }
        struct BackendClassRegistry {
        public:
            BackendClassRegistry() {
                RenderBackend::RegisterBackend(backend, []() -> std::unique_ptr<RenderBackend> {
                    return T::CreateBackend();
                });
            }
        };
    }

}




namespace std {
    inline std::string to_string(UPRISE_ENGINE::RENDER::RENDER_COMMON::Backend _Val) {
        switch (_Val) {
            using enum UPRISE_ENGINE::RENDER::RENDER_COMMON::Backend;
            case B_OPENGL: return "OPENGL";
            case B_DIRECTX11:return "DIRECTX11";
            case B_DIRECTX12:return "DIRECTX12";
            case B_VULKAN: return "VULKAN";
            default: return "unknown";
        }
    }
}