#pragma once
#include <memory>

namespace UPRISE_ENGINE ::RENDER::RENDER_COMMON{
    class WINDOW_BASE;

 
        /// <summary>
    /// 
    /// </summary>
        using KeyInputCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int key, int scancode, int action, int mods);
        /// <summary>
        /// 
        /// </summary>
        using MouseButtonCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int button, int action, int mods);
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
