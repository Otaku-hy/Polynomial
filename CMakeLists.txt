cmake_minimum_required(VERSION 3.13)

project(Polynomial LANGUAGES CXX)

add_subdirectory(inputParser)
add_subdirectory(interaction)
add_subdirectory(polynomial)

add_executable(Poly main.cpp)
set_target_properties(Poly PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED True)
target_link_libraries(Poly PRIVATE inputParser interaction polynomial)