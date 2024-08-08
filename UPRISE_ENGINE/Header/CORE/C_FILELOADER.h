#pragma once
#ifndef _FILELOADER_
#define _FILELOADER_

#include "pch.h"
namespace CORE {

	class File {



	};
	class Folder {

	public :
		Folder();

		std::vector<File> GetFiles();
	};
	class Directory {
	public:
		const char* Path;
		Directory(const char* Paht);

		std::vector<Folder> GetFolder();

	};

	class FileLoader {

	public:
		Directory* directory;
		FileLoader(Directory* directory);
		File LoadFile(const char* path);
		File LoadFilesWithExtension(const char* path,const char* extension);

	};




}
#endif // !_FILELOADER_
