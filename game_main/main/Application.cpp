/*
 *@ 文件 ： Application.cpp
 *@ 描述 ： 游戏主体框架的类方法的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 补充 ：
 *@ 时间 ： 2026-2-1
 */
#include "Application.hpp"

// 构造函数
Application::Application() : c_window(sf::VideoMode({1920, 1080}), "RunawayDUT353"),
    c_menu(c_gameState,c_camera)
{
    CreateDefaultWindow();
}

// 检查程序是否运行
bool Application::IsRunning() const
{
    return c_window.isOpen();
}

// 处理事件
void Application::ProcessEvent()
{
    c_window.handleEvents([this](const auto &Tevent)
                          {
    // 事件被处理则返回true，未被处理则返回false
    if(this->HandleEvent(Tevent)) return;
    if(this->c_menu.HandleEvent(Tevent, c_window)) return; });
}

// 更新游戏状态
void Application::Update()
{
    // 定义时间步长
    auto deltatime = deltaTime.restart().asSeconds();
    // SED: 更新游戏内容
    // 更新菜单状态
    c_menu.Menu_update(c_window);
    // 更新相机
    UpdateCamera();

}

// 刷新显示效果
void Application::Render()
{
    c_window.clear(sf::Color::Black);
    // SED: 渲染游戏内容
    // 渲染菜单
    c_menu.Menu_draw(c_window);

    c_window.display();
}

// 处理窗口调整大小事件
bool Application::HandleEvent(const sf::Event::Resized & resized)
{
    UpdateCameraViewPort(resized.size.x, resized.size.y);
    return true;
}

// 处理关闭事件
bool Application::HandleEvent(const sf::Event::Closed &)
{
    Close();
    return true;
}

bool Application::HandleEvent(const sf::Event::MouseButtonPressed & mouse)
{
    c_music.mouseClickSound.play();
    return false;
}

// 关闭窗口
void Application::Close()
{
    c_window.close();
}
