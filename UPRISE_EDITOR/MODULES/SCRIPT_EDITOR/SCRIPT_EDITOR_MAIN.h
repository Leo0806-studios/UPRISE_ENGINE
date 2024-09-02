#pragma once
#ifndef _SCRIPT_EDITOR_MAINN_
#define _SCRIPT_EDITOR_MAINN_
#include "pch.h"
#include "SCRIPT_FILE.h"
#include "HEADER/MAIN_EDITOR_HEADER.h"
namespace SCRIPT_EDITOR {
	class Editor {
		
		static int current_doc;
		static std::vector< Script> scripts;
		static int callback(ImGuiInputTextCallbackData* data) {

		}
	public:
		static void DrawEditor() {
			{
				ImGui::Begin("Script Editor");
				ImGui::BeginChild("openscripts", ImVec2(200, 100), 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar || ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
				for (int i = 0; i <= scripts.size();i++) {
					if (ImGui::Button(scripts[i].name.c_str())) {
						current_doc = i;
					}

				}
				ImGui::EndChild();
				ImGui::BeginChild(scripts[current_doc].name.c_str());
				int i;
				ImGuiInputTextCallback ret = callback;
				//ImGui::InputTextMultiline("Code", &scripts[current_doc].Lines,ImVec2(500,500), ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackResize, ret,(void*) & i);
				ImGui::InputTextMultiline("Code", &scripts[current_doc].Lines);



				ImGui::End();

			}
		}

	};
}
#endif // !_SCRIPT_EDITOR_MAINN_
