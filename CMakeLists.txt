cmake_minimum_required(VERSION 3.5)

project(telemsrv LANGUAGES CXX)

include_directories(inc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

find_library(PTHREAD_LIB pthread)
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp") 
add_executable(telemsrv ${SOURCE_FILES})

target_link_libraries(telemsrv ${PTHREAD_LIB} ${PQXX_LIB} ${PQ_LIB})


