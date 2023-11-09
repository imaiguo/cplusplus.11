#pragma once

#include <map>
#include <string>
#include <stdint.h>

#define ERR_SUCCESS 0
#define ERR_FAILURE 1

namespace Utils{

const char * GetValueDescription(const std::map<uint64_t,const char*> &mapvalueDesc,
                                 uint64_t value);

}