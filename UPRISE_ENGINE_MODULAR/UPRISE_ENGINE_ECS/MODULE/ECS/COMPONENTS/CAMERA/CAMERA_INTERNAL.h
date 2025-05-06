#pragma once
#ifndef UE_CAMERA_INTERNAL_
#define UE_CAMERA_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif


#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "BEHAVIOUR/BEHAVIOUR_INTERNAL.h"
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    namespace RENDER {
        class RenderCam;
    }
    /// <summary>
    /// Camera Component    
    /// </summary>
    class Camera :public Behaviour {
    private:

        /// <summary>
        /// Wrapper pointer to the RenderCam
        /// </summary>
        WeakRef<RENDER::RenderCam, true> rendercam;
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
#endif