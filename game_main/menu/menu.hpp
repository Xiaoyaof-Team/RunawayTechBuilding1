/*
 *@ 文件 ： menu.hpp
 *@ 描述 ： 菜单界面的类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include "SFML/Graphics.hpp"

// 枚举菜单状态
enum class MenuState
{
    None = 0,
    MainMenu = 1,
    Setting = 2,
    Pause = 3,
    Over = 4,
    Quit = 5
};

class Menu
{
public:
    // 声明菜单状态
    MenuState currentState = MenuState::None;
    // 声明上一次的菜单状态
    // 用于设置时返回主菜单或暂停菜单
    MenuState lastState = MenuState::None;
private:
    // 声明纹理贴图
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    // 声明标题
    sf::Text titleText;
    // 声明主菜单选项
    sf::Text MainMenu_StartText;
    sf::Text MainMenu_SettingText;
    sf::Text MainMenu_ExitText;
    // 声明设置菜单选项
    sf::Text Setting_VolumeText;
    sf::Text Setting_isFullScreenText;
    sf::Text Setting_frameRateText;
    sf::Text Setting_isMouseleaveText;
    sf::Text Setting_isMousefollowText;
    sf::Text Setting_BackText;
    // 声明暂停菜单选项
    sf::Text Pause_ResumeText;
    sf::Text Pause_SettingText;
    sf::Text Pause_ExitText;
    // 声明游戏结束菜单选项
    sf::Text Over_RestartText;
    sf::Text Over_ExitText;

public:
    Menu();
    void Menu_update();
    void Menu_draw(sf::RenderWindow& c_window);
    void Menu_loadResources();

    bool HandleEvent(const sf::Event::KeyPressed& key);
    bool HandleEvent(const sf::Event::MouseButtonPressed& mouse);
    template <class T>
    bool HandleEvent(const T&) { return false; }
};