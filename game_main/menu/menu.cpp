/*
 *@ 文件 ： menu.cpp
 *@ 描述 ： 菜单界面的类实现
 *@ 作者 ： 小恐龙大魔王 
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"

Menu::Menu() : backgroundTexture(), backgroundSprite(backgroundTexture),
               titleText(typeface.Black),
               MainMenu_StartText(typeface.Bold),
               MainMenu_SettingText(typeface.Bold),
               MainMenu_ExitText(typeface.Bold),
               Setting_VolumeText(typeface.Bold),
               Setting_isFullScreenText(typeface.Bold),
               Setting_frameRateText(typeface.Bold),
               Setting_isMouseleaveText(typeface.Bold),
               Setting_isMousefollowText(typeface.Bold),
               Setting_BackText(typeface.Bold),
               Pause_ResumeText(typeface.Bold),
               Pause_SettingText(typeface.Bold),
               Pause_ExitText(typeface.Bold),
               Over_RestartText(typeface.Bold),
               Over_ExitText(typeface.Bold)
{
    // 加载背景纹理

    Menu_loadResources();
}

void Menu::Menu_update()
{
    switch (currentState)
    {
    case MenuState::None:
        // 不显示任何菜单
        break;
    case MenuState::MainMenu:
        // 更新主菜单选项
        break;
    case MenuState::Setting:
        // 更新设置菜单选项
        break;
    case MenuState::Pause:
        // 更新暂停菜单选项
        break;
    case MenuState::Over:
        // 更新游戏结束菜单选项
        break;
    default:
        break;
    }
}

void Menu::Menu_draw(sf::RenderWindow& c_window)
{
    switch (currentState)
    {
    case MenuState::None:
        // 不绘制任何菜单
        break;
    case MenuState::MainMenu:
        // 绘制主菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(MainMenu_StartText);
        c_window.draw(MainMenu_SettingText);
        c_window.draw(MainMenu_ExitText);
        break;
    case MenuState::Setting:
        // 绘制设置菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Setting_VolumeText);
        c_window.draw(Setting_isFullScreenText);
        c_window.draw(Setting_frameRateText);
        c_window.draw(Setting_isMouseleaveText);
        c_window.draw(Setting_isMousefollowText);
        c_window.draw(Setting_BackText);
        break;
    case MenuState::Pause:
        // 绘制暂停菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Pause_ResumeText);
        c_window.draw(Pause_SettingText);
        c_window.draw(Pause_ExitText);
        break;
    case MenuState::Over:
        // 绘制游戏结束菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Over_RestartText);
        c_window.draw(Over_ExitText);
        break;
    default:
        break;
    }
}



