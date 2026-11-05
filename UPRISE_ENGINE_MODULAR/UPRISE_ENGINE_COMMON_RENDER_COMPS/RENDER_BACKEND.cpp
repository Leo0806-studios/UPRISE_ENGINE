// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <memory>
#include <LOG.h>
#include <UTILITIES.h>
#include <UUID.h>
#include "RENDER_BACKEND.h"
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {



    Key RenderBackend::internalRegisterWindow(std::unique_ptr<Window> window)
    {
        return Key(nullptr);
    }

    std::weak_ptr<Window> RenderBackend::internalGetWindow(Key key)
    {
        return std::weak_ptr<Window>();
    }

    void RenderBackend::internalDestroyWindow(Key key)
    {}

    Key RenderBackend::internalRegisterBuffer(std::unique_ptr<Buffer> buffer)
    {
        return Key(nullptr);
    }

    std::weak_ptr<Buffer> RenderBackend::internalGetBuffer(Key key)
    {
        return std::weak_ptr<Buffer>();
    }

    void RenderBackend::internalDestroyBuffer(Key key)
    {}

    Key RenderBackend::internalRegisterContext(std::unique_ptr<Context> context)
    {
        return Key(nullptr);
    }

    std::weak_ptr<Context> RenderBackend::internalGetContext(Key key)
    {
        return std::weak_ptr<Context>();
    }

    void RenderBackend::internalDestroyContext(Key key)
    {}

    void RenderBackend::CreateBackend(Backend backend)
    {
        ASSERT_MSG(internalBackend == nullptr, "Backend already created. cannot create another backend");
        ASSERT_MSG(std::to_underlying(backend) < backendCreators.size(), "Backend Type Invalid. max integer value is 3");
        internalBackend = backendCreators[backend]();
    }

    std::weak_ptr<RenderBackend> RenderBackend::GetBackend()
    {
        return internalBackend;
    }

    Backend RenderBackend::GetBackendType()
    {
        return backendType;
    }

    Key RenderBackend::RegisterWindow(std::unique_ptr<Window> window)
    {
        DATATYPES::UUID uuid = DATATYPES::UUID::Create();
        Key key(std::to_string(uuid));
        auto [it, succsess] = windows.try_emplace(key, std::move(window));
        if (!succsess) UE_UNLIKELY{
            return Key(nullptr);
        }
        return key;
    }

    std::weak_ptr<Window> RenderBackend::GetWindow(Key key)
    {
        auto it = windows.find(key);
        if (it == windows.end())
        {
            return std::weak_ptr<Window>();
        }
        return (*it).second;
    }

    Succsess RenderBackend::DestroyWindow(Key key)
    {
        auto it = windows.find(key);
        if (it == windows.end()) {
            return false;
        }
        (*it).second.reset();
        windows.erase(it);
        return true;
    }

    void RenderBackend::DestroyAllWindows()
    {
        for (auto& [key, window] : windows) {
            internalBackend->internalDestroyWindow(key);
            window.reset();
        }
        windows.clear();
    }

    Key RenderBackend::RegisterBuffer(std::unique_ptr<Buffer> buffer)
    {
        DATATYPES::UUID uuid = DATATYPES::UUID::Create();
        Key key(std::to_string(uuid));
        auto [it, succsess] = buffers.try_emplace(key, std::move(buffer));
        if (!succsess) UE_UNLIKELY{
            return Key(nullptr);
        }
        return key;
    }

    std::weak_ptr<Buffer> RenderBackend::GetBuffer(Key key)
    {
        auto it = buffers.find(key);
        if (it == buffers.end())
        {
            return std::weak_ptr<Buffer>();
        }
        return (*it).second;
    }

    Succsess RenderBackend::DestroyBuffer(Key key)
    {
        auto it = buffers.find(key);
        if (it == buffers.end()) {
            return false;
        }
        (*it).second.reset();
        buffers.erase(it);
        return true;
    }

    void RenderBackend::DestroyAllBuffers()
    {
        for (auto& [key, buffer] : buffers) {
            internalBackend->internalDestroyBuffer(key);
            buffer.reset();
        }
        buffers.clear();
    }

    Key RenderBackend::RegisterContext(std::unique_ptr<Context> context)
    {
        DATATYPES::UUID uuid = DATATYPES::UUID::Create();
        Key key(std::to_string(uuid));
        auto [it,succsess]=contexts.try_emplace(key, std::move(context));
        if (!succsess) UE_UNLIKELY{
            return Key(nullptr);
        }
        return key;
    }

    std::weak_ptr<Context> RenderBackend::GetContext(Key key)
    {
        auto it = contexts.find(key);
        if (it == contexts.end())
        {
            return std::weak_ptr<Context>();
        }
        return (*it).second;
    }

    Succsess RenderBackend::DestroyContext(Key key)
    {

        auto it = contexts.find(key);
        if (it == contexts.end()) {
            return false;
        }
        internalBackend->internalDestroyBuffer(key);
        (*it).second.reset();
        contexts.erase(it);
        return true;
    }

    void RenderBackend::DestroyAllContexts()
    {
        for (auto& [key, context] : contexts) {
            internalBackend->internalDestroyContext(key);
            context.reset();
        }
        contexts.clear();
    }

    void RenderBackend::UpdateDrawFrame()
    {
        internalBackend->internalUpdateDrawFrame();
    }

    void RenderBackend::RegisterBackend(Backend backend, CreatorFunk functor)
    {
        ASSERT_MSG(std::to_underlying(backend) >= backendCreators.size(), "Backend Type Invalid. max integer value is 3");
        backendCreators[backend] = functor;
    }

}


