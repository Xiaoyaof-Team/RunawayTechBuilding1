/*
 *@ 文件 ： scene.hpp
 *@ 描述 ： 无异常场景大类的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-6
 */
#pragma once
#include <SFML/Graphics.hpp>
#include "classroom.hpp"
#include "corridor.hpp"
#include "toilot.hpp"
#include "type.hpp"
#include "player.hpp"
#include <string>

class GameStateMachine;

enum class SceneState
{
    Classroom = 0,
    Classroom_desk = 1,
    Corridor = 2,
    Toilot = 3,
    Rule = 4,
    Mirror = 5
};

class Scene
{
public:
    // 获得全局状态机
    GameStateMachine &c_gamestate;
    // 场景大类的成员变量
    Classroom c_classroom;
    Corridor c_corridor;
    Toilot c_toilot;

    // 获得人物
    Player &c_player;

    // 场景状态
    SceneState currentSceneState = SceneState::Classroom;
    sf::Sprite *currentSceneBackground;
    sf::Text text_desk; // 作用于与讲台交互的文字

    sf::Text notion_board_text; // 作用于公告栏的文字
    sf::Text mirror_text;
    sf::Text mirror_intext;      // 作用于玩家说话的文字
    sf::Text player_word;        // 作用于玩家说话的文字
    sf::Clock player_word_clock; // 玩家说话文字的计时器

    int answer = 0; // 记录走了哪边

private:
public:
    Scene(GameStateMachine &c_gamestate, Player &c_player) : c_gamestate(c_gamestate),
                                                             c_player(c_player),
                                                             text_desk(typeface.Bold),
                                                             notion_board_text(typeface.Bold),
                                                             mirror_text(typeface.Bold),
                                                             mirror_intext(typeface.Bold),
                                                             player_word(typeface.Regular),
                                                             currentSceneBackground(&c_classroom.background_sprite)
    {
    }
    void classroom_set_first();
    void classroom_player_set_first();

    void classroom_set();
    void classroom_player_set();
    void classroom_clock_set();
    void classroom_update();
    void classroom_draw(sf::RenderWindow &c_window);
    void classroom_draw_2(sf::RenderWindow &c_window);
    void switch_ClassroomToCorridor();
    void switch_ClassroomToDesk();
    bool HandleEvent_Classroom_ondesk(const sf::Event::KeyPressed &key);
    bool HandleEvent_Classroom_ondoor(const sf::Event::KeyPressed &key);

    void on_classroom_desk();
    void on_classroom_door();

    void classroom_desk_set();
    void classroom_desk_player_reset();
    void classroom_desk_update();
    void classroom_desk_draw(sf::RenderWindow &c_window);
    void classroom_desk_draw_2(sf::RenderWindow &c_window);
    void switch_DeskToClassroom();
    bool HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key);

    void on_classroom_desk_text();

    void corridor_set();
    void corridor_doorleft_set();
    void corridor_doorright_set();
    void corridor_flower_set();
    void corridor_flower_1_set();
    void corridor_flower2_set();
    void corridor_cabinet_set();
    void corridor_cabinet_1_set();
    void corridor_notion_board_set();
    void corridor_clock_set();
    void corridor_toilotman_set();
    void corridor_toilotwoman_set();
    void corridor_player_set_fromstairleft();
    void corridor_player_set_fromstairright();
    void corridor_player_set_fromclassroomleft();
    void corridor_player_set_fromclassroomright();
    void corridor_player_set_fromtoilotman();
    void corridor_player_set_fromtoilotwoman();
    void switch_CorridorToRule();
    void switch_CorridorToClassroom();
    void switch_CorridorToToilot();
    bool HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_ontoilotman(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_ontoilotwoman(const sf::Event::KeyPressed &key);

    void on_corridor_notion_board();
    void on_corridor_stair_left();
    void on_corridor_stair_right();

    bool HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key);

    void corridor_update();
    void corridor_draw(sf::RenderWindow &c_window);
    void corridor_draw_2(sf::RenderWindow &c_window);

    void rule_set();
    void rule_player_reset();
    void rule_update();
    void rule_draw(sf::RenderWindow &c_window);
    void rule_draw_2(sf::RenderWindow &c_window);
    void switch_RuleToCorridor();
    bool HandleEvent_Rule_on(const sf::Event::KeyPressed &key);

    void on_rule();

    void toilot_set();
    void toilot_door_set();
    void toilot_wash_basin_set();
    void toilot_mirror_set();
    void toilot_player_set();
    void switch_ToilotToCorridor();
    void switch_ToilotToMirror();
    void toilot_update();
    void toilot_draw(sf::RenderWindow &window);
    void toilot_draw_2(sf::RenderWindow &window);
    bool HandleEvent_Toilot_ondoor(const sf::Event::KeyPressed &key);
    bool HandleEvent_Toilot_onmirror(const sf::Event::KeyPressed &key);

    void on_toilot_mirror();

    void mirror_set();
    void mirror_player_reset();
    void mirror_text_set();
    void mirror_update();
    void mirror_draw(sf::RenderWindow &window);
    void mirror_draw_2(sf::RenderWindow &window);
    void switch_MirrorToToilot();
    bool HandleEvent_Mirror_on(const sf::Event::KeyPressed &key);

    void switchscene(SceneState newScene);
    void edge_check_left();
    void edge_check_right();
    void player_text(std::wstring text);
    void player_text_update();

    template <class T>
    bool HandleEvent(const T &) { return false; }

private:
};