/*
 *@文件 ： AllAbnormity.cpp
 *@描述 ： 异常管理类实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-7
 */
#include "AllAbnormity.hpp"
#include "abnormity.hpp"
#include "scene.hpp"
#include <random>
#include "normal.hpp"
#include "Application.hpp"
#include "1.ClassroomWithManything/ClassroomwithManything.hpp"
#include "3.CorridorWithWrongBoard/CorridorWithWrongBoard.hpp"

AllAbnormity::AllAbnormity(Scene *scene) : p_s(scene), gen(rd())
{
    // 异常添加处
    abnormityFactory[0] = [this]()
    { return std::make_unique<Normal>(p_s); };
    abnormityFactory[1] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); };
    abnormityFactory[2] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); };
    abnormityFactory[3] = [this]()
    { return std::make_unique<CorridorWithWrongBoard>(p_s); };

    // 初始化hasvisited向量，默认所有异常都未出现过
    // 默认初始异常为Normal
    hasvisited.resize(abnormityFactory.size(), false);
    currentAbnormity = abnormityFactory[0]();
}

// 获取当前异常索引
int AllAbnormity::getcurrentAbnormityIndex()
{
    return currentAbnormityIndex;
}

// 设置当前异常索引
void AllAbnormity::setcurrentAbnormityIndex(int index)
{
    currentAbnormityIndex = index;
}

// 获取当前剩余关卡数
int AllAbnormity::getstatistics_levels()
{
    return p_s->statistics_levels;
}

// 设置当前剩余关卡数
void AllAbnormity::setstatistics_levels(int levels)
{
    p_s->statistics_levels = levels;
}

// 获得关卡随机数
int AllAbnormity::getRandomLevel(int min, int max)
{
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// 获得当前异常是否出现过
bool AllAbnormity::gethasvisited(int index)
{
    return hasvisited[index];
}

// 设置当前异常为已出现
void AllAbnormity::sethasvisited(int index)
{
    hasvisited[index] = true;
}

// 判断是否正确，是则生成新关卡，否则重置当前关卡
void AllAbnormity::checkAnswer(Menu &c_menu)
{
    switch (p_s->answer)
    {
    case 0:
        break;
    case 1:
        // 正常应该走左边
        if (currentAbnormityIndex == 0)
        {
            generateLevel();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairleft();
        }
        else
        {
            std::fill(hasvisited.begin(), hasvisited.end(), false);
            currentAbnormityIndex = 0;
            p_s->statistics_levels = 12;
            currentAbnormity = abnormityFactory[0]();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairleft();
        }
        break;
    case 2:
        // 异常应该走右边
        if (currentAbnormityIndex != 0)
        {
            generateLevel();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairright();
        }
        else
        {
            std::fill(hasvisited.begin(), hasvisited.end(), false);
            currentAbnormityIndex = 0;
            p_s->statistics_levels = 12;
            currentAbnormity = abnormityFactory[0]();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairright();
        }
        break;

    case 3:
        if (p_s->statistics_levels == 1)
        {
            // 游戏胜利
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Classroom);
            c_menu.c_menuState.currentState = MenuState::Win;
        }
        else
        {
            std::fill(hasvisited.begin(), hasvisited.end(), false);
            currentAbnormityIndex = 0;
            p_s->statistics_levels = 12;
            currentAbnormity = abnormityFactory[0]();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairright();
        }
        break;
    }
}

// 生成新的随机数关卡、
int AllAbnormity::generateNewLevel()
{
    // return 3; // 测试用，直接返回对应关卡
    int n = 0;
    while (1)
    {
        if (getRandomLevel(1, 100) < 40)
        {
            return 0;
        }
        int newLevel = getRandomLevel(0, abnormityFactory.size() - 1);
        if (!gethasvisited(newLevel))
        {
            sethasvisited(newLevel);
            return newLevel;
        }
        n++;
        if (n >= 10)
            return 0;
        continue;
    }
}

// 生成新的关卡
void AllAbnormity::generateLevel()
{
    hasvisited[currentAbnormityIndex] = true; // 将当前异常标记为已出现
    int newLevel = generateNewLevel();
    setcurrentAbnormityIndex(newLevel);
    currentAbnormity = abnormityFactory[newLevel]();
    setstatistics_levels(p_s->statistics_levels - 1);
    if (p_s->statistics_levels == 0)
    {
        resetLevel();
    }
}

// 重置关卡
void AllAbnormity::resetLevel()
{
    std::fill(hasvisited.begin(), hasvisited.end(), false);
    currentAbnormityIndex = 0;
    p_s->statistics_levels = 12;
    currentAbnormity = abnormityFactory[0]();
    p_s->answer = 0;
    currentAbnormity->corridor_player_set_fromstairleft();
    currentAbnormity->switch_CorridorToClassroom();
}
