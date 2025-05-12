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

namespace UPRISE_ENGINE {
    class WINDOW_BASE;

    namespace RENDER_COMMON {
        /// <summary>
    /// 
    /// </summary>
        typedef int(*KeyInputCallback)(SharedRef<WINDOW_BASE, true> Windopw, int key, int scancode, int action, int mods);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*MouseButtonCallback)(SharedRef<WINDOW_BASE, true> Windopw, int button, int action, int mods);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*CursorPosCallback)(SharedRef<WINDOW_BASE, true> Windopw, double xpos, double ypos);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*ResizeCallback)(SharedRef<WINDOW_BASE, true> Windopw, int width, int height);
        /// <summary>
        /// 
        /// </summary>
        typedef int (*CursorEnterCallback)(SharedRef<WINDOW_BASE, true> Windopw, int entered);
        /// <summary>
        /// 
        /// </summary>
        typedef int (*ScrollCallback)(SharedRef<WINDOW_BASE, true> Windopw, double xoffset, double yoffset);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowCloseCallback)(SharedRef<WINDOW_BASE, true> Windopw);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowRefreshCallback)(SharedRef<WINDOW_BASE, true> Windopw);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowFocusCallback)(SharedRef<WINDOW_BASE, true> Windopw, int focused);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowIconifyCallback)(SharedRef<WINDOW_BASE, true> Windopw, int iconified);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*FramebufferSizeCallback)(SharedRef<WINDOW_BASE, true> Windopw, int width, int height);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowMaximizeCallback)(SharedRef<WINDOW_BASE, true> Windopw, int maximized);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowContentScaleCallback)(SharedRef<WINDOW_BASE, true> Windopw, float xscale, float yscale);
        /// <summary>
        /// 
        /// </summary>
        typedef int(*WindowPosCallback)(SharedRef<WINDOW_BASE, true> Windopw, int xpos, int ypos);
    }

}
#endif