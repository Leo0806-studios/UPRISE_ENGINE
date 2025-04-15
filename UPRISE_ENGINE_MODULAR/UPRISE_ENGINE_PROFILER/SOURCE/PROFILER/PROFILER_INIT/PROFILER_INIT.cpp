// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

import UPRISE_ENGINE_PROFILER;

 int UPRISE_ENGINE::PROFILER::Profiler_started(int set)
{
     static int a = 0;
     if (set != 0)
     {
         a = set;
     }
     return a;
}


