#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::scene_set()
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_set();
        break;
    case SceneState::Classroom_desk:
        classroom_desk_set();
        break;
    case SceneState::Corridor:
        corridor_set();
        break;
    case SceneState::Toilot:
        toilot_set();
        break;
    case SceneState::Rule:
        rule_set();
        break;
    case SceneState::Mirror:
        mirror_set();
        break;
    default:
        break;
    }
}

void Abnormity::scene_update()
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_update();
        break;
    case SceneState::Classroom_desk:
        classroom_desk_update();
        break;
    case SceneState::Corridor:
        corridor_update();
        break;
    case SceneState::Toilot:
        toilot_update();
        break;
    case SceneState::Rule:
        rule_update();
        break;
    case SceneState::Mirror:
        mirror_update();
        break;
    default:
        break;
    }
    edge_check_left();
    edge_check_right();
    player_text_update();
}

void Abnormity::scene_draw(sf::RenderWindow &c_window)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_draw(c_window);
        break;
    case SceneState::Classroom_desk:
        classroom_desk_draw(c_window);
        break;
    case SceneState::Corridor:
        corridor_draw(c_window);
        break;
    case SceneState::Toilot:
        toilot_draw(c_window);
        break;
    case SceneState::Rule:
        rule_draw(c_window);
        break;
    case SceneState::Mirror:
        mirror_draw(c_window);
        break;
    default:
        break;
    }
}

void Abnormity::scene_draw_2(sf::RenderWindow &c_window)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_draw_2(c_window);
        break;
    case SceneState::Classroom_desk:
        classroom_desk_draw_2(c_window);
        break;
    case SceneState::Corridor:
        corridor_draw_2(c_window);
        break;
    case SceneState::Toilot:
        toilot_draw_2(c_window);
        break;
    case SceneState::Rule:
        rule_draw_2(c_window);
        break;
    case SceneState::Mirror:
        mirror_draw_2(c_window);
        break;
    default:
        break;
    }
    c_window.draw(p_s->player_word);
}

bool Abnormity::HandleEvent(const sf::Event::KeyPressed &key)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        if (HandleEvent_Classroom_ondesk(key))
            return true;
        if (HandleEvent_Classroom_ondoor(key))
            return true;
        break;
    case SceneState::Classroom_desk:
        if (HandleEvent_Classroom_desk_on(key))
            return true;
        break;
    case SceneState::Corridor:
        if (HandleEvent_Corridor_ondoorleft(key))
            return true;
        if (HandleEvent_Corridor_ondoorright(key))
            return true;
        if (HandleEvent_Corridor_onnotionboard(key))
            return true;
        if (HandleEvent_Corridor_ontoilotman(key))
            return true;
        if (HandleEvent_Corridor_ontoilotwoman(key))
            return true;
        if (HandleEvent_Corridor_stairleft(key))
            return true;
        if (HandleEvent_Corridor_stairright(key))
            return true;
        break;
    case SceneState::Toilot:
        if (HandleEvent_Toilot_ondoor(key))
            return true;
        if (HandleEvent_Toilot_onmirror(key))
            return true;
        break;
    case SceneState::Rule:
        if (HandleEvent_Rule_on(key))
            return true;
        break;
    case SceneState::Mirror:
        if (HandleEvent_Mirror_on(key))
            return true;
        break;
    default:
        break;
    }
    return false;
}

