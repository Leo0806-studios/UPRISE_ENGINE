#pragma once
#ifndef _SCRIPT_FILE_
#define _SCRIPT_FILE_
#include "pch.h"
#include "imgui_stdlib.h"
namespace SCRIPT_EDITOR {
	class Script {
	public:
		std::filesystem::path paht;
		std::string name;
		std::string Lines;
	};
}
#endif