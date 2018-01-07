#include_directories(libs)

add_library(recursion_problems libs/recursion_problems.cpp)
add_executable(testRecursion test/testRecursion.cpp)
target_link_libraries(testRecursion recursion_problems)
