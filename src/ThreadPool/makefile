
appName		:=ThreadPool
buildDir	:=../build/
objDir		:=$(buildDir)obj/
binDir		:=$(buildDir)bin/
#incDir		:=/opt/commonlib/ZeroMQ4.3.0/include

libDir		:=$(buildDir)bin/

cxxSrc		:=$(shell find * -name "*.cpp")


cc			:= g++

ccflag		:=$(foreach includedir,$(incDir),-I$(includedir)) -m64 -std=c++11 -O2
lkflag		:=$(addprefix -L,$(libDir)) -O2

cxxObj		:=$(patsubst %.cpp,%.o,$(cxxSrc))
allObj		:=$(addprefix $(objDir),$(cxxObj))


$(appName):$(cxxObj)
	$(cc) -o $(binDir)$@ $(allObj) $(lkflag) -lglog -lpthread -L$(binDir) $(LDFLAGS)
	
	
%.o:$(appSrc)%.cpp | buildDir
	$(cc) -fPIC -c $< -o $(objDir)$@   $(ccflag)
	
buildDir:
	@mkdir -p $(objDir)
	@mkdir -p $(binDir)