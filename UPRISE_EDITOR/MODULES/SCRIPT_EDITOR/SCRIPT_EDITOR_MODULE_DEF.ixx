// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
#ifdef _DEBUG__
#define EDITOR_INLINE __inline
#else
#define EDITOR_INLINE __forceinline
#endif
#include "HEADER/H_IMGUI.h";

export module SCRIPT_EDITOR_MODULE_DEF;
import std;


export namespace SCRIPT_EDITOR {
	
		class Script {
		public:
			std::filesystem::path paht;
			std::string name;
			std::string Lines;
		};
	
	class Editor {

		static int current_doc;
		static std::vector< Script> scripts;
#define IG ImGui::
		//static int callback(ImGuiInputTextCallbackData* data) {

		//}
		EDITOR_INLINE static void DrawMenue_Bar() {

			IG Begin("bar",0,ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar);
			IG End();
		}
		EDITOR_INLINE static void FindScripts(std::filesystem::path rootdir) {

		}
	public:
		static void DrawEditor() {
			{
				ImGui::Begin("Script Editor");
				ImGui::BeginChild("openscripts", ImVec2(200, 100), 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar || ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
				int i = scripts.size() - 1;
				for (; i >=0; i--) {
					if (ImGui::Button(scripts[i].name.c_str())) {
						current_doc = i;
					}

				}
				ImGui::EndChild();
				//ImGui::BeginChild(scripts[current_doc].name.c_str());
				//
				////ImGuiInputTextCallback ret = callback;
				////ImGui::InputTextMultiline("Code", &scripts[current_doc].Lines,ImVec2(500,500), ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackResize, ret,(void*) & i);
				//ImGui::InputTextMultiline("Code", &scripts[current_doc].Lines);

				//ImGui::EndChild();

				ImGui::End();

			}
		}

	};
}


std::vector< SCRIPT_EDITOR::Script> SCRIPT_EDITOR::Editor::scripts;
int SCRIPT_EDITOR::Editor::current_doc;