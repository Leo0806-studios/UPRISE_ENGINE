export module UPRISE_ENGINE_CORE:COMPONENT;
import std;
import REF_WRAPPER;
import :OBJECT;
export namespace UPRISE_ENGINE {
    namespace CORE {
        /// <summary>
    /// base Class for components on GameObjects that are just for storing Data
    /// very low runntime cost
    /// </summary>
        class  Component :public CORE::Object {
        private:
        public:
            UPRISE_CORE_API   Component() = default;
            UPRISE_CORE_API    Component(const Component& other) = delete;
            UPRISE_CORE_API  Component operator=(const Component& other) = delete;
            UPRISE_CORE_API  ~Component() {}
            UPRISE_CORE_API  void OnDestroyInt(WeakRef<CORE::Object, true> obj)override {}
        };
    }
}