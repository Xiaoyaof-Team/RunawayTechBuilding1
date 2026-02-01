/*
 *@ 文件 ： menu_default.cpp
 *@ 描述 ： 菜单界面的类字体背景等预设配置
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"

//SED: AI补全，后续需要调整
void Menu::Menu_loadResources()
{
    // 加载背景纹理
    backgroundTexture.loadFromFile("game_main/menu/resources/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    // 设置标题文本
    titleText.setString("Runaway\nDUT353");
    titleText.setCharacterSize(72);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition({0.f, 0.f}); // 设置标题位置

    // 设置主菜单选项文本与位置
    MainMenu_StartText.setString("Start Game");
    MainMenu_StartText.setCharacterSize(40);
    MainMenu_StartText.setFillColor(sf::Color::White);
    MainMenu_StartText.setPosition({60.f, 300.f});

    MainMenu_SettingText.setString("Settings");
    MainMenu_SettingText.setCharacterSize(40);
    MainMenu_SettingText.setFillColor(sf::Color::White);
    MainMenu_SettingText.setPosition({60.f, 400.f});

    MainMenu_ExitText.setString("Exit");
    MainMenu_ExitText.setCharacterSize(40);
    MainMenu_ExitText.setFillColor(sf::Color::White);
    MainMenu_ExitText.setPosition({60.f, 500.f});

    // 设置设置菜单选项文本与位置
    Setting_VolumeText.setString("Volume");
    Setting_VolumeText.setCharacterSize(30);
    Setting_VolumeText.setFillColor(sf::Color::White);
    Setting_VolumeText.setPosition({60.f, 250.f});

    Setting_isFullScreenText.setString("Full Screen");
    Setting_isFullScreenText.setCharacterSize(30);
    Setting_isFullScreenText.setFillColor(sf::Color::White);
    Setting_isFullScreenText.setPosition({60.f, 320.f});

    Setting_frameRateText.setString("Frame Rate Limit");
    Setting_frameRateText.setCharacterSize(30);
    Setting_frameRateText.setFillColor(sf::Color::White);
    Setting_frameRateText.setPosition({60.f, 390.f});

    Setting_isMouseleaveText.setString("Mouse Leave Pause");
    Setting_isMouseleaveText.setCharacterSize(30);
    Setting_isMouseleaveText.setFillColor(sf::Color::White);
    Setting_isMouseleaveText.setPosition({60.f, 460.f});

    Setting_isMousefollowText.setString("Mouse Follow");
    Setting_isMousefollowText.setCharacterSize(30);
    Setting_isMousefollowText.setFillColor(sf::Color::White);
    Setting_isMousefollowText.setPosition({60.f, 530.f});

    Setting_BackText.setString("Back");
    Setting_BackText.setCharacterSize(30);
    Setting_BackText.setFillColor(sf::Color::White);
    Setting_BackText.setPosition({60.f, 600.f});

    // 设置暂停菜单选项文本与位置
    Pause_ResumeText.setString("Resume");
    Pause_ResumeText.setCharacterSize(40);
    Pause_ResumeText.setFillColor(sf::Color::White);
    Pause_ResumeText.setPosition({60.f, 300.f});

    Pause_SettingText.setString("Settings");
    Pause_SettingText.setCharacterSize(40);
    Pause_SettingText.setFillColor(sf::Color::White);
    Pause_SettingText.setPosition({60.f, 400.f});

    Pause_ExitText.setString("Exit to Main Menu");
    Pause_ExitText.setCharacterSize(40);
    Pause_ExitText.setFillColor(sf::Color::White);
    Pause_ExitText.setPosition({60.f, 500.f});

    // 设置游戏结束菜单选项文本与位置
    Over_RestartText.setString("Restart");
    Over_RestartText.setCharacterSize(40);
    Over_RestartText.setFillColor(sf::Color::White);
    Over_RestartText.setPosition({60.f, 300.f});

    Over_ExitText.setString("Exit to Main Menu");
    Over_ExitText.setCharacterSize(40);
    Over_ExitText.setFillColor(sf::Color::White);
    Over_ExitText.setPosition({60.f, 400.f});
}