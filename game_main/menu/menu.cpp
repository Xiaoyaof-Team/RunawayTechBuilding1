/*
 *@ 文件 ： menu.cpp
 *@ 描述 ： 菜单界面的类实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"
#include "GameStateMachine.hpp"

Menu::Menu(GameStateMachine &c_gameState) : c_gameState(c_gameState),
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
                                            Setting_BackText(typeface.Bold),
                                            Pause_ResumeText(typeface.Bold),
                                            Pause_SettingText(typeface.Bold),
                                            Pause_ExitText(typeface.Bold),
                                            Over_RestartText(typeface.Bold),
                                            Over_ExitText(typeface.Bold)
{
    Menu_loadResources(c_gameState);
}

void Menu::Menu_update(sf::RenderWindow &c_window)
{
    switch (c_menuState.currentState)
    {
    case MenuState::None:
        // 不显示任何菜单
        break;
    case MenuState::MainMenu:
        // 更新主菜单选项
        break;
    case MenuState::Setting:
        // 加载最新的设置选项
        Setting_VolumeText.setString(L"音量 : " + std::to_wstring(c_gameState.Volume) + L" %");
        Setting_isFullScreenText.setString(L"显示设置 : " + c_gameState.is_FullScreen);
        Setting_frameRateText.setString(L"帧率限制 : " + c_gameState.Frame_Rate + L" FPS");
        Setting_isMouseleaveText.setString(L"允许鼠标离开 : " + c_gameState.is_MouseLeave_Pause);
        Setting_isMousefollowText.setString(L"鼠标跟随视角 : " + c_gameState.is_Mouse_Follow_Camera);
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
