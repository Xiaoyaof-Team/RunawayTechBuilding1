target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom_desk.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom.hpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor.hpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/mirror.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/rule.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/scene.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/scene.hpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/toilot.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/toilot.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor_clock.cpp
)

target_include_directories(game_start PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})