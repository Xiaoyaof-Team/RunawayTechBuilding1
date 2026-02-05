/*
 *@ 文件 ： menuStateMachine.hpp
 *@ 描述 ： 菜单状态机类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
// 枚举菜单状态
enum class MenuState
{
    None = 0,
    MainMenu = 1,
    Setting = 2,
    Pause = 3,
    Over = 4,
};

class MenuStateMachine
{
public:
    // 声明菜单状态
    MenuState currentState = MenuState::None;
    // 声明上一次的菜单状态
    // 用于设置时返回主菜单或暂停菜单
    MenuState lastState = MenuState::None;
};