target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassroomwithManything.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassroomwithManything.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})