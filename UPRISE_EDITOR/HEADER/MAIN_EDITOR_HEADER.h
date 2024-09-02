#pragma once
#ifndef _MAIN_EDITOR_HEADER_
#define _MAIN_EDITOR_HEADER_
//#include "pch.h"
import MISC;
import std;
import DATATYPES_MODULE_MAIN_DEF;
namespace EDITOR {
	class Editor {
	public:
		static std::vector<Serialized_Script> Scripts;
		static std::filesystem::path AssetPath;
		static int Scripts_open;
	//	void t();
	};
}
#endif // !_MAIN_EDITOR_HEADER_
