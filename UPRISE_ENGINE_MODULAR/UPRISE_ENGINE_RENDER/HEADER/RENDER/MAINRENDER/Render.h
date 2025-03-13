// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Render_
#define UE_Render_
#include <GLOBAL/GLINCLUDES.h>
#include "GLOBAL.h"
import REF_WRAPPER; //-V3549 //-V2575
import std; //-V3549 //-V2575
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        class WINDOW_BASE;
        class CONTEXT_BASE;
    }
    class GameObject;
    namespace RENDER {
        class Window;
        enum class Render_Backend {
            RB_OPENGL,
            RB_VULKAN,
            RB_DIRECTX11,
            RB_DIRECTX12
        };
        class Material;
        class Render {
        private:
            UPRISE_RENDER_API static std::unordered_map<std::string, int> materialIDlinkdict;
            UPRISE_RENDER_API static SharedRef<GameObject, true> renderCamera;
            UPRISE_RENDER_API static SharedRef<RENDER_COMMON::WINDOW_BASE, true> Windowvar;

            /// <summary>
            /// WindowDict is a unordert map with a std::string as a key and a ownedRef<Window> as a value
            /// </summary>
            using WindowDict = std::unordered_map<std::string, OwnedRef<Window>>;
            UPRISE_RENDER_API MockableStaticVar(WindowDict,Windows)

        public:
            UPRISE_RENDER_API static void DisplayFpsInMainWindowTitle(double Fps);
            Render() = default;
            ~Render() {}

            /// <summary>
            /// Set the render camera
            /// </summary>
            /// <param name="cam"></param>
            UPRISE_RENDER_API static void SetRenderCamera(SharedRef<GameObject, true> cam);
            UPRISE_RENDER_API __inline static  SharedRef<RENDER_COMMON::WINDOW_BASE, true> GetWindow();

            class RenderSetup {
            private:
                UPRISE_RENDER_API static bool setup_call;
            public:
                RenderSetup() = delete;
                UPRISE_RENDER_API  static void SetRenderBackend(Render_Backend backend);
                UPRISE_RENDER_API   static void CreateBackend();
                UPRISE_RENDER_API static WeakRef<RENDER_COMMON::CONTEXT_BASE, true>  CreateContext(WeakRef<RENDER_COMMON::WINDOW_BASE, true> window);
                static UPRISE_RENDER_API OwnedRef<RENDER_COMMON::WINDOW_BASE> Window(int w, int h, std::string Title);
                UPRISE_RENDER_API static void framebuffer_size_callback(SharedRef<RENDER_COMMON::WINDOW_BASE, true> window, int width, int height);
                UPRISE_RENDER_API static void Setup(int w, int h, const char* Title, UPRISE_ENGINE::RENDER::Render_Backend backend);
            };
            class RenderShutdown {

            public:
                
                UPRISE_RENDER_API static void Shutdown();

            };
        };
    }
}

#endif // !_Render_
