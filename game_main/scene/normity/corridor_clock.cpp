#include "scene.hpp"
#include <iostream>

std::array<sf::Texture, 13> Corridor::loadClockTextures()
{
    std::array<sf::Texture, 13> temptextures;
    if (!(temptextures[0].loadFromFile("game_main/picture/scene/corridor/clock0.png")) ||
        !(temptextures[1].loadFromFile("game_main/picture/scene/corridor/clock1.png")) ||
        !(temptextures[2].loadFromFile("game_main/picture/scene/corridor/clock2.png")) ||
        !(temptextures[3].loadFromFile("game_main/picture/scene/corridor/clock3.png")) ||
        !(temptextures[4].loadFromFile("game_main/picture/scene/corridor/clock4.png")) ||
        !(temptextures[5].loadFromFile("game_main/picture/scene/corridor/clock5.png")) ||
        !(temptextures[6].loadFromFile("game_main/picture/scene/corridor/clock6.png")) ||
        !(temptextures[7].loadFromFile("game_main/picture/scene/corridor/clock7.png")) ||
        !(temptextures[8].loadFromFile("game_main/picture/scene/corridor/clock8.png")) ||
        !(temptextures[9].loadFromFile("game_main/picture/scene/corridor/clock9.png")) ||
        !(temptextures[10].loadFromFile("game_main/picture/scene/corridor/clock10.png")) ||
        !(temptextures[11].loadFromFile("game_main/picture/scene/corridor/clock11.png")) ||
        !(temptextures[12].loadFromFile("game_main/picture/scene/corridor/clock12.png")))
    {
        std::cerr << "走廊钟表图片加载失败！请检查文件路径！" << std::endl;
    }
    return temptextures;
}

void Scene::corridor_clock_set()
{
    c_corridor.clock_sprite.setOrigin(c_corridor.clock_sprite.getLocalBounds().size / 2.f);
    c_corridor.clock_sprite.setPosition({1300.0, 320.0});
    c_corridor.clock_sprite.setScale({0.55f, 0.55f});
    c_corridor.clock_sprite.setTexture(c_corridor.clock[statistics_levels]);
}