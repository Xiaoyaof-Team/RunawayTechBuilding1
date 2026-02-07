/*
 *@文件 ： mirror.cpp
 *@描述 ： 无异常场景大类镜子的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::mirror_set()
{
    c_toilot.mirror_sprite.setOrigin(c_toilot.mirror_sprite.getLocalBounds().size / 2.f);
    c_toilot.mirror_sprite.setPosition(c_player.getPosition());
    c_toilot.mirror_sprite.setScale({8.f, 6.f});
    mirror_text_set();
}

void Scene::mirror_text_set()
{
    mirror_intext.setPosition(c_toilot.mirror_sprite.getPosition() + sf::Vector2f(-200.f, 100.f));
    mirror_intext.setCharacterSize(40);
    mirror_intext.setString(L"一片模糊，什么都看不清");
}

void Scene::mirror_update()
{
}

void Scene::mirror_draw(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}

void Scene::mirror_draw_2(sf::RenderWindow &c_window)
{
    c_window.draw(c_toilot.mirror_sprite);
    c_window.draw(mirror_intext);
}

void Scene::mirror_player_reset()
{
    c_player.setPosition(c_toilot.mirror_sprite.getPosition());
}

void Scene::switch_MirrorToToilot()
{
    mirror_player_reset();
    switchscene(SceneState::Toilot);
}

bool Scene::HandleEvent_Mirror_on(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        switch_MirrorToToilot();
        return true;
    }
    return false;
}