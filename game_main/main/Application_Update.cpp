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