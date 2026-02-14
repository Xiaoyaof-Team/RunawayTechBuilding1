target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassroomWithWrongDesks.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassroomWithWrongDesks.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})