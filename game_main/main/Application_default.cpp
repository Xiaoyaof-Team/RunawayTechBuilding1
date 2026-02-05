/*
 *@ 文件 ： Application_default.cpp
 *@ 描述 ： 游戏主体框架的类预设配置
 *@ 作者 ： 小恐龙大魔王
 *@ 补充 ：
 *@ 时间 ： 2026-2-1
 */
#include "Application.hpp"
#include "GameStateMachine.hpp"
#include <string>

void Application::CreateDefaultWindow()
{
    // 默认设置帧数
    c_window.setFramerateLimit(std::stoi(c_gameState.Frame_Rate));
    // 禁用按键重复
    c_window.setKeyRepeatEnabled(false);

    // 启用自定义相机
    CreateDefaultCamera();

    // 最后设置显示菜单为主菜单
    c_menu.c_menuState.currentState = MenuState::MainMenu;
}

void Application::CreateDefaultCamera()
{
    c_camera.setSize({1920.f, 1080.f});
    c_camera.setCenter({960.f, 540.f});
    auto windowSize = c_window.getSize();
    UpdateCameraViewPort(windowSize.x, windowSize.y);
}