
#include "pch.h"
#include "DLL-ENGINE-LINK.h"
#define IM IMPORTANT
using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;
std::map<std::string, CreatorFunc> fact::creators;
std::vector<std::shared_ptr<CORE::Behaviour>> fact::inst;
//VEC(std::any) fact::anys;
//DATALINK* IMPORTANT::LINK;
//const WCHAR* IMPORTANT::addrs = (const WCHAR*)L"C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME_LOADED.dll";
//
//HINSTANCE IMPORTANT::handle = NULL;
//IMPORTANT::create IMPORTANT::CREATE;
//IM::print IM :: PRINT;
//IM::externFuction IM::Function;
//IM::SetDatabase IM::Set;
//IM::GetDatabase IM::Get;
//IM::BEHAVIOUR_UPDATE IM::B_Up;
//IM::BEHAVIOUR_UPDATE_AWAKE IM::B_Up_A;
//IM::BEHAVIOUR_UPDATE_START IM::B_Up_S;
//IM::PHYSICS_UPDATE IM::P_Up;
//IM::DRAW_EDITOR IM::D_E;
//IM::STOP IM::Stop;
//GameMode IM::mode = GameMode::GameMode_Stoped;

void* operator new(std::size_t count)
{
    auto ptr = malloc(count);
    TracyAlloc(ptr, count);
    return ptr;
}

void operator delete(void* ptr) noexcept
{
    TracyFree(ptr);
    free(ptr);
}
//const WCHAR* EDITOR_IMPORTANT::addrs = (const WCHAR*)L"C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\EDITOR\\UPRISE_EDITOR_LOADED.dll";
//HINSTANCE EDITOR_IMPORTANT::EDITORHANDLE = NULL;
//
//EDITOR_IMPORTANT:: SHUTDOWN EDITOR_IMPORTANT::Shutdown_Editor;
//EDITOR_IMPORTANT:: INIT EDITOR_IMPORTANT::init_EDITOR;
//EDITOR_IMPORTANT:: DRAW EDITOR_IMPORTANT::Draw_EDITOR;