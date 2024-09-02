#pragma once
#ifndef _SCRIPT_SERIALIZER_
#define _SCRIPT_SERIALIZER_
//#include "pch.h"
import MISC;
import std;
import SIGNATURE_MODULE_DEF;
#include "HEADER/EDDITOR_SCRIPT.h"
//#include "HEADER/SIGNATURES.h"
namespace EDITOR {

	class Script_Serializer {
		static std::string Find_Decorated_Name(std::string FuncSig);
		static std::string Create_Decorated_Name(const EDITOR::FuncSig& sig);
		static std::string Create_Decorated_Name(const EDITOR::VarSig& sig);
	public:
		static Serialized_Script Serialize_Script(std::filesystem::path file);
		static std::vector<Serialized_Script> Serialize_Scripts(std::vector<std::filesystem::path> files);
	};

}
#endif // !_SCRIPT_SERIALIZER_
