
cmake_minimum_required(VERSION 3.5)

project (unittest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    find_package(log4cplus PATHS "/opt/Data/devtools/log4cplus-2.1.0/lib/cmake/" REQUIRED)
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    find_package(log4cplus PATHS "D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus" REQUIRED)
endif()

find_package(GTest PATHS "/opt/Data/devtools/googletest.1.12.0/lib/cmake/GTest/" REQUIRED)

if(log4cplus_FOUND)
    message ("log4cplus found")
else()
    message (FATAL_ERROR "log4cplus isnot found")
endif()

if(GTest_FOUND)
    message ("GTest found")
    set(GTest_INCLUDE_DIRECTORIES "/opt/Data/devtools/googletest.1.12.0/include")
else()
    message (FATAL_ERROR "GTest isnot found")
endif()

# link_directories(D:/devtools/googletest.1.12.0/debug/lib)
link_directories(/opt/Data/devtools/googletest.1.12.0/lib/)

aux_source_directory(src/features FeaturesCPP)
aux_source_directory(src/tools toolsCPP)

add_executable( ${PROJECT_NAME}
                src/main.cpp
                ${FeaturesCPP}
                ${toolsCPP}
            )

INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS} ${GTest_INCLUDE_DIRECTORIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE log4cplus::log4cplus gtest)

file( COPY config/log4cplus.properties DESTINATION ./)
