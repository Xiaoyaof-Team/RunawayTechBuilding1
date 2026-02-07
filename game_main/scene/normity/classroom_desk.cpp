/*
 *@文件 ： classroom_desk.cpp
 *@描述 ： 无异常场景大类教室的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::classroom_desk_set()
{
    // 设置讲台内容
    c_classroom.desk_text_sprite.setOrigin(c_classroom.desk_text_sprite.getLocalBounds().size / 2.f);
    c_classroom.desk_text_sprite.setPosition(c_player.getPosition());
    c_classroom.desk_text_sprite.setScale({1.0f, 1.0f});
}

void Scene::classroom_desk_update()
{
    on_classroom_desk_text();
}

void Scene::classroom_desk_draw(sf::RenderWindow &window)
{
    // 默认不绘制任何内容
}

void Scene::classroom_desk_draw_2(sf::RenderWindow &window)
{
    // 绘制讲台内容
    window.draw(c_classroom.desk_text_sprite);
}

bool Scene::HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key)
{
    // 处理与讲台交互的按键事件
    if (key.code == sf::Keyboard::Key::E)
    {
        // 处理点击事件，返回教室场景
        classroom_desk_player_reset();
        switch_DeskToClassroom();
        return true; // 事件已处理
    }
    return false; // 事件未处理
}

void Scene::classroom_desk_player_reset()
{
    // 将人物还原至初始位置
    c_player.setPosition(c_classroom.desk_text_sprite.getPosition());
}

void Scene::switch_DeskToClassroom()
{
    // 切换回教室场景
    text_desk.setString(L"");
    switchscene(SceneState::Classroom);
}

void Scene::on_classroom_desk_text()
{
    // 默认没有刷新事件
}