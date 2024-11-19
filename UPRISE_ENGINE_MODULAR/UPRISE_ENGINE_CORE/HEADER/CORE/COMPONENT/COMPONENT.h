#pragma once
#ifndef _Component_
#define _Component_
#include "OBJECT/OBJECT.h";




namespace CORE {
    /// <summary>
/// base Class for components on GameObjects that are just for storing Data
/// very low runntime cost
/// </summary>
     class UPRISE_CORE_API Component :public CORE::Object {
    private:
    public:
        Component() = default;
        ~Component() {}
        void OnDestroyInt(RefWrapper<CORE::Object, true> obj)override {}
    };
}
#endif // !_Component_
