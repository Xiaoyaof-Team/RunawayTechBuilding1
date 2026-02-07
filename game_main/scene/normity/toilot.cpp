/*
 *@文件 ： toilot.cpp
 *@描述 ： 无异常场景大类厕所的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::toilot_set()
{
    c_toilot.background_sprite.setPosition({0.f, 0.f});
    c_toilot.background_sprite.setScale({0.8f, 0.8f});
    toilot_door_set();
    toilot_wash_basin_set();
    toilot_mirror_set();
}

void Scene::toilot_door_set()
{
    c_toilot.door_sprite.setOrigin(c_toilot.door_sprite.getLocalBounds().size / 2.f);
    c_toilot.door_sprite.setPosition({310.541, 300.698});
    c_toilot.door_sprite.setScale({0.61f, 0.61f});
}

void Scene::toilot_wash_basin_set()
{
    c_toilot.wash_basin_sprite.setOrigin(c_toilot.wash_basin_sprite.getLocalBounds().size / 2.f);
    c_toilot.wash_basin_sprite.setPosition({931.284f, 430.419f});
    c_toilot.wash_basin_sprite.setScale({1.1f, 1.1f});
}

void Scene::toilot_mirror_set()
{
    c_toilot.mirror_sprite.setOrigin(c_toilot.mirror_sprite.getLocalBounds().size / 2.f);
    c_toilot.mirror_sprite.setPosition({931.284f, 200.f});
    c_toilot.mirror_sprite.setScale({1.3f, 1.f});
}

void Scene::toilot_player_set()
{
    c_player.setPosition({302.058, 376.012});
    c_player.setDirection_right();
}

void Scene::switch_ToilotToCorridor()
{
    switchscene(SceneState::Corridor);
    corridor_player_set_fromtoilotwoman();
}

void Scene::switch_ToilotToMirror()
{
    switchscene(SceneState::Mirror);
}

void Scene::toilot_update()
{
    // 处理厕所场景的更新逻辑
    on_toilot_mirror();
}

void Scene::toilot_draw(sf::RenderWindow &c_window)
{
    c_window.draw(c_toilot.background_sprite);
    c_window.draw(c_toilot.door_sprite);
    c_window.draw(c_toilot.wash_basin_sprite);
    c_window.draw(c_toilot.mirror_sprite);
    c_window.draw(mirror_text);
}

void Scene::toilot_draw_2(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}

void Scene::on_toilot_mirror()
{
    if (c_player.getGlobalBounds().contains(c_toilot.mirror_sprite.getGlobalBounds().getCenter()))
    {
        mirror_text.setString(L"E键照镜子");
        mirror_text.setPosition(c_toilot.mirror_sprite.getPosition() + sf::Vector2f(-100.f, -150.f));
        mirror_text.setCharacterSize(40);
        mirror_text.setFillColor(sf::Color::White);
    }
    else
    {
        mirror_text.setString(L"");
    }
}

bool Scene::HandleEvent_Toilot_ondoor(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W && c_player.getGlobalBounds().contains(c_toilot.door_sprite.getGlobalBounds().getCenter()))
    {
        switch_ToilotToCorridor();
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Toilot_onmirror(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E && c_player.getGlobalBounds().contains(c_toilot.mirror_sprite.getGlobalBounds().getCenter()))
    {
        switch_ToilotToMirror();
        return true;
    }
    return false;
}
