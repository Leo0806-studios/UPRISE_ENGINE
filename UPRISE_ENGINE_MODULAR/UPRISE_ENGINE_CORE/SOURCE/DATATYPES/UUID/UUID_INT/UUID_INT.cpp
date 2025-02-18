// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "UUID_INT.h"
#include "Windows.h"
//#include "boost/uuid.hpp"
void INTERNALS__::createUUID(char* uuid_)
{
    UUID uid;
   // boost::uuids::uuid uid2 = boost::uuids::random_generator()();
    UuidCreate(&uid);
    //UuidCreate(&uid);
    //constexpr int size = sizeof(boost::uuids::uuid); // 16 bytes
  
    memcpy(uuid_, &uid, sizeof(UUID)); // copy 16 bytes from uid to uuid


}
