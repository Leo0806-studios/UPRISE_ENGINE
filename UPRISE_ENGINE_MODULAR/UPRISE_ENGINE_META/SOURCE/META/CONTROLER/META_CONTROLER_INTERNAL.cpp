#ifdef __INTELLISENSE__
#include "UE_META_INTELLISENSE_FIX.h"
#include <Windows.h>
#include <cstring>
#else 
import UPRISE_ENGINE_META;
import <Windows.h>;
import<cstring>;

#endif // 
inline UPRISE_ENGINE::META::Meta_Obj::Meta_Obj(size_t init_size) {
    Size = init_size;
    m_data = VirtualAlloc(NULL, init_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    VirtualProtect(m_data, init_size, PAGE_EXECUTE_READWRITE, NULL);
}
inline bool UPRISE_ENGINE::META::Meta_Obj::relocate(size_t new_size) {
    void* tmp = VirtualAlloc(NULL, new_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    memcpy(tmp, m_data,  Size);
    VirtualFree(m_data, 0, MEM_RELEASE);
    m_data = tmp;
    return true;
}