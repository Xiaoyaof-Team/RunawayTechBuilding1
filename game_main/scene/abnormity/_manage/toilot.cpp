/*
 *@文件 ： toilot.cpp
 *@描述 ： 异常父类卫生间的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::toilot_set()
{
    toilot_background_set();
    toilot_door_set();
    toilot_wash_basin_set();
    toilot_mirror_set();
}
void Abnormity::toilot_background_set() { p_s->toilot_background_set(); }
void Abnormity::toilot_door_set() { p_s->toilot_door_set(); }
void Abnormity::toilot_wash_basin_set() { p_s->toilot_wash_basin_set(); }
void Abnormity::toilot_mirror_set() { p_s->toilot_mirror_set(); }
void Abnormity::toilot_player_set() { p_s->toilot_player_set(); }
void Abnormity::switch_ToilotToCorridor()
{
    p_s->switch_ToilotToCorridor();
    this->scene_set();
}
void Abnormity::switch_ToilotToMirror()
{
    p_s->switch_ToilotToMirror();
    this->scene_set();
}
void Abnormity::toilot_update()
{
    on_toilot_mirror();
    on_toilot_wash_basin();
    on_toilot_door();
    on_toilot_lid();
}
void Abnormity::toilot_draw(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_toilot.background_sprite);
    c_window.draw(p_s->c_toilot.door_sprite);
    c_window.draw(p_s->c_toilot.wash_basin_sprite);
    c_window.draw(p_s->c_toilot.mirror_sprite);
    c_window.draw(p_s->mirror_text);
}
void Abnormity::toilot_draw_2(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}
bool Abnormity::HandleEvent_Toilot_ondoor(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Toilot_ondoor(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Toilot_onmirror(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Toilot_onmirror(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Toilot_onwashbasin(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Toilot_onlid(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
void Abnormity::on_toilot_mirror() { p_s->on_toilot_mirror(); }
void Abnormity::on_toilot_wash_basin()
{
    // 空实现
}
void Abnormity::on_toilot_door()
{
    // 空实现
}
void Abnormity::on_toilot_lid()
{
    // 空实现
}

bool Abnormity::isplayerwithtoilot_mirror() { return p_s->isplayerwithtoilotmirror(); }
bool Abnormity::isplayerwithtoilot_door() { return p_s->isplayerwithtoilotdoor(); }
bool Abnormity::isplayerwithtoilot_washbasin() { return p_s->isplayerwithtoilotwashbasin(); }
bool Abnormity::isplayerwithtoilot_lid() { return p_s->isplayerwithtoilotlid(); }