/*
 *@ 文件 ： menu.hpp
 *@ 描述 ： 菜单界面的类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include "SFML/Graphics.hpp"
#include "GameStateMachine.hpp"
#include "menuStateMachine.hpp"
#include "music.hpp"

class Menu
{
public:
    // 声明菜单状态机
    MenuStateMachine c_menuState;
    // 获得全局状态机
    GameStateMachine &c_gameState;

    // 获得视图
    sf::View &c_camera;

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
    sf::Text Setting_zoomText;
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
    Menu(GameStateMachine &c_gameState, sf::View &c_camera);
    void Menu_update(sf::RenderWindow &c_window);
    void Menu_draw(sf::RenderWindow &c_window);
    void Menu_loadResources(GameStateMachine &c_gameState);
    void Menu_UpdateText(GameStateMachine &c_gameState, sf::RenderWindow &c_window);

    bool HandleEvent(const sf::Event::KeyPressed &key, sf::RenderWindow &c_window);
    bool HandleEvent(const sf::Event::MouseButtonPressed &mouse, sf::RenderWindow &c_window);
    void handle_setting_change(const sf::Event::MouseButtonPressed &mouse, sf::RenderWindow &c_window);
    template <class T>
    bool HandleEvent(const T &, sf::RenderWindow &c_window) { return false; }
};