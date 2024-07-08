#include "CORE.h"

 std::string CORE::Filehandler::ApplicationPath() {

	if (Application_Path.data() == NULL) {


		Application_Path = std::filesystem::current_path().string();
	}
	return Application_Path;
}
