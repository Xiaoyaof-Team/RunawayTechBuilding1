/*
 *@文件 ： AllAbnormity.hpp
 *@描述 ： 异常管理类实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-7
 */
#pragma once
#include <functional>
#include <memory>
#include <map>
#include <vector>
#include <random>
class Scene;
class Abnormity;

class AllAbnormity
{
public:
    Scene *p_s;
    std::unique_ptr<Abnormity> currentAbnormity = nullptr;
    std::map<int, std::function<std::unique_ptr<Abnormity>()>> abnormityFactory;
    std::vector<bool> hasvisited;  // 检查异常是否出现过
    std::random_device rd;         // 随机数生成器
    std::mt19937 gen;              // 随机数引擎
    int currentAbnormityIndex = 0; // 当前异常索引
    int statistics_levels = 13;    // 统计当前游戏状态，默认还剩13关

public:
    AllAbnormity(Scene *scene);

    // 获取当前异常索引
    int getcurrentAbnormityIndex();
    void setcurrentAbnormityIndex(int index);
    int getstatistics_levels();
    void setstatistics_levels(int levels);
    int getRandomLevel(int min, int max);
    bool gethasvisited(int index);
    void sethasvisited(int index);
    void checkAnswer();
    int generateNewLevel();
    void generateLevel();
    void resetLevel();
};