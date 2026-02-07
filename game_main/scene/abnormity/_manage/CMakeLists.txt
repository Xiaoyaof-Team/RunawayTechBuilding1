target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/abnormity.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AllAbnormity.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/abnormity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AllAbnormity.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})