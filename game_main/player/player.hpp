/*
 *@ 文件 ： player.hpp
 *@ 描述 ： 角色移动
 *@ 作者 ： 逍遥风鉴事
 *@ 时间 ： 2026-2-4
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Player
{
public:
    Player();

    // 初始化
    void init();

    // 角色计算
    void update(float deltaTime);

    // 角色更新
    void draw(sf::RenderWindow &window);

    // 绘制
    void display();

    // 获取位置
    sf::Vector2f getPosition() const;

private:
    float speed;
    sf::Vector2f position;
    sf::FloatRect hitbox;
    std::array<sf::Texture, 6> textures; // 哈哈好不容易扣完图才知道有雪碧图这个东西
    sf::Texture test;
    sf::Sprite sprite;
    int currentFrame; // 当前画序
    float changeTime; // 动画切换时间
    float timing;
    float scale;

private:
    // 加载角色贴图
    std::array<sf::Texture, 6> loadPlayerTextures();
};

#endif