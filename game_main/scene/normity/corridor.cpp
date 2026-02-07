/*
 *@文件 ： corridor.cpp
 *@描述 ： 无异常场景大类走廊的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::corridor_set()
{
    // 设置走廊场景初始状态
    c_corridor.background_sprite.setPosition({0.f, 0.f});
    c_corridor.background_sprite.setScale({0.8f, 0.8f});

    corridor_doorleft_set();
    corridor_doorright_set();
    corridor_flower_set();
    corridor_flower_1_set();
    corridor_flower2_set();
    corridor_cabinet_set();
    corridor_cabinet_1_set();
    corridor_notion_board_set();
    corridor_clock_set();
    corridor_toilotman_set();
    corridor_toilotwoman_set();
}

void Scene::corridor_doorleft_set()
{
    c_corridor.door_left_sprite.setOrigin(c_corridor.door_left_sprite.getLocalBounds().size / 2.f);
    c_corridor.door_left_sprite.setPosition({1035.87, 495.794});
    c_corridor.door_left_sprite.setScale({0.85f, 0.85f});
}

void Scene::corridor_doorright_set()
{
    c_corridor.door_right_sprite.setOrigin(c_corridor.door_right_sprite.getLocalBounds().size / 2.f);
    c_corridor.door_right_sprite.setPosition({5860.62, 495.794});
    c_corridor.door_right_sprite.setScale({1.f, 1.f});
}

void Scene::corridor_flower_set()
{
    c_corridor.flower_sprite.setOrigin(c_corridor.flower_sprite.getLocalBounds().size / 2.f);
    c_corridor.flower_sprite.setPosition({1830.0, 590.794});
    c_corridor.flower_sprite.setScale({0.4f, 0.4f});
}

void Scene::corridor_flower_1_set()
{
    c_corridor.flower_1_sprite.setOrigin(c_corridor.flower_1_sprite.getLocalBounds().size / 2.f);
    c_corridor.flower_1_sprite.setPosition({3850.0, 590.794});
    c_corridor.flower_1_sprite.setScale({0.4f, 0.4f});
}

void Scene::corridor_flower2_set()
{
    c_corridor.flower2_sprite.setOrigin(c_corridor.flower2_sprite.getLocalBounds().size / 2.f);
    c_corridor.flower2_sprite.setPosition({2400, 510.794});
    c_corridor.flower2_sprite.setScale({0.5f, 0.5f});
}

void Scene::corridor_cabinet_set()
{
    c_corridor.cabinet_sprite.setOrigin(c_corridor.cabinet_sprite.getLocalBounds().size / 2.f);
    c_corridor.cabinet_sprite.setPosition({2107.26, 490.794});
    c_corridor.cabinet_sprite.setScale({0.7f, 0.7f});
}

void Scene::corridor_cabinet_1_set()
{
    c_corridor.cabinet_1_sprite.setOrigin(c_corridor.cabinet_1_sprite.getLocalBounds().size / 2.f);
    c_corridor.cabinet_1_sprite.setPosition({4108.2, 490.794});
    c_corridor.cabinet_1_sprite.setScale({0.7f, 0.7f});
}

void Scene::corridor_notion_board_set()
{
    c_corridor.notion_board_sprite.setOrigin(c_corridor.notion_board_sprite.getLocalBounds().size / 2.f);
    c_corridor.notion_board_sprite.setPosition({660.649, 420.0});
    c_corridor.notion_board_sprite.setScale({0.58f, 0.58f});
}

void Scene::corridor_clock_set()
{
    c_corridor.clock_sprite.setOrigin(c_corridor.clock_sprite.getLocalBounds().size / 2.f);
    c_corridor.clock_sprite.setPosition({3200.0, 320.0});
    c_corridor.clock_sprite.setScale({0.55f, 0.55f});
}

void Scene::corridor_toilotman_set()
{
    c_corridor.toilotman_sprite.setOrigin(c_corridor.toilotman_sprite.getLocalBounds().size / 2.f);
    c_corridor.toilotman_sprite.setPosition({6265.56, 499.794});
    c_corridor.toilotman_sprite.setScale({0.55f, 0.55f});
}

void Scene::corridor_toilotwoman_set()
{
    c_corridor.toilotwoman_sprite.setOrigin(c_corridor.toilotwoman_sprite.getLocalBounds().size / 2.f);
    c_corridor.toilotwoman_sprite.setPosition({6505.51, 499.794});
    c_corridor.toilotwoman_sprite.setScale({0.55f, 0.55f});
}

void Scene::corridor_player_set_fromstairleft()
{
    c_player.setPosition({351.355, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromstairright()
{
    c_player.setPosition({6805.22, 644.794});
    c_player.setDirection_left();
}

void Scene::corridor_player_set_fromclassroomleft()
{
    c_player.setPosition({1035.87, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromclassroomright()
{
    c_player.setPosition({5894.62, 644.794});
    c_player.setDirection_left();
}

void Scene::corridor_player_set_fromtoilotman()
{
    c_player.setPosition({6276.56, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromtoilotwoman()
{
    c_player.setPosition({6513.51, 644.794});
    c_player.setDirection_right();
}

void Scene::on_corridor_notion_board()
{
    if (c_player.getGlobalBounds().findIntersection(c_corridor.notion_board_sprite.getGlobalBounds()))
    {
        notion_board_text.setString(L"E键查看公告栏");
        notion_board_text.setPosition(c_corridor.notion_board_sprite.getPosition() + sf::Vector2f(-130.f, -150.f));
        notion_board_text.setCharacterSize(40);
        notion_board_text.setFillColor(sf::Color::White);
    }
    else
    {
        notion_board_text.setString(L"");
    }
}

void Scene::on_corridor_stair_left()
{
    if (c_player.getPosition().x <= 351.355f)
    {
        player_text(L"...走这里吗?");
    }
}

void Scene::on_corridor_stair_right()
{
    if (c_player.getPosition().x >= 6805.22f)
    {
        player_text(L"...走这里吗?");
    }
}

void Scene::corridor_update()
{
    on_corridor_notion_board();
    on_corridor_stair_left();
    on_corridor_stair_right();
}

void Scene::corridor_draw(sf::RenderWindow &c_window)
{
    // 绘制走廊背景
    c_window.draw(c_corridor.background_sprite);
    c_window.draw(c_corridor.door_left_sprite);
    c_window.draw(c_corridor.door_right_sprite);
    c_window.draw(c_corridor.clock_sprite);
    c_window.draw(c_corridor.notion_board_sprite);
    c_window.draw(c_corridor.flower_sprite);
    c_window.draw(c_corridor.flower_1_sprite);
    c_window.draw(c_corridor.flower2_sprite);
    c_window.draw(c_corridor.cabinet_sprite);
    c_window.draw(c_corridor.cabinet_1_sprite);
    c_window.draw(c_corridor.toilotman_sprite);
    c_window.draw(c_corridor.toilotwoman_sprite);
    c_window.draw(notion_board_text);
}

void Scene::corridor_draw_2(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}

void Scene::switch_CorridorToRule()
{
    switchscene(SceneState::Rule);
}

void Scene::switch_CorridorToClassroom()
{
    switchscene(SceneState::Classroom);
    classroom_player_set();
}

void Scene::switch_CorridorToToilot()
{
    switchscene(SceneState::Toilot);
    toilot_player_set();
}

bool Scene::HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (c_corridor.door_left_sprite.getGlobalBounds().contains(c_player.getPosition()))
        {
            switch_CorridorToClassroom();
            return true;
        }
    }
    return false;
}

bool Scene::HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (c_corridor.door_right_sprite.getGlobalBounds().contains(c_player.getPosition()))
        {
            player_text(L"这里好像上锁了");
            return true;
        }
    }
    return false;
}

bool Scene::HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        if (c_corridor.notion_board_sprite.getGlobalBounds().findIntersection(c_player.getGlobalBounds()))
        {
            switch_CorridorToRule();
            return true;
        }
    }
    return false;
}

bool Scene::HandleEvent_Corridor_ontoilotman(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (c_corridor.toilotman_sprite.getGlobalBounds().contains(c_player.getPosition()))
        {
            player_text(L"我似乎不应该进去...");
            return true;
        }
    }
    return false;
}

bool Scene::HandleEvent_Corridor_ontoilotwoman(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (c_corridor.toilotwoman_sprite.getGlobalBounds().contains(c_player.getPosition()))
        {
            switch_CorridorToToilot();
            return true;
        }
    }
    return false;
}

bool Scene::HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (c_player.getPosition().x <= 351.355f)
        {
            answer = 1;
            return true;
        }
    }
    return false;
}

bool Scene::HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (c_player.getPosition().x >= 6805.22f)
        {
            answer = 2;
            return true;
        }
    }
    return false;
}