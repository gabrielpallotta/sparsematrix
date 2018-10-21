cmake_minimum_required(VERSION 3.9.2)
project(sparsematrix)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(deps/avltree/include)

add_executable(${PROJECT_NAME} main.cpp)