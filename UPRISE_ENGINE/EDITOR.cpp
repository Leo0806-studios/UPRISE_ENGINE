// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"

#include "DEBUG_LOGGER.h"

#include "GLINCLUDES.h"

#include "HeaderE/CORE/CORE.h"
#include "HeaderE/DATATYPES/D_DATATYPES.h"


#include "ECS.h"
#include "RENDER.h"
//#include "RENDER_DATATYPES.h"
//#include "RENDER_OBJECT_SPAWNING.h"
#include "MESSAGES.h"
//#include "HeaderE/CORE/CORE.h"
//#include "INPUT.h"
//#include "memory"
#include "TEST.h"
#include "RENDER_MATERIAL.h"
#include "PHYSICS.h"
#include "RENDERSETUP.h"
#include "HeaderE/CORE/C_SCENE.h"
#include "HeaderE/DATATYPES/D_TERRAIN_DATA.h"
#include <typeindex>
#define _INCLUDE_TYPE_
#define _INCLUDE_REFLECTION_
#include "HeaderE/CORE/C_REFLECTION.h"
#include "DLL-ENGINE-LINK.h"
#include <HeaderE/CORE/C_CONFIGLOADER.h>
#include "new"
#include "EDITOR.h"
#include "MISC.h"
;
#define FUNC(x,y,z)(IMPORTANT::x)GetProcAddress(IMPORTANT::y,z);

