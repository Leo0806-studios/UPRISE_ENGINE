#pragma once
#ifndef _OBJECT_
#define _OBJECT_
import REF_WRAPPER;

import std;
namespace CORE {
	class Behaviour;
	class Component;
};
/// <summary>
/// Namespace for core functionality
/// </summary>
namespace CORE{
	/// <summary>
/// Baseclass For nearly everything object related in the engine
/// </summary>
	class Object {
	private:
		std::string name;
		bool enabled = true;
	public:
#pragma region Constuctors
		Object() = default;

#pragma endregion
#pragma region destructors
		virtual ~Object() {}
#pragma endregion
#pragma region Functions
#pragma region statics
		template<class T>
		UPRISE_CORE_API	__inline static bool Destroy(RefWrapper<T, true> Object);

		
#pragma endregion
#pragma region Members
		std::string& Name() {
			return name;
		}
		bool& Enabled() {
			return enabled;
		}
#pragma region  const
		const std::string& Name()const {
			return name;
		}
		const bool& Enabled() const{
			return enabled;
		}
#pragma endregion

#pragma endregion
#pragma region virtuals
#pragma endregion

#pragma endregion



	};
}

#endif // !_OBJECT_
