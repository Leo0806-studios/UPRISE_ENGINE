// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Camera_
#define UE_Camera_
import REF_WRAPPER; //-V2575 //-V3549

#include "CORE/BEHAVIOUR/BEHAVIOUR.h"
namespace UPRISE_ENGINE {
    namespace RENDER {
        class RenderCam;
    }
    /// <summary>
    /// Camera Component    
    /// </summary>
    class Camera :public CORE::Behaviour {
    private:

        /// <summary>
        /// Wrapper pointer to the RenderCam
        /// </summary>
        SharedRef<RENDER::RenderCam, true> rendercam;
    public:
        /// <summary>
        /// Component UUID
        /// </summary>
        static UUID uid;
        /// <summary>
/// FOV of the camera
/// </summary>
        float fov;
        char PAD[4];   //TODO find a better way to align this or find data to put here //-V112
        /// <summary>
        /// default constructor
        /// </summary>
        Camera() = default;
        ~Camera() {}
#pragma region Funcs
        /// <summary>
        /// fow changer
        /// </summary>
        /// <returns></returns>
        UPRISE_ECS_API float& Fov();
        /// <summary>
        /// function that gets called when the object is created
        /// </summary>
        /// <returns></returns>
        UPRISE_ECS_API void Awake()override;
        /// <summary>
        /// function that gets called every frame
        /// </summary>
        /// <returns></returns>
        UPRISE_ECS_API void Update()override;
        /// <summary>
        /// replaces the first update of the object.
        /// is run on the next frame after awake
        /// </summary>
        /// <returns></returns>

        UPRISE_ECS_API void Start()override;
#pragma endregion


    };
}


#endif // !_Camera_
