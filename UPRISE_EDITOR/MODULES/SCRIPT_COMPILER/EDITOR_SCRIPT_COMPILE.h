#pragma once
#ifndef _EDITOR_SCRIPT_COMPILE_
#define _EDITOR_SCRIPT_COMPILE_
//#include "pch.h"
import std;
import MISC;
#include "HEADER/SIGNATURES.h"

namespace EDITOR {

	class Copmiler {
	private:
		static int Scn_Dict_recurse(std::vector<std::filesystem::path>* vecToAdd, std::filesystem::path path);
		static int Parse_File( std::ifstream& file, std::filesystem::path& path);


	public:
		static std::map<std::string, Vector_Tupple< FuncSig, VarSig>> File_Sigs;
		static std::vector<std::filesystem::path> Files;
		static std::vector<std::filesystem::path> Scan_Dict(std::filesystem::path path);
		static int Parse_Source_Files(std::vector<std::filesystem::path>& Files);
		static int PrepareCompiling();
		static int Compile(bool full);
		static int Link();
		static int Find_Decorated_Names(std::filesystem::path File);
		static int Create_def_File();
	};
}
#endif // !_EDITOR_SCRIPT_COMPILE_
