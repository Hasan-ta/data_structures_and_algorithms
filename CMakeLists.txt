cmake_minimum_required(VERSION 2.8)
project(computer_vision CXX C)

set(SUPERBUILD_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "-Ofast -msse4 -DNDEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "-g")
endif()

add_subdirectory(src)
