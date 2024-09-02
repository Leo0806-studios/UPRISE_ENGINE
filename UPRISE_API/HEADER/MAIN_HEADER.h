#pragma once
#ifndef _MAIN_HEAADER_
#define _MAIN_HEAADER_
#include "pch.h"
class ConfigFile {
public:
	enum ConfigType {
		ConfigType_Building,
		Vehicle,
		Projectile,
		Particle,
		Island,
		AiObject,
		Global,
		Manager,
		VertexShader,
		FragmentShader,
		GeometryShader,
		ComputeShader,
		ConfigType_Material
	};
};
class INTERNAL_FUNCS;
template <typename _T>
struct CompiletimeHash {
public:
	constexpr CompiletimeHash() :inf(typeid(_T)), ahs(inf.hash_code()) {

	}
	using type = _T;
	std::type_info  inf = typeid(_T);

	static const size_t ahs;
	constexpr size_t  constexpr Hash() {
		return  ahs;
	}
};
#undef GetObject;
struct vecTupple {
	std::vector<int> a, b;
};
extern "C" {
	class ObjBase;
	class IMPORTANT {
		friend ObjBase;
		friend UPRISE_API int INIT();
		friend INTERNAL_FUNCS;
		static char* (*PtrToObj)(UUID uuid);
		static char* (*PtrToObjS)(std::string name);
		static vecTupple(*GetVarPos)(std::string typeName);
		static char* (*getComponentS)(std::string name);
		static char* (*getComponent)(UUID uuid);
	};
	UPRISE_API int INIT();
	/// <summary>
	/// Base class for all objects in game(API)
	/// </summary>
	class ObjBase {
	private:
		UUID uuid;
		int* Owner;
		bool* IsEnabled;
		int* HP;
		friend INTERNAL_FUNCS;

	public:
		UPRISE_API static std::shared_ptr<ObjBase> GetObject(std::string name, size_t typehash);
		UPRISE_API static std::shared_ptr<ObjBase> GetObject(UUID uuid, size_t typehash);

		/// <summary>
		/// sets the enabled tate of the Object
		/// </summary>
		/// <param name="enable"></param>
		/// <returns></returns>
		UPRISE_API bool setEnable(bool enable) {
			return *IsEnabled;

		}


		/// <summary>
		/// get if Object is Enabled
		/// </summary>
		/// <returns>returns true if enabled and false if disabled</returns>
		UPRISE_API bool getEnable() {
			return *IsEnabled;
		}
		/// <summary>
		/// Get owner of obj
		/// </summary>
		/// <returns>id of owner</returns>
		UPRISE_API int getOwner() {
			return *Owner;
		}
		/// <summary>
		/// Sets Ownner of Object
		/// </summary>
		/// <returns>id of new ownner (int)</returns>
		UPRISE_API int SetOwner(int id) {
			return *Owner;

		}
		UPRISE_API void DamageObj(int damage) {

		}
		UPRISE_API void SetHp(int hp) {

		}
	};
	class Building :public ObjBase {


	};


	class Vehicle :public ObjBase {

	};
	class Ship :public Vehicle {

	};
	class Plane : public Vehicle {

	};
	class Submarine : public Vehicle {

	};
	class Spaceship : public Vehicle {

	};
	class LandVehicle :public Vehicle {

	};

	UPRISE_API Building CreateFromCFG(std::string name, ConfigFile::ConfigType Type);


}
extern "C" {
	class IMPORTANT;
}
class INTERNAL_FUNCS {
	friend IMPORTANT;
	friend ObjBase;
	template<typename _Ty>
	static std::shared_ptr<_Ty> _internal_get_obj(UUID uuid, int id) {

		switch (id) {

		case 0: {
			char* ptr = (char*)IMPORTANT::PtrToObj(uuid);
			break;
		}
		case 1: {
			char* ptr = (char*)IMPORTANT::PtrToObj(uuid);
			std::shared_ptr<Ship> ret = std::make_shared<Ship>();
			ret->uuid = *(UUID*)ptr[8];
			ret->IsEnabled = (bool*)ptr[24];
			vecTupple tp = IMPORTANT::GetVarPos("C_Ship");
			char* cmptr = (char*)IMPORTANT::getComponent(uuid);
			ret->HP = (int*)cmptr[tp.a[2]];
			return ret;

			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;

		}
		case 4: {
			break;

		}
		case 5: {
			break;

		}
		}
	}
	template<typename _Ty>
	static std::shared_ptr<_Ty> _internal_get_obj(std::string name, int id) {

		switch (id) {

		case 0: {
			char* ptr = (char*)IMPORTANT::PtrToObjS(name);
			break;
		}
		case 1: {
			char* ptr =(char*) IMPORTANT::PtrToObjS(name);
			std::shared_ptr<Ship> ret = std::make_shared<Ship>();
			ret->uuid = *(UUID*)ptr[8];
			ret->IsEnabled = (bool*)ptr[24];
			vecTupple tp = IMPORTANT::GetVarPos("C_Ship");
			char* cmptr = (char*)IMPORTANT::getComponentS(name);
			ret->HP = (int*)cmptr[tp.a[2]];
			
			return ret;
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;

		}
		case 4: {
			break;

		}
		case 5: {
			break;

		}
		}
	}

private:

};
#endif // !_MAIN_HEAADER_
