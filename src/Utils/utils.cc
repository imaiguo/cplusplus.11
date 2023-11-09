#include "utils.h"

namespace Utils{

static std::map <uint64_t ,const char*> MAP_ERRCODE_DESC = {
    {(uint64_t)ERR_SUCCESS,"ERR_SUCCESS"},
    {(uint64_t)ERR_FAILURE ,"ERR_FAILURE"}
};

const char * GetValueDescription(const std::map<uint64_t,const char*> &mapvalueDesc, uint64_t value) {
    auto it = mapvalueDesc.find(value);
    if ( it != mapvalueDesc.end())
        return it->second;
    return "unkown description of value.";    
}

}