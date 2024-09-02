
#pragma once
#ifndef _MISC_
#define _MISC_

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
//import Windows;

#define symLoad GetProcAddress 


#include <shellapi.h> // For CommandLineToArgvW
#if defined(min)
#undef min
#endif
#if defined(max)
#undef max
#endif
#if defined(CreateWindow)
#undef CreateWindow
#endif
#include <wrl.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_stdlib.h"
#include "DLL-ENGINE-LINK.h"

#define TD(t,r,p) typedef r(*t)(p);
//#define FUNCI(x,y,z)(IMPORTANT::x)GetProcAddress(IMPORTANT::y,z);
//#define FUNCE(x,y,z)(EDITOR_IMPORTANT::x)GetProcAddress(EDITOR_IMPORTANT::y,z);
#define IM IMPORTANT

import std;
 class EDITOR_IMPORTANT {
public:
    static  const WCHAR* addrs;

    static HINSTANCE EDITORHANDLE;
    TD(INIT, void, ImGuiContext* ctx)
        TD(DRAW, void, void)
        TD(SHUTDOWN, void, void)
        ;
    static SHUTDOWN Shutdown_Editor;
    static INIT init_EDITOR;
    static DRAW Draw_EDITOR;
};

 enum GameMode {
    GameMode_Paused,
    GameMode_Play,
    GameMode_Stoped
};
 class IMPORTANT {
public:

    static DATALINK* LINK;
    static  const WCHAR* addrs;
    static HINSTANCE handle;
    typedef void (*create)();
    typedef void(*print)();
    typedef void(*externFuction)(DATALINK* DATA);
    typedef DATALINK* (*GetDatabase)();
    typedef void(*SetDatabase)(DATALINK*);
    typedef void(*BEHAVIOUR_UPDATE)();
    typedef void(*BEHAVIOUR_UPDATE_AWAKE)();
    typedef void(*BEHAVIOUR_UPDATE_START)();
    typedef void(*PHYSICS_UPDATE)();
    typedef void(*DRAW_EDITOR)();
    typedef void(*STOP)();

    //static test* inst = NULL;

    static create CREATE;
    static print PRINT;
    static externFuction Function;
    static SetDatabase Set;
    static GetDatabase Get;
    static BEHAVIOUR_UPDATE B_Up;
    static BEHAVIOUR_UPDATE_AWAKE B_Up_A;
    static BEHAVIOUR_UPDATE_START B_Up_S;
    static PHYSICS_UPDATE P_Up;
    static DRAW_EDITOR D_E;
    static STOP Stop;
    static GameMode mode;
    //static boost::compute::device device;
   // static boost::compute::context context;
    //static boost::compute::command_queue cq;

};

#endif // !_MISC_
