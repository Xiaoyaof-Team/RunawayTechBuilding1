add_subdirectory(0_normal)
add_subdirectory(_manage)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/0_normal
${CMAKE_CURRENT_SOURCE_DIR}/_manage)

target_include_directories(game_start PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})