// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"

#include "Header/CORE/C_FILELOADER.h"

CORE::FileLoader::FileLoader(Directory* directory)
{
    this->directory = directory;
}

CORE::File CORE::FileLoader::LoadFile(const char* path)
{
    return File();
}

CORE::File CORE::FileLoader::LoadFilesWithExtension(const char* path, const char* extension)
{
    return File();
}

CORE::Directory::Directory(const char* Paht)
{
    this->Path = Paht;
}

std::vector<CORE::Folder> CORE::Directory::GetFolder()
{
    return std::vector<Folder>();
}

CORE::Folder::Folder()
{
}

std::vector<CORE::File> CORE::Folder::GetFiles()
{
    return std::vector<File>();
}
