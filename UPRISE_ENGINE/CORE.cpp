#include "pch.h"
#include "CORE.h"
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
