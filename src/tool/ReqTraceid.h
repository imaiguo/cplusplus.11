
#include <map>
#include <atomic>
#include <string>
#include <stdint.h>

class ReqTraceid {
 public:
     ReqTraceid():traceid_(0){}
     
     ~ReqTraceid(){}
     uint64_t getTraceId() { return ++traceid_; }
     
private:
    std::atomic<uint64_t> traceid_;
};
