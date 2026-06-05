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
        using CursorPosCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, double xpos, double ypos);
        /// <summary>
        /// 
        /// </summary>
        using ResizeCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int width, int height);
        /// <summary>
        /// 
        /// </summary>
        using CursorEnterCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int entered);
        /// <summary>
        /// 
        /// </summary>
        using ScrollCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, double xoffset, double yoffset);
        /// <summary>
        /// 
        /// </summary>
        using WindowCloseCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw);
        /// <summary>
        /// 
        /// </summary>
        using WindowRefreshCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw);
        /// <summary>
        /// 
        /// </summary>
        using WindowFocusCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int focused);
        /// <summary>
        /// 
        /// </summary>
        using WindowIconifyCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int iconified);
        /// <summary>
        /// 
        /// </summary>
        using FramebufferSizeCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int width, int height);
        /// <summary>
        /// 
        /// </summary>
        using WindowMaximizeCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int maximized);
        /// <summary>
        /// 
        /// </summary>
        using WindowContentScaleCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, float xscale, float yscale);
        /// <summary>
        /// 
        /// </summary>
        using WindowPosCallback = int (*)(std::weak_ptr<WINDOW_BASE> Windopw, int xpos, int ypos);
    

}
