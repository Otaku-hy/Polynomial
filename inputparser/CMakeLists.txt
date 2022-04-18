add_library(inputParser "")

target_sources(inputParser 
    PRIVATE
        InputParser.cpp
        InputParser.hpp
)

set_target_properties(inputParser PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED True)
target_include_directories(inputParser PUBLIC .)
target_link_libraries(inputParser PRIVATE polynomial)