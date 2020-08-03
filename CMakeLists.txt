cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(submodules/googletest)

add_subdirectory(Base64)
add_subdirectory(Base64/tests)
add_subdirectory(DataStructures)
add_subdirectory(Graphs)
add_subdirectory(Sorts)
add_subdirectory(Sorts/tests)
add_subdirectory(String)
add_subdirectory(StringUtils)
