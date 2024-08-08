
#include "pch.h"

using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;
std::map<std::string, CreatorFunc> fact::creators;
VEC(std::shared_ptr<CORE::Behaviour>) fact::inst;
VEC(std::any) fact::anys;