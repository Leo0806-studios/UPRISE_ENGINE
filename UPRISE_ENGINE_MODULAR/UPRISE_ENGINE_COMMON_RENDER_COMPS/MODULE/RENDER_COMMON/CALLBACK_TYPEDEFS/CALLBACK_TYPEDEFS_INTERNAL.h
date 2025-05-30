#pragma once
#ifndef UE_CALLBACK_TYPEDEFS_INTERNAL_
#define UE_CALLBACK_TYPEDEFS_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_COMMON_COMPS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE ::RENDER::RENDER_COMMON{
    class WINDOW_BASE;

 
        /// <summary>
    /// 
    /// </summary>
        using KeyInputCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int key, int scancode, int action, int mods);
        /// <summary>
        /// 
        /// </summary>
        using MouseButtonCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int button, int action, int mods);
        /// <summary>
        /// 
        /// </summary>
        using CursorPosCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, double xpos, double ypos);
        /// <summary>
        /// 
        /// </summary>
        using ResizeCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int width, int height);
        /// <summary>
        /// 
        /// </summary>
        using CursorEnterCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int entered);
        /// <summary>
        /// 
        /// </summary>
        using ScrollCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, double xoffset, double yoffset);
        /// <summary>
        /// 
        /// </summary>
        using WindowCloseCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw);
        /// <summary>
        /// 
        /// </summary>
        using WindowRefreshCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw);
        /// <summary>
        /// 
        /// </summary>
        using WindowFocusCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int focused);
        /// <summary>
        /// 
        /// </summary>
        using WindowIconifyCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int iconified);
        /// <summary>
        /// 
        /// </summary>
        using FramebufferSizeCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int width, int height);
        /// <summary>
        /// 
        /// </summary>
        using WindowMaximizeCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int maximized);
        /// <summary>
        /// 
        /// </summary>
        using WindowContentScaleCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, float xscale, float yscale);
        /// <summary>
        /// 
        /// </summary>
        using WindowPosCallback = int (*)(SharedRef<WINDOW_BASE, true> Windopw, int xpos, int ypos);
    

}
#endif