#pragma once

#include <map>
#include <atomic>
#include <string>
#include <stdint.h>
#include <stdarg.h>

#define ERR_SUCCESS 0
#define ERR_FAILURE 1

// 符合条件返回错误码

#define CONDIT_RETURN(errcode,condit)\
    do{\
        if(condit)\
        {\
             return errcode;\
         }\
    }while(0);

// 符合条件返回
#define CONDIT_RETURN(condit)\
    do{\
        if(condit)\
        {\
             return;\
         }\
    }while(0);

// 符合条件,打印日志,返回错误码
#define CONDIT_RETURN(errcode,condit,messageformat,...)\
    do{\
        if(condit)\
        {\
            LOG_ERROR(messageformat,##__VAR_ARGS__);\
             return errcode;\
         }\
    }while(0);

// 符合条件,打印日志,不返回
#define CONDIT_RETURN(condit,messageformat,...)\
    do{\
        if(condit)\
        {\
            LOG_ERROR(messageformat,##__VAR_ARGS__);\
             return;\
         }\
    }while(0);

// 符合条件,打印日志,返回错误码,设置var=false
#define CONDIT_RETURN(errcode,condit,var,messageformat,...)\
    do{\
        if(condit)\
        {\
            var = false;\
            LOG_ERROR(messageformat,##__VAR_ARGS__);\
             return errcode;\
         }\
    }while(0);

// 符合条件,打印日志,返回错误码,设置var=val
#define CONDIT_RETURN(errcode,condit,var,val,messageformat,...)\
    do{\
        if(condit)\
        {\
            var = val;\
            LOG_ERROR(messageformat,##__VAR_ARGS__);\
             return errcode;\
         }\
    }while(0);

#define SAFE_DELETE_POINTER(p)\
    if((p) != NULL)\
    {\
        delete p;\
        (p) = NULL;\
     }

#define CHECK_BGR_IMAGE(errcode,reqid,bgrimage,message) if(!(bgrimage) || !(bgrimage)->width || !(bgrimage)->height || !(bgrimage)->channels || !(bgrimage)->data )\
    {\
        LOG_FATAL("%s reqid=%s,ivaid bgr image! image=%p,width=%d, height=%d, channels=%d, data=%p",\
            message,\
            reqid,\
            bgrimage,\
            (bgrimage)?(bgrimage)->width    :0,\
            (bgrimage)?(bgrimage)->height   :0,\
            (bgrimage)?(bgrimage)->channels  :0,\
            (bgrimage)?(bgrimage)->data    :nullptr);\
         return errcode;\
     }

//一次请求的id
class ReqTraceid {
 public:
     ReqTraceid():traceid_(0){}
     
     ~ReqTraceid(){}
     uint64_t getTraceId() { return ++traceid_; }
     
private:
    std::atomic<uint64_t> traceid_;
};

static std::map <uint64_t ,const char*> MAP_ERRCODE_DESC = {
    {(uint64_t)ERR_SUCCESS,"ERR_SUCCESS"},
    {(uint64_t)ERR_FAILURE ,"ERR_FAILURE"}
};

const char * GetValueDescription(const std::map<uint64_t,const char*> &mapvalueDesc,uint64_t value) {
    auto it = mapvalueDesc.find(value);
    if ( it != mapvalueDesc.end())
        return it->second;
    return "unkown description of value.";    
}
