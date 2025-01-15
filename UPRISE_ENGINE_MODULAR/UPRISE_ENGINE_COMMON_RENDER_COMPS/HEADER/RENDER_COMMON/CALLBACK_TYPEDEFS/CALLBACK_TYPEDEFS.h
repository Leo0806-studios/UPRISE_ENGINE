#pragma once
#ifndef _CALLBACK_TYPEDEFS_
#define _CALLBACK_TYPEDEFS_
import REF_WRAPPER;
class WINDOW_BASE;

namespace RENDER_COMMON {
    /// <summary>
/// 
/// </summary>
    typedef int(*KeyInputCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int key, int scancode, int action, int mods);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*MouseButtonCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int button, int action, int mods);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*CursorPosCallback)(RefWrapper<WINDOW_BASE, true> Windopw, double xpos, double ypos);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*ResizeCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int width, int height);
    /// <summary>
    /// 
    /// </summary>
    typedef int (*CursorEnterCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int entered);
    /// <summary>
    /// 
    /// </summary>
    typedef int (*ScrollCallback)(RefWrapper<WINDOW_BASE, true> Windopw, double xoffset, double yoffset);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowCloseCallback)(RefWrapper<WINDOW_BASE, true> Windopw);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowRefreshCallback)(RefWrapper<WINDOW_BASE, true> Windopw);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowFocusCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int focused);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowIconifyCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int iconified);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*FramebufferSizeCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int width, int height);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowMaximizeCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int maximized);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowContentScaleCallback)(RefWrapper<WINDOW_BASE, true> Windopw, float xscale, float yscale);
    /// <summary>
    /// 
    /// </summary>
    typedef int(*WindowPosCallback)(RefWrapper<WINDOW_BASE, true> Windopw, int xpos, int ypos);
}


#endif // !_CALLBACK_TYPEDEFS_
