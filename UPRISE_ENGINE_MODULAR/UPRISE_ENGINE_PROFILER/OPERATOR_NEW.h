// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_OPERATOR_NEW_
#define UE_OPERATOR_NEW_

     void* operator new(size_t count); //-V3549 //-V2575


#endif // !_OPERATOR_NEW_
#ifndef UE_OPERATOR_DELETE_
#define UE_OPERATOR_DELETE_
     void operator delete(void* ptr); //-V3549 //-V2575

#endif // !_OPERATOR_DELETE_