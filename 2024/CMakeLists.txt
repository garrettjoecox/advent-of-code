cmake_minimum_required(VERSION 3.22)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/CMake/toolchain.cmake")
project(advent-2024)
set(CMAKE_CXX_STANDARD 20 CACHE STRING "The C++ standard to use")

file(GLOB_RECURSE days__ RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/days/*.c" "src/days/*.cpp" "src/days/*.h" "src/days/*.hpp")

add_library(days-lib SHARED ${days__})
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE days-lib)
