// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
import <memory>;
import UPRISE_ENGINE_PROFILER;
 UPRISE_ENGINE::PROFILER::ALLOC_OBJECT::ALLOC_OBJECT(size_t size, void* ptr, const char* Type, const char*  File, int Line, const char*  message) {
    //PROFILE_EVENT b(ALLOC(size, ptr, Type, File, Line, message));
    UPRISE_ENGINE::PROFILER::EVENT_QEUE::Add_to_Qeue(std::move(
        std::make_unique<ALLOC>(ALLOC(size, ptr, Type, File, Line, message))
    
    ));
}
