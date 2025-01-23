// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//#include "pch.h"
#include "HEADER/MAIN_EDITOR_HEADER.h"

std::filesystem::path EDITOR::Editor::AssetPath;
int EDITOR::Editor::Scripts_open;
std::vector<EDITOR::Serialized_Script> EDITOR::Editor::Scripts;