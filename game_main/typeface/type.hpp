/*
 *@ 文件 ： type.hpp
 *@ 描述 ： 字体的类声明，引入字体文件
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include "SFML/Graphics.hpp"

class Type
{
public:
    sf::Font Black;
    sf::Font Bold;
    sf::Font Light;
    sf::Font Medium;
    sf::Font Regular;
    sf::Font Thin;

public:
    Type()
    {
        Black.openFromFile("game_main/typeface/HarmonyOS_Sans_SC/HarmonyOS_Sans_SC_Black.ttf");
        Bold.openFromFile("game_main/typeface/HarmonyOS_Sans_SC/HarmonyOS_Sans_SC_Bold.ttf");
        Light.openFromFile("game_main/typeface/HarmonyOS_Sans_SC/HarmonyOS_Sans_SC_Light.ttf");
        Medium.openFromFile("game_main/typeface/HarmonyOS_Sans_SC/HarmonyOS_Sans_SC_Medium.ttf");
        Regular.openFromFile("game_main/typeface/HarmonyOS_Sans_SC/HarmonyOS_Sans_SC_Regular.ttf");
        Thin.openFromFile("game_main/typeface/HarmonyOS_Sans_SC/HarmonyOS_Sans_SC_Thin.ttf");
    }
};

extern Type typeface;