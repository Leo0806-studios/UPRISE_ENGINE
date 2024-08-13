#include "pch.h"

#include "HeaderE/CORE/C_FILELOADER.h"

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
