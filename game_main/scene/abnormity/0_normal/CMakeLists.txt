# ================================================
#文件：CMakeLists.txt
#说明：无异常类
#最后更新：2026-2-7
# ================================================
target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/normal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/normal.hpp
)
target_include_directories(game_start PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})