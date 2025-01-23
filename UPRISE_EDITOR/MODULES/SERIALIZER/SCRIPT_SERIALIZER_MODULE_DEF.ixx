// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module SCRIPT_SERIALIZER_MODULE_DEF;
import std;

import DATATYPES_MODULE_MAIN_DEF;
import SIGNATURE_MODULE_DEF;


	export	namespace EDITOR {

		class Script_Serializer {
			static std::string Find_Decorated_Name(std::string FuncSig)
			{
				return std::string();
			}
			static std::string Create_Decorated_Name(const EDITOR::FuncSig& sig)
			{
				std::string DecoratedName = "?";
				DecoratedName = DecoratedName + sig.name;
				DecoratedName = DecoratedName + "@";
				DecoratedName = DecoratedName + sig.Namespace_class_List;
				DecoratedName = DecoratedName + "@";

				return std::string();
			}
			static std::string Create_Decorated_Name(const EDITOR::VarSig& sig)
			{
				std::string DecoratedName = "?";
				DecoratedName = DecoratedName + sig.Name;
				DecoratedName = DecoratedName + "@";
				DecoratedName = DecoratedName + sig.Namespace_class_List;
				DecoratedName = DecoratedName + "@@";

				if (sig.FunctType == "static" && sig.Visibility == "private") {
					DecoratedName = DecoratedName + "0";
				}
				else if (sig.FunctType == "static " && sig.Visibility == "ptotected") {
					DecoratedName = DecoratedName + "1";

				}
				else if (sig.FunctType == "static " && sig.Visibility == "public") {
					DecoratedName = DecoratedName + "2";

				}
				else {
					DecoratedName = DecoratedName + "3";

				}

				DecoratedName = DecoratedName + "V";
				DecoratedName = DecoratedName + sig.Type;
				DecoratedName = DecoratedName + "@@";
				if (sig.Type_Mod == "&") {
					DecoratedName = DecoratedName + "A";

				}
				else if (sig.Type_Mod == "*") {
					DecoratedName = DecoratedName + "P";

				}
				return DecoratedName;
			}
		public:
			static Serialized_Script Serialize_Script(std::filesystem::path file)
			{


				return Serialized_Script();
			}
			static std::vector<Serialized_Script> Serialize_Scripts(std::vector<std::filesystem::path> files)
			{
				std::vector<EDITOR::Serialized_Script> ret;

				for (auto& script : files) {
					Serialized_Script get = EDITOR::Script_Serializer::Serialize_Script(script);
					if (get.FAIL) {
						std::cout << "SERIALIZER encounterd an error during serialization of script " << script.filename() << ".\n" <<
							"script is stored at  " << script << "\n" << "Error Message " << get.Get_Error() << "\n";
						return std::vector<Serialized_Script>();
					}
					else {
						ret.push_back(get);
					}
				}
				return ret;
			}
		};

	}



