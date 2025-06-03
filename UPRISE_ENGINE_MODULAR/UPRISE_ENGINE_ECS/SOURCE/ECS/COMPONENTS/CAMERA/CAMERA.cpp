// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_ECS;
import UPRISE_ENGINE_CORE;
import std;
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    float& Camera::Fov() {
        //TODO finish Reimplementing

        static float f = 1;
        UE_THROW_NOT_IMPLEMENTED;
        throw std::exception("THIS METHOD IS NOT IMPLEMENTED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       // return f;
    }
    void Camera::Awake()
    {
    }
    void Camera::Update()
    {
    }
    void Camera::Start()
    {
    }
}
