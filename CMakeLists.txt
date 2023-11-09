
cmake_minimum_required(VERSION 3.5)

project (unittest LANGUAGES CXX)

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

aux_source_directory(src/Feature FeatureCPP)
aux_source_directory(src/Utils Utils)

add_executable( ${PROJECT_NAME}
                src/main.cpp
                src/ThreadPool/ThreadPoolTest.cc
                src/Singleton/SingletonTest.cc
                ${FeatureCPP}
                ${Utils}
            )

# if(MSVC)
#     target_compile_options(${PROJECT_NAME} PUBLIC "/Zc:__cplusplus") // 这个设置会让__cplusplus值变为201402
# endif()

INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS} D:/devtools/googletest.1.12.0/debug/include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE log4cplus::log4cplusU gtest)

file( COPY config/log4cplus.properties DESTINATION ./)
