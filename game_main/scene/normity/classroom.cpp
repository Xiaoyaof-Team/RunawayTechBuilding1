/*
 *@文件 ： classroom.cpp
 *@描述 ： 无异常场景大类教室的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::classroom_clock_set()
{
    c_classroom.clock_sprite.setPosition({1180.33, 486.686});
    c_classroom.clock_sprite.setScale({0.3f, 0.3f});
}

void Scene::classroom_set_first()
{
    // 设置教室场景初始状态
    c_classroom.background_sprite.setPosition({0.f, 0.f});
    c_classroom.background_sprite.setScale({1.6f, 1.6f});
    c_classroom.desk_sprite.setPosition({430.f, 970.f});
    c_classroom.desk_sprite.setScale({1.3f, 1.3f});
    classroom_clock_set();
}

void Scene::classroom_background_set()
{
    // 设置教室场景初始状态
    c_classroom.background_sprite.setPosition({0.f, 0.f});
    c_classroom.background_sprite.setScale({1.6f, 1.6f});
    c_classroom.desk_sprite.setPosition({430.f, 970.f});
    c_classroom.desk_sprite.setScale({1.3f, 1.3f});
}

void Scene::classroom_player_set()
{
    c_player.setPosition({2249.16, 1023.02});
    c_player.setDirection_left();
}

void Scene::on_classroom_desk()
{
    // 处理与讲台交互的逻辑
    if (c_player.getGlobalBounds().contains(c_classroom.desk_sprite.getGlobalBounds().getCenter() + sf::Vector2f(0.f, -50.f)))
    {
        // 如果玩家与课桌发生碰撞，执行相应的逻辑
        // 例如：阻止玩家继续前进，或者触发某个事件
        text_desk.setString(L"E键查看讲台");
        text_desk.setCharacterSize(40);
        text_desk.setPosition(c_classroom.desk_sprite.getPosition() + sf::Vector2f(700.f, 80.f));
    }
    else
    {
        text_desk.setString(L"");
    }
}

bool Scene::HandleEvent_Classroom_ondesk(const sf::Event::KeyPressed &key)
{
    // 处理与讲台交互的按键事件
    if (key.code == sf::Keyboard::Key::E)
    {
        switch_ClassroomToDesk();
        return true;
    }
    return false;
}

void Scene::switch_ClassroomToDesk()
{
    // 切换到与讲台交互的状态
    switchscene(SceneState::Classroom_desk);
}

bool Scene::HandleEvent_Classroom_ondoor(const sf::Event::KeyPressed &key)
{
    // 处理与教室门交互的按键事件
    if (key.code == sf::Keyboard::Key::W)
    {
        switch_ClassroomToCorridor();
        return true;
    }
    return false;
}

void Scene::switch_ClassroomToCorridor()
{
    switchscene(SceneState::Corridor);
    corridor_player_set_fromclassroomleft();
}

bool Scene::isplayerwithclassroom_desk()
{
    // 判断玩家是否与讲台发生交互
    return c_player.getGlobalBounds().contains(c_classroom.desk_sprite.getGlobalBounds().getCenter() + sf::Vector2f(0.f, -50.f));
}

bool Scene::isplayerwithclassroom_door()
{
    // 判断玩家是否与教室门发生交互
    return c_player.getPosition().x > 2150;
}