cmake_minimum_required(VERSION 3.13)

project(Polynomial LANGUAGES CXX)

add_executable(Poly main.cpp Polynomial.cpp InputParser.cpp Interaction.cpp)
set_target_properties(Poly PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED True)