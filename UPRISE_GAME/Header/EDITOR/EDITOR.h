#pragma once
#ifndef _EDITOR_
#include "pch.h"
#define _EDITOR_

namespace EDITOR {

	class Editor {

	public:
		static int StartEditor();
		static void DrawEditor();
		static void CompileCode();
		static void Build();
		static void Reload();
		static void SetApplicationMode();

	};
}

#endif
