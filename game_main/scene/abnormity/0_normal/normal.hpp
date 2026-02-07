/*
 *@文件 ： normal.hpp
 *@描述 ： 无异常实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-7
 */
#pragma once
#include "abnormity.hpp"

class Normal : public Abnormity
{
public:
private:
public:
    using Abnormity::HandleEvent;
    Normal(Scene *scene) : Abnormity(scene) {}

private:
};