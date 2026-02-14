/*
 *@ 文件 ： menu.cpp
 *@ 描述 ： 菜单界面的类实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"
#include "GameStateMachine.hpp"

Menu::Menu(GameStateMachine &c_gameState, sf::View &c_camera) : c_gameState(c_gameState),
                                                                c_camera(c_camera),
                                                                backgroundTexture(), backgroundSprite(backgroundTexture),
                                                                titleText(typeface.Black),
                                                                MainMenu_StartText(typeface.Bold),
                                                                MainMenu_SettingText(typeface.Bold),
                                                                MainMenu_ExitText(typeface.Bold),
                                                                Setting_VolumeText(typeface.Bold),
                                                                Setting_isFullScreenText(typeface.Bold),
                                                                Setting_frameRateText(typeface.Bold),
                                                                Setting_zoomText(typeface.Bold),
                                                                Setting_isMouseleaveText(typeface.Bold),
                                                                Setting_isMousefollowText(typeface.Bold),
                                                                Setting_isSkipBeginText(typeface.Bold),
                                                                Setting_BackText(typeface.Bold),
                                                                Pause_ResumeText(typeface.Bold),
                                                                Pause_SettingText(typeface.Bold),
                                                                Pause_ExitText(typeface.Bold),
                                                                Over_RestartText(typeface.Bold),
                                                                Over_ExitText(typeface.Bold),
                                                                Win_ExitText(typeface.Bold),
                                                                Win_RestartText(typeface.Bold)
{
    Menu_loadResources(c_gameState);
}

void Menu::Menu_update(sf::RenderWindow &c_window)
{
    if (c_menuState.currentState != MenuState::None)
    {
        // 更新菜单文本内容
        Menu_UpdateText(c_gameState, c_window);
    }
    else
    {
        return;
    }
}

void Menu::Menu_draw(sf::RenderWindow &c_window)
{
    switch (c_menuState.currentState)
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
        c_window.draw(Setting_zoomText);
        c_window.draw(Setting_isMouseleaveText);
        c_window.draw(Setting_isMousefollowText);
        c_window.draw(Setting_isSkipBeginText);
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
    case MenuState::Win:
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Win_RestartText);
        c_window.draw(Win_ExitText);
        break;
    default:
        break;
    }
}
