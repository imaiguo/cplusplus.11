
cmake_minimum_required(VERSION 3.5)

project (cpp11test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(log4cplus_DIR D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus)

find_package(log4cplus REQUIRED)
if(log4cplus_FOUND)
    message ("log4cplus found")
else()
    message (FATAL_ERROR "log4cplus isnot found")
endif()

link_directories(D:/devtools/googletest.1.12.0/debug/lib)

aux_source_directory(src/NewFeature NewFeatureCPP)

add_executable( ${PROJECT_NAME}
                src/main.cpp
                src/log4cplus_unittest.cc
                src/gtest_unittest.cc
                src/ThreadPool/ThreadPoolTest.cc
                src/Singleton/SingletonTest.cc
                ${NewFeatureCPP}
            )

INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS} D:/devtools/googletest.1.12.0/debug/include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE log4cplus::log4cplusU gtest)

file( COPY config/log4cplus.properties DESTINATION ./)
