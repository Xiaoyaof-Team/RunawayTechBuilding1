/*
 *@ 文件 ： menu_mouse.cpp
 *@ 描述 ： 菜单界面的类对鼠标事件的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"

bool Menu::HandleEvent(const sf::Event::MouseButtonPressed &mouse)
{
    auto mousePos = (sf::Vector2f)mouse.position;
    // 根据当前菜单状态处理鼠标点击事件
    switch (currentState)
    {
    case MenuState::None:
        // 不处理鼠标事件
        break;
    case MenuState::MainMenu:
        // 处理主菜单鼠标点击事件
        if (MainMenu_StartText.getGlobalBounds().contains(mousePos))
        {
            // 点击开始游戏
            currentState = MenuState::None;
            return true;
        }
        else if (MainMenu_SettingText.getGlobalBounds().contains(mousePos))
        {
            // 点击设置
            // 记录上一次菜单状态
            lastState = currentState;
            currentState = MenuState::Setting;
            return true;
        }
        else if (MainMenu_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击退出游戏
            currentState = MenuState::Over;
            return true;
        }
        break;
    case MenuState::Setting:
        // 处理设置菜单鼠标点击事件
        // SED:还有其他的设置选项未实现，具体的实现待定
        if (Setting_BackText.getGlobalBounds().contains(mousePos))
        {
            // 点击返回
            currentState = lastState;
            return true;
        }
        break;
    case MenuState::Pause:
        // 处理暂停菜单鼠标点击事件
        if (Pause_ResumeText.getGlobalBounds().contains(mousePos))
        {
            // 点击继续游戏
            currentState = MenuState::None;
            return true;
        }
        else if (Pause_SettingText.getGlobalBounds().contains(mousePos))
        {
            // 点击设置
            // 记录上一次菜单状态
            lastState = currentState;
            currentState = MenuState::Setting;
            return true;
        }
        else if (Pause_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击回到主菜单
            // SED：需要使游戏状态机回到初始状态
            currentState = MenuState::MainMenu;
            return true;
        }
        break;
    case MenuState::Over:
        // 处理游戏结束菜单鼠标点击事件
        if (Over_RestartText.getGlobalBounds().contains(mousePos))
        {
            // 点击回到主菜单
            currentState = MenuState::MainMenu;
            return true;
        }
        else if (Over_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击退出游戏
            // SED： 需要调用应用程序的退出函数
            currentState = MenuState::Quit;
            return true;
        }
        break;
    default:
        break;
    }
    return false;
}