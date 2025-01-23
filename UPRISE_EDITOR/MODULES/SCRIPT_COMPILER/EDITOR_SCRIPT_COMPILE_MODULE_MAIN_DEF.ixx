// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
#include "HEADER/MAIN_EDITOR_HEADER.h"

export module EDITOR_SCRIPT_COMPILE_MODULE_MAIN_DEF;
import std;
import SIGNATURE_MODULE_DEF;
import MISC;

export   namespace EDITOR {

	class Copmiler {
	private:
		static int Scn_Dict_recurse(std::vector<std::filesystem::path>* vecToAdd, std::filesystem::path path)
		{
			static int retval;
			for (auto& entry : std::filesystem::directory_iterator(path)) {
				if (entry.is_regular_file()) {
					if (entry.path().extension() == ".h") {
						vecToAdd->push_back(entry.path());
					}
					else
					{
						retval++;
					}
				}
				else {
					Scn_Dict_recurse(vecToAdd, entry.path());
				}
			}
			return retval;
		}
		static int Parse_File(std::ifstream& file, std::filesystem::path& path)
		{


			std::regex function_regex(R"(
		(?:(public|protected|private):)?           # Optional access specifier
		\s*                                        # Optional whitespace
		(static|virtual|inline|const)?              # Optional function qualifiers
		\s*                                        # Optional whitespace
		([\w:<>\s*&]+)                             # Return type (with potential templates, pointers, references, etc.)
		\s+                                        # Whitespace between return type and function name
		(\w+)                                      # Function name
		\s*\(([^)]*)\)                             # Parameters (inside parentheses)
		\s*(const)?                                # Optional const at the end
		\s*(override)?                             # Optional override at the end
	)");
			// std::regex function_regex(R"((\w[\w\s\*&:<>]*)\s+(\w+)::(\w+)\s*\(([^)]*)\)\s*(const)?\s*(override)?\s*(final)?)");

			std::regex variable_regex(R"(
	(?:(public|protected|private):)?           # Optional access specifier
	\s*                                        # Optional whitespace
	(static|const)?                            # Optional qualifiers like static or const
	\s*                                        # Optional whitespace
	([\w:<>\s*&]+)                             # Type (can include templates, pointers, references, etc.)
	\s+                                        # Whitespace between type and variable name
	(\w+)                                      # Variable name
	\s*(=\s*[^;]*)?                            # Optional initializer (anything up to the semicolon)
	\s*;                                       # End of the declaration
)");


			//  std::regex variable_regex(R"((\w[\w\s\*&:<>]*)\s+(\w+)\s*(=\s*[^;]*)?;)");
			std::regex namespace_regex(R"(\bnamespace\s+(\w+)\s*\{?)");

			std::regex class_regex(R"(\bclass\s+(\w+)\s*(?::\s*[\w\s,<>:]+)?\s*\{?)");

			std::string line;
			std::string Filename = path.filename().string();
			std::string Visibility;
			std::string Type;
			int depth = 0;
			struct Stac_Scope {
			public:
				explicit  Stac_Scope(int i, std::string thing) :thing(thing), depth(i) {  }
				std::string thing;
				int depth;
				~Stac_Scope() {}
			};
			std::vector<Stac_Scope> Stack;


			while (std::getline(file, line)) {
				std::smatch match;
				if (std::regex_search(line, match, namespace_regex)) {
					Stack.push_back(Stac_Scope(depth, match[1]));
				}
				if (std::regex_search(line, match, class_regex)) {
					if (std::regex_search(line, match, namespace_regex)) {
						Stack.push_back(Stac_Scope(depth, match[1]));
					}
				}
				if (line.contains("public:")) {
					Visibility = "public";
				}
				if (line.contains("private:")) {
					Visibility = "private:";
				}
				if (line.contains('{')) {
					depth++;
				}
				if (line.contains('}')) {
					depth--;
				}
				if (depth == Stack[Stack.size() - 1].depth) {
					Stack.erase(Stack.end());
				}
				if (std::regex_search(line, match, function_regex)) {
					std::string cs_NS_List = "@";
					for (auto& alm : Stack) {
						cs_NS_List = cs_NS_List + alm.thing;
						cs_NS_List = cs_NS_List + "@";
					}
					File_Sigs[Filename].A.push_back(FuncSig(match[4], cs_NS_List, match[3], match[5], match[6], match[7], Visibility, match[2]));
				}
				else if (std::regex_search(line, match, variable_regex)) {
					std::string cs_NS_List = "@";
					for (auto& alm : Stack) {
						cs_NS_List = cs_NS_List + alm.thing;
						cs_NS_List = cs_NS_List + "@";
					}
					std::string mod;
					if (line.contains("*")) {
						mod = "*";
					}
					else if (line.contains("&")) {
						mod = "&";
					}
					File_Sigs[Filename].B.push_back(VarSig(match[4], match[3], cs_NS_List, match[5], Visibility, match[2], mod));
				}
			}

			return 0;
		}


	public:
		static std::map<std::string, Vector_Tupple< FuncSig, VarSig>> File_Sigs;
		static std::vector<std::filesystem::path> Files;
		static std::vector<std::filesystem::path> Scan_Dict(std::filesystem::path path)
		{
			std::vector<std::filesystem::path> ret;
			Scn_Dict_recurse(&ret, path);

			return ret;
		}
		static int Parse_Source_Files(std::vector<std::filesystem::path>& Files)
		{
			for (auto& File : Files) {
				std::ifstream script;
				script.open(File);


				//std::stringstream scriptstream;
				// read file's buffer contents into streams
				// scriptstream << script.rdbuf();

				if (!Parse_File(script, File)) {
					return -1;
				}
			}

			return 0;
		}
		static int PrepareCompiling()
		{
			Files = Scan_Dict(EDITOR::Editor::AssetPath);

			Parse_Source_Files(Files);
			return 0;
		}
		static int Compile(bool full)
		{
			return 0;
		}
		static int Link()
		{
			return 0;
		}
		static int Find_Decorated_Names(std::filesystem::path File)
		{
			return 0;
		}
		static int Create_def_File()
		{
			return 0;
		}
	};
}




std::map<std::string, Vector_Tupple< EDITOR::FuncSig, EDITOR::VarSig>> EDITOR::Copmiler::File_Sigs;
std::vector<std::filesystem::path> EDITOR::Copmiler::Files;