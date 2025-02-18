#pragma once
#ifndef _FileHandel_
#define _FileHandel_
import std;
import REF_WRAPPER;
namespace UPRISE_EDITOR {
    class FileHandel {
    private:
        std::filesystem::path path;
        SharedRef<std::ifstream, true> file;
        SharedRef<std::string, true> data;
    public:
        FileHandel() = default;
        ~FileHandel() {}
        SharedRef<std::ifstream, true> LoadFile(std::filesystem::path path) {
            file = CreateSharedRef < std::ifstream, true>();
            file->open(path);
            path = path;
            return file;
        }
        SharedRef<std::string, true> ToString() {
            std::stringstream ss;
            ss << file->rdbuf();

            data = CreateSharedRef<std::string, true>(ss.str());
            //data = ss.str();
            return data;
        }


    };
}

#endif // !_FileHandel_
