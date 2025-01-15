#include "UUID_INT.h"
//#include "Windows.h"
#include "boost/uuid.hpp"
void INTERNALS__::createUUID(char* uuid_)
{
    //UUID uid;
    boost::uuids::uuid uid2 = boost::uuids::random_generator()();
    //UuidCreate(&uid);
    constexpr int size = sizeof(boost::uuids::uuid); // 16 bytes
  
    memcpy(uuid_, &uid2, size); // copy 16 bytes from uid to uuid


}
