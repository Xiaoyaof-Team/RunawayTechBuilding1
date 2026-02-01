# ================================================
# 文件：CMakeLists.txt
# 说明：项目CMake的主配置文件，拉取SFML库并配置项目编译选项
# 作者：小恐龙大魔王
# 日期： 2026-2-1
# ================================================
cmake_minimum_required(VERSION 3.50)
project(RunawayDUT353 CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
    typeface/type.cpp
    typeface/type.hpp
    music/music.cpp
    music/music.hpp
)

target_include_directories(game_start PRIVATE main menu typeface music)
target_compile_features(game_start PRIVATE cxx_std_20)
target_link_libraries(game_start PRIVATE SFML::Graphics SFML::Audio)