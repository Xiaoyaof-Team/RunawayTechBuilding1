/* 
 *@ 文件 ： Application.hpp
 *@ 描述 ： 游戏主体框架的类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
*/
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "menu.hpp"

class Application
{
public:

private:
    // 创建窗口
    sf::RenderWindow c_window;
    // 创建时间刻度
    sf::Clock deltaTime;

    // 创建相机
    sf::View c_camera;

    // 创建菜单
    Menu c_menu;
public:
    Application();
    bool IsRunning() const;
    void ProcessEvent();
    void Update();
    void Render();
    void Close();

private:
    bool HandleEvent(const sf::Event::Closed &);
    // 处理其余事件
    template <class T>
    bool HandleEvent(const T &) { return false; }

    
};
