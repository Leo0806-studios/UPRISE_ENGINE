#pragma once
#ifndef _EDITOR_
#include "pch.h"
#include "MODULE_IMPORTS.h"
#define _EDITOR_
class GameObject;
namespace EDITOR {

	class Editor {

	public:
		static std::shared_ptr<GameObject> SelectedObj;
		static int StartEditor();
		static void DrawEditor();
		static void CompileCode();
		static void Build();
		static void Reload();
		static void SetApplicationMode();
		static std::string Current_Path;

	};
}

#endif
