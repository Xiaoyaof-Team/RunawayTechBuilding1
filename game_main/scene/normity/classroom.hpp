/*
 *@ 文件 ： classroom.hpp
 *@ 描述 ： 教室场景大类的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-6
 */
#pragma once
#include <SFML/Graphics.hpp>

class Classroom
{
public:
    sf::Texture background;
    sf::Texture desk;
    sf::Texture classroom_desk_text;
    sf::Texture clock;
    sf::Sprite background_sprite;
    sf::Sprite desk_sprite;
    sf::Sprite desk_text_sprite;
    sf::Sprite clock_sprite;

private:
public:
    Classroom() : background("game_main/picture/scene/classroom/background.png"),
                  desk("game_main/picture/scene/classroom/desk.png"),
                  classroom_desk_text("game_main/picture/scene/classroom/desk_text.png"),
                  clock("game_main/picture/scene/classroom/clock.png"),
                  background_sprite(background),
                  desk_sprite(desk),
                  desk_text_sprite(classroom_desk_text),
                  clock_sprite(clock)
    {
    }

private:
};