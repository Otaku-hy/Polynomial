add_library(polynomial "")

target_sources(polynomial
    PRIVATE
        Polynomial.cpp
        Polynomial.hpp
)

set_target_properties(polynomial PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED True)
target_include_directories(polynomial PUBLIC .)