// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Camera_
#define _Camera_
import REF_WRAPPER;

#include "CORE/BEHAVIOUR/BEHAVIOUR.h";


namespace RENDER {
	class RenderCam;
}
/// <summary>
/// Camera Component    
/// </summary>
class Camera:public CORE::Behaviour {
private:
	/// <summary>
    /// FOV of the camera
	/// </summary>
	float fov;
	/// <summary>
	/// Wrapper pointer to the RenderCam
	/// </summary>
	RefWrapper<RENDER::RenderCam, true> rendercam;
public:
	/// <summary>
	/// Component UUID
	/// </summary>
	static UUID uid;
	/// <summary>
    /// default constructor
	/// </summary>
	Camera() = default;
	~Camera(){}
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
#endif // !_Camera_