void Abnormity::classroom_set_first() { p_s->classroom_set_first(); }
void Abnormity::classroom_player_set_first() { p_s->classroom_player_set_first(); }
void Abnormity::classroom_set() { p_s->classroom_set(); }
void Abnormity::classroom_player_set() { p_s->classroom_player_set(); }
void Abnormity::classroom_clock_set() { p_s->classroom_clock_set(); }
void Abnormity::classroom_update() { p_s->classroom_update(); }
void Abnormity::classroom_draw(sf::RenderWindow &c_window) { p_s->classroom_draw(c_window); }
void Abnormity::classroom_draw_2(sf::RenderWindow &c_window) { p_s->classroom_draw_2(c_window); }
void Abnormity::switch_ClassroomToCorridor()
{
    p_s->switch_ClassroomToCorridor();
    this->scene_set();
}
void Abnormity::switch_ClassroomToDesk()
{
    p_s->switch_ClassroomToDesk();
    this->scene_set();
}
bool Abnormity::HandleEvent_Classroom_ondesk(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Classroom_ondesk(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Classroom_ondoor(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Classroom_ondoor(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_classroom_desk() { p_s->on_classroom_desk(); }
void Abnormity::on_classroom_door() { p_s->on_classroom_door(); }
void Abnormity::classroom_desk_set() { p_s->classroom_desk_set(); }
void Abnormity::classroom_desk_player_reset() { p_s->classroom_desk_player_reset(); }
void Abnormity::classroom_desk_update() { p_s->classroom_desk_update(); }
void Abnormity::classroom_desk_draw(sf::RenderWindow &c_window) { p_s->classroom_desk_draw(c_window); }
void Abnormity::classroom_desk_draw_2(sf::RenderWindow &c_window) { p_s->classroom_desk_draw_2(c_window); }
void Abnormity::switch_DeskToClassroom()
{
    p_s->switch_DeskToClassroom();
    this->scene_set();
}
bool Abnormity::HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Classroom_desk_on(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_classroom_desk_text() { p_s->on_classroom_desk_text(); }
void Abnormity::corridor_set() { p_s->corridor_set(); }
void Abnormity::corridor_doorleft_set() { p_s->corridor_doorleft_set(); }
void Abnormity::corridor_doorright_set() { p_s->corridor_doorright_set(); }
void Abnormity::corridor_flower_set() { p_s->corridor_flower_set(); }
void Abnormity::corridor_flower_1_set() { p_s->corridor_flower_1_set(); }
void Abnormity::corridor_flower2_set() { p_s->corridor_flower2_set(); }
void Abnormity::corridor_cabinet_set() { p_s->corridor_cabinet_set(); }
void Abnormity::corridor_cabinet_1_set() { p_s->corridor_cabinet_1_set(); }
void Abnormity::corridor_notion_board_set() { p_s->corridor_notion_board_set(); }
void Abnormity::corridor_clock_set() { p_s->corridor_clock_set(); }
void Abnormity::corridor_toilotman_set() { p_s->corridor_toilotman_set(); }
void Abnormity::corridor_toilotwoman_set() { p_s->corridor_toilotwoman_set(); }
void Abnormity::corridor_player_set_fromstairleft() { p_s->corridor_player_set_fromstairleft(); }
void Abnormity::corridor_player_set_fromstairright() { p_s->corridor_player_set_fromstairright(); }
void Abnormity::corridor_player_set_fromclassroomleft() { p_s->corridor_player_set_fromclassroomleft(); }
void Abnormity::corridor_player_set_fromclassroomright() { p_s->corridor_player_set_fromclassroomright(); }
void Abnormity::corridor_player_set_fromtoilotman() { p_s->corridor_player_set_fromtoilotman(); }
void Abnormity::corridor_player_set_fromtoilotwoman() { p_s->corridor_player_set_fromtoilotwoman(); }
void Abnormity::switch_CorridorToRule()
{
    p_s->switch_CorridorToRule();
    this->scene_set();
}
void Abnormity::switch_CorridorToClassroom()
{
    p_s->switch_CorridorToClassroom();
    this->scene_set();
}
void Abnormity::switch_CorridorToToilot()
{
    p_s->switch_CorridorToToilot();
    this->scene_set();
}
bool Abnormity::HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_ondoorleft(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_ondoorright(key); }
bool Abnormity::HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_onnotionboard(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Corridor_ontoilotman(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_ontoilotman(key); }
bool Abnormity::HandleEvent_Corridor_ontoilotwoman(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_ontoilotwoman(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_corridor_notion_board() { p_s->on_corridor_notion_board(); }
void Abnormity::on_corridor_stair_left() { p_s->on_corridor_stair_left(); }
void Abnormity::on_corridor_stair_right() { p_s->on_corridor_stair_right(); }
bool Abnormity::HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_stairleft(key); }
bool Abnormity::HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_stairright(key); }
void Abnormity::corridor_update() { p_s->corridor_update(); }
void Abnormity::corridor_draw(sf::RenderWindow &c_window) { p_s->corridor_draw(c_window); }
void Abnormity::corridor_draw_2(sf::RenderWindow &c_window) { p_s->corridor_draw_2(c_window); }
void Abnormity::rule_set() { p_s->rule_set(); }
void Abnormity::rule_player_reset() { p_s->rule_player_reset(); }
void Abnormity::rule_update() { p_s->rule_update(); }
void Abnormity::rule_draw(sf::RenderWindow &c_window) { p_s->rule_draw(c_window); }
void Abnormity::rule_draw_2(sf::RenderWindow &c_window) { p_s->rule_draw_2(c_window); }
void Abnormity::switch_RuleToCorridor()
{
    p_s->switch_RuleToCorridor();
    this->scene_set();
}
bool Abnormity::HandleEvent_Rule_on(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Rule_on(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_rule() { p_s->on_rule(); }
void Abnormity::toilot_set() { p_s->toilot_set(); }
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
void Abnormity::toilot_update() { p_s->toilot_update(); }
void Abnormity::toilot_draw(sf::RenderWindow &window) { p_s->toilot_draw(window); }
void Abnormity::toilot_draw_2(sf::RenderWindow &window) { p_s->toilot_draw_2(window); }
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
void Abnormity::on_toilot_mirror() { p_s->on_toilot_mirror(); }
void Abnormity::mirror_set() { p_s->mirror_set(); }
void Abnormity::mirror_player_reset() { p_s->mirror_player_reset(); }
void Abnormity::mirror_text_set() { p_s->mirror_text_set(); }
void Abnormity::mirror_update() { p_s->mirror_update(); }
void Abnormity::mirror_draw(sf::RenderWindow &window) { p_s->mirror_draw(window); }
void Abnormity::mirror_draw_2(sf::RenderWindow &window) { p_s->mirror_draw_2(window); }
void Abnormity::switch_MirrorToToilot()
{
    p_s->switch_MirrorToToilot();
    this->scene_set();
}
bool Abnormity::HandleEvent_Mirror_on(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Mirror_on(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::switchscene(SceneState newScene)
{
    p_s->switchscene(newScene);
    this->scene_set();
}
void Abnormity::edge_check_left() { p_s->edge_check_left(); }
void Abnormity::edge_check_right() { p_s->edge_check_right(); }
void Abnormity::player_text(std::wstring text) { p_s->player_text(text); }
void Abnormity::player_text_update() { p_s->player_text_update(); }