#define BEGIN(x) ImGui::Begin(x);
#define END ImGui::End();
std::shared_ptr<GameObject> EDITOR::Editor::SelectedObj;
std::string EDITOR::Editor::Current_Path;
int EDITOR::Editor::StartEditor()
{
	return 0;
}
static void SearchFolderRecrusively( std::filesystem::path& path) {
	TrPr(ctx, __func__);

	//ImGui::Columns(4);
	if (ImGui::Button("back")) {
		path = path.string().substr(0, path.string().find_last_of('\\'));
		
	}
	ImGui::BeginTable("ASSETS Display", 10);

	int i = 0;
	ImGui::TableNextRow();
	//ImGui::BeginGroup();

	for (auto& Directory_entry : std::filesystem::directory_iterator(path))
	{
		if (i == 9) {
			i = 0;
			ImGui::TableNextRow();
		}
		ImGui::TableSetColumnIndex(i);
		{
			char b[] = "📂";
			auto awea = "\xF0\x9F\x93\x82";
			std::string st = "\xF0\x9F\x93\x82";
			//std::wcout << L"📂";
			if (Directory_entry.is_directory()) {
				ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(255, 0, 0, 50));

				ImGui::BeginChild((const char*)Directory_entry.path().filename().string().c_str(), ImVec2(100, 100));
				ImGui::Button("FOLDER", ImVec2(50, 50));
				ImGui::SameLine(0,0);
				if(ImGui::Button("OPEN", ImVec2(50, 50))) {
					EDITOR::Editor::Current_Path = Directory_entry.path().string();
					path = Directory_entry.path();
					ImGui::EndChild();
					ImGui::PopStyleColor();
					//ImGui::EndTable();
					break;
				}
				ImGui::TextWrapped((const char*)Directory_entry.path().filename().string().c_str());

				ImGui::EndChild();
				ImGui::PopStyleColor();
			}
			else {
				ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(255, 0, 0, 50));

				ImGui::BeginChild((const char*)Directory_entry.path().filename().string().c_str(), ImVec2(100, 100));
				ImGui::Button((const char*)Directory_entry.path().filename().extension().c_str());
				ImGui::TextWrapped((const char*)Directory_entry.path().filename().string().c_str());

				ImGui::EndChild();
				ImGui::PopStyleColor();
			}
		}
	
		i++;
	}
	ImGui::EndTable();
	//ImGui::EndGroup();
	//ImGui::EndMenu();
	TrPrE(ctx)
}
void EDITOR::Editor::DrawEditor()
{
	static std::stringstream sstream;
	static string testlines;
	static bool test = false;
	if (test ==false) {
		test = true;
		static std::ifstream stream;
		stream.open(__FILE__);
		sstream << stream.rdbuf();
		testlines = sstream.str();
	}
	ImGui::ShowDemoWindow();
	{
		ImGui::SetNextWindowSize(ImVec2(1600, 900));
		ImGui::Begin("werewrewr");
		ImGui::InputTextMultiline("Code", &testlines,ImVec2(1600,900));

		ImGui::End();
	}

	 {
		ImGui::Begin("Editor");

		// Show Scene View
		ImGui::Text("Scene View");


		// Show Hierarchy Window
		TrPr(ctx1,"Draw Object List")
		ImGui::Begin("Hierarchy");

		for (const auto& obj : CORE::Scene::activeScene->ObjectsInScene) {
			bool isSelected = false; //= (SelectedObj->uuid == &obj->uuid);

			// Highlight the selected item
			if (isSelected) {
				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0F, 1.0F, 0.0F, 1.0F)); // Yellow for selected
			}

			// Display the game object name and detect selection
			if (ImGui::Selectable(obj->name.c_str(), isSelected)) {
				SelectedObj = obj; // Update the selected object
			}

			if (isSelected) {
				ImGui::PopStyleColor();
			}
			if (ImGui::TreeNode(obj->name.c_str())) {
				// Display children if necessary
				ImGui::TreePop();
			}
		}
		ImGui::End();
		TrPrE(ctx1)
		// Show Inspector Window
			TrPr(ctx2,"Draw Inspector")
		if (SelectedObj) {
			ImGui::Begin("Inspector");
			ImGui::Text("Name: %s", SelectedObj->name.c_str());
			//char buff[100];
			//ImGui::InputText("NAME", SelectedObj->name,0,);
			// char buf1[32] = "template";
			ImGui::InputText("default", SelectedObj->name.data(), 32);
			//SelectedObj->name = buf1;
			//Log << buf1;
			ImGui::Checkbox("Enabled", &SelectedObj->Enabled);
			// Add more properties as needed
			ImGui::DragFloat3("Position", &SelectedObj->TrAnSfOrM->Position.x);
			auto aa = SelectedObj->TrAnSfOrM->rotation.ToRotationVector();
			ImGui::InputFloat3("posa", &aa.x);
			// = SelectedObj->TrAnSfOrM->rotation.ToRotationVector();
			ImGui::SliderFloat3("Rotation", &SelectedObj->TrAnSfOrM->Vec3Rotation.x, -1.5f, 1.5f);
			SelectedObj->TrAnSfOrM->SetRotation(SelectedObj->TrAnSfOrM->Vec3Rotation);
			//if (ImGui::Button("update position")) {
			//	tmp = SelectedObj->TrAnSfOrM->rotation.ToRotationVector();
			//}
			ImGui::SeparatorText("Components");
			for (auto& cmp : SelectedObj->behaviours) {
				ImGui::Text(cmp->compname.c_str());
				cmp->EditorWindow();
			}
			ImGui::SeparatorText("Add components");
			static bool open;
			if (ImGui::Button("Add Component")) {

				open = !open;

			}
			if (open) {
				TrPr(CmpListctx,"Draw Add Component List")
				ImGui::BeginChild("Component List");

				for (auto& a : fact::creators) {

					if (ImGui::Button(a.first.c_str())) {
						//tt te;
						//auto tert = std::make_shared<t>(te);
						// using t =decltype(tert->test());
						// std::any aaa = Test();
						// std::string nm = typeid(t).name();

						//auto a = fact::anys[0].type().name();
						SelectedObj->AddComponent(a.second(), a.first);
					}

				}
				ImGui::EndChild();
				TrPrE(CmpListctx)
			}
			ImGui::End();
		}

		TrPrE(ctx2)

		// Show Toolbar
			TrPr(ctx3,"Draw Toolbar")
		ImGui::Begin("Toolbar");
		if (ImGui::Button("Play")) {
			std::rename("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME.dll", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME_LOADED.dll");

			IMPORTANT::handle = LoadLibrary(IMPORTANT::addrs);
			{
				PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)IMPORTANT::handle;
				PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((BYTE*)IMPORTANT::handle + dosHeader->e_lfanew);
				PIMAGE_EXPORT_DIRECTORY exportDir = (PIMAGE_EXPORT_DIRECTORY)((BYTE*)IMPORTANT::handle + ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

				DWORD* names = (DWORD*)((BYTE*)IMPORTANT::handle + exportDir->AddressOfNames);
				WORD* ordinals = (WORD*)((BYTE*)IMPORTANT::handle + exportDir->AddressOfNameOrdinals);
				DWORD* functions = (DWORD*)((BYTE*)IMPORTANT::handle + exportDir->AddressOfFunctions);

				std::cout << "Exported Functions:\n";
				for (DWORD i = 0; i < exportDir->NumberOfNames; i++) {
					char* functionName = (char*)((BYTE*)IMPORTANT::handle + names[i]);
					DWORD functionRVA = functions[ordinals[i]];
					std::cout << "Function: " << functionName << " at RVA: 0x" << std::hex << functionRVA << std::dec << "\n";
				}
			}
			IMPORTANT::mode = GameMode::GameMode_Play;
			IMPORTANT::Function = (IMPORTANT::externFuction)GetProcAddress(IMPORTANT::handle, "INITIALIZE");

			IMPORTANT::CREATE = (IMPORTANT::create)GetProcAddress(IMPORTANT::handle, "_CREATE");
			IMPORTANT::PRINT = (IMPORTANT::print)GetProcAddress(IMPORTANT::handle, "_PRINT");
			IMPORTANT::Get = (IMPORTANT::GetDatabase)GetProcAddress(IMPORTANT::handle, "GetDatabase");
			IMPORTANT::Set = (IMPORTANT::SetDatabase)GetProcAddress(IMPORTANT::handle, "SetDatabase");
			IMPORTANT::B_Up = (IMPORTANT::BEHAVIOUR_UPDATE)GetProcAddress(IMPORTANT::handle, "BEHAVIOUR_UPDATE");
			IMPORTANT::B_Up_A = FUNC(BEHAVIOUR_UPDATE_AWAKE, handle, "BEHAVIOUR_UPDATE_AWAKE");
			IMPORTANT::B_Up_S = FUNC(BEHAVIOUR_UPDATE_START, handle, "BEHAVIOUR_UPDATE_START")
			IMPORTANT::P_Up = FUNC(PHYSICS_UPDATE, handle, "PHYSICS_UPDATE");
			IMPORTANT::D_E = FUNC(DRAW_EDITOR, handle, "DRAW_EDITOR");
			IMPORTANT::Stop = FUNC(STOP, handle, "STOP");
			IMPORTANT::Function(IMPORTANT::LINK);
			CORE::Scene::Backups_SCENE_obj = CORE::Scene::activeScene_obj;
			IMPORTANT::LINK->Backups_SCENE = CORE::Scene::activeScene;
			//auto get = *CREATE();
			if (IMPORTANT::LINK) {
				IMPORTANT::Set(IMPORTANT::LINK);
			}
			//inst = &get;
			//Log << "instance mam adr is " << inst << "\n";

			// Toggle play mode
		}

		if (ImGui::Button("Pause")) {
			// Toggle pause mode
		}
		if (ImGui::Button("Stop")) {
			IMPORTANT::Stop();
			SelectedObj = NULL;
			CORE::Scene::activeScene_obj = CORE::Scene::Backups_SCENE_obj;
			IMPORTANT::mode = GameMode::GameMode_Stoped;
			IMPORTANT::LINK = IMPORTANT::Get();
			FreeLibrary(IMPORTANT::handle);
			IMPORTANT::handle = NULL;
			IMPORTANT::Function = NULL;
			IMPORTANT::CREATE = NULL;
			IMPORTANT::PRINT = NULL;
			std::rename("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME_LOADED.dll", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME.dll");

			// Stop simulation
		}
		ImGui::End();

		TrPrE(ctx3)

		ImGui::End();
	}





















	{
		TrPr(ctx4,"Draw Test Window")
		ImGui::Begin("TEST");


		ImGui::Text("This is some useful text.");
		if (ImGui::Button("Click Me")) {
			//bb(); // Call the function when the button is clicked
			//spawned = true;

		}
		ImGui::End();
		TrPrE(ctx4)
	}
	{
		TrPr(ctx5,"Draw Asset Window")
		BEGIN("ASSETS");
		static auto assetfolder = CORE::Filehandler::ApplicationPath()+"\\ASSETS";
		static std::filesystem::path pathf(assetfolder);
		SearchFolderRecrusively(pathf);
		END;
		TrPrE(ctx5)
	}
}

void EDITOR::Editor::CompileCode()
{
}

void EDITOR::Editor::Build()
{
}

void EDITOR::Editor::Reload()
{
}

void EDITOR::Editor::SetApplicationMode()
{
}
