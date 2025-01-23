// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "MAIN_HEADER.h"
int INIT() {
	return 0;
}
Building CreateFromCFG(std::string name, ConfigFile::ConfigType Type)
{
	return Building();
}

 UPRISE_API std::shared_ptr<ObjBase> ObjBase::GetObject(std::string name, size_t typehash) {
	//int hsh = std::hash<std::string>(typeName);
	 if (typehash == typeid(Ship).hash_code()) {

		 return INTERNAL_FUNCS::_internal_get_obj<Ship>(name,1);
	 }
	 else if (typehash == typeid(Plane).hash_code()) {

	 }
	 else if (typehash == typeid(Submarine).hash_code()) {

	 }
	 else if (typehash == typeid(Spaceship).hash_code()) {

	 }
	 else if (typehash == typeid(LandVehicle).hash_code()) {

	 }
}
 UPRISE_API std::shared_ptr<ObjBase> ObjBase::GetObject(UUID uuid, size_t typehash) {
	 //int hsh = std::hash<std::string>(typeName);
	 if (typehash == typeid(Ship).hash_code()) {

		 return INTERNAL_FUNCS::_internal_get_obj<Ship>(uuid,1);
	 }
	 else if (typehash == typeid(Plane).hash_code()) {

	 }
	 else if (typehash == typeid(Submarine).hash_code()) {

	 }
	 else if (typehash == typeid(Spaceship).hash_code()) {

	 }
	 else if (typehash == typeid(LandVehicle).hash_code()) {

	 }
 }
