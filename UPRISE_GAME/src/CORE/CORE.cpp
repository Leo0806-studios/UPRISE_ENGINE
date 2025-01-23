// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "Header/CORE/CORE.h"
std::string CORE::Filehandler::Application_Path;
bool CORE::Filehandler::yes = false;
 std::string CORE::Filehandler::ApplicationPath() {
	TrPr(ctx, __func__)
	if (yes == false) {
		yes = true;

		//Application_Path = GetModuleFileNameA();
		char buffer[MAX_PATH];
		DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);
		Application_Path = std::string(buffer, length-18);
	}
	TrPrE(ctx);
	return Application_Path;
}
