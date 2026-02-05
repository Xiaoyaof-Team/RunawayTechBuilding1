/*
 *@ 文件 ： Application_Update.cpp
 *@ 描述 ： 游戏主体框架状态机的更新
 *@ 作者 ： 小恐龙大魔王
 *@ 补充 ：
 *@ 时间 ： 2026-2-1
 */
#include "Application.hpp"

void Application::UpdateCamera()
{
    // SED: 在这里添加相机更新逻辑

    // 应用更新后的相机视图到窗口
    c_window.setView(c_camera);
}

// 自动调整比例
void Application::UpdateCameraViewPort(uint32_t width, uint32_t height)
{
    float windowRatio = (float)width / (float)height;
    float viewRatio = 1920.f / 1080.f;
    float sizeX = 1.f;
    float sizeY = 1.f;
    float posX = 0.f;
    float posY = 0.f;

    if (windowRatio > viewRatio)
    {
        sizeX = viewRatio / windowRatio;
        posX = (1.f - sizeX) / 2.f;
    }
    else
    {
        sizeY = windowRatio / viewRatio;
        posY = (1.f - sizeY) / 2.f;
    }

    c_camera.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
    c_window.setView(c_camera);
}