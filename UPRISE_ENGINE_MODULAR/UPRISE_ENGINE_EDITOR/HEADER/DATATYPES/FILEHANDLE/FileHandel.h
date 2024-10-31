#pragma once
#ifndef _FileHandel_
#define _FileHandel_
import std;
import REF_WRAPPER;
class FileHandel {
private:
    std::filesystem::path path;
    RefWrapper<std::ifstream,true> file;
    RefWrapper<std::string, true> data;
public:
	FileHandel() = default;
	~FileHandel(){}
    RefWrapper<std::ifstream, true> LoadFile(std::filesystem::path path) {
        file = WrapRef < std::ifstream, true>();
        file->open (path);
        path = path;
        return file;
    }
    RefWrapper<std::string, true> ToString() {
        std::stringstream ss;
        ss << file->rdbuf();
        
        data = WrapRef<std::string, true>(ss.str());
        //data = ss.str();
        return data;
    }

    
};
#endif // !_FileHandel_
