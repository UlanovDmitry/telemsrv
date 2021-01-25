cmake_minimum_required(VERSION 3.5)

project(telemsrv LANGUAGES CXX)
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

list(APPEND CMAKE_PREFIX_PATH "/opt/tbb")

include_directories(inc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

find_library(PTHREAD_LIB pthread)
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

find_package(TBB REQUIRED)

#include_directories("${TBB_INCLUDE_DIR}")

# set(SOURCES src/main.cpp)
# file(GLOB CS "src/*.c") 
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp") 
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${PTHREAD_LIB} ${PQXX_LIB} ${PQ_LIB} ${TBB_IMPORTED_TARGETS})


