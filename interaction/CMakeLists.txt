add_library(interaction "")

target_sources(interaction 
    PRIVATE
        Interaction.cpp
        Interaction.hpp
)

set_target_properties(interaction PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED True)
target_include_directories(interaction PUBLIC .)
target_link_libraries(interaction PRIVATE polynomial inputParser)