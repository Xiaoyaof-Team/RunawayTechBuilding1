# ================================================
#文件：CMakeLists.txt
#说明：项目CMake的主配置文件，拉取SFML库并配置项目编译选项
#最后更新：2026-2-5
# ================================================
cmake_minimum_required(VERSION 3.50)
project(RunawayDUT353 CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:gb2312>")
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/execution-charset:gb2312>")
    # 移除可能存在的 /utf-8 冲突项
endif()

include(FetchContent)
FetchContent_Declare(sfml GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.2)
FetchContent_MakeAvailable(sfml)

add_executable(game_start 
    main.cpp 
    main/Application.cpp 
    main/Application_default.cpp
    main/Application_Update.cpp
    main/Application.hpp
    main/GameStateMachine.hpp
    menu/menu.cpp 
    menu/menu.hpp
    menu/menu_key.cpp
    menu/menu_mouse.cpp
    menu/menu_default.cpp
    menu/menuStateMachine.hpp
    menu/menu_UpdateText.cpp
    typeface/type.cpp
    typeface/type.hpp
    music/music.cpp
    music/music.hpp
    player/player.cpp
    player/player.hpp
)

add_subdirectory(scene/normity)
add_subdirectory(scene/abnormity)

target_include_directories(game_start PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/main 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu 
    ${CMAKE_CURRENT_SOURCE_DIR}/typeface 
    ${CMAKE_CURRENT_SOURCE_DIR}/music 
    ${CMAKE_CURRENT_SOURCE_DIR}/player 
)

target_compile_features(game_start PRIVATE cxx_std_20)
target_link_libraries(game_start PRIVATE SFML::Graphics SFML::Audio)
