/*
 *@ 文件 ： player.cpp
 *@ 描述 ： 角色移动
 *@ 作者 ： 逍遥风鉴事
 *@ 时间 ： 2026-2-4
 */

#include "player.hpp"
#include "Application.hpp"

Player::Player()
    : position(200.0f, 200.0f),
      speed(100.0f),
      timing(0.0f),
      changeTime(0.2f),
      currentFrame(1),
      textures(loadPlayerTextures()),
      sprite(textures[0]),
      scale(0.125f)

{

    sprite.setTexture(textures[1]);
}

std::array<sf::Texture, 6> Player::loadPlayerTextures()
{
    std::array<sf::Texture, 6> temptextures;
    if (!(temptextures[0].loadFromFile("game_main/picture/player/back.png")) ||
        !(temptextures[1].loadFromFile("game_main/picture/player/stand.png")) ||
        !(temptextures[2].loadFromFile("game_main/picture/player/front.png")) ||
        !(temptextures[3].loadFromFile("game_main/picture/player/forward.png")) ||
        !(temptextures[4].loadFromFile("game_main/picture/player/sleep.png")) ||
        !(temptextures[5].loadFromFile("game_main/picture/player/wakeup.png")))
    {
        std::cerr << "加载失败！请检查文件路径！" << std::endl;
    }
    std::cout << "加载成功！" << std::endl;
    return temptextures;
}

void Player::init()
{

    sprite.setTexture(textures[1]);

    sprite.setScale({0.125f, 0.125f});
    // sf::Vector2u texSize = textures[1].getSize();
    // std::cout << "Texture[1] real size: " << texSize.x << "x" << texSize.y << std::endl;

    // sf::IntRect rect = sprite.getTextureRect();
    // std::cout << "Sprite Size: " << rect.size.x << " x " << rect.size.y << std::endl;

    // 计算几何中心，有AI参与
    auto size = sf::Vector2f(textures[0].getSize());
    sprite.setOrigin({size.x / 2.f, size.y / 2.f});
    sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Player::update(float deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        movement.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        movement.x += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        movement.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        movement.y -= 1.f;

    if (movement != sf::Vector2f(0.0f, 0.0f))
    {
        movement = movement.normalized(); // 防止斜着超速
        position += movement * speed * deltaTime;

        // 动画切换时间计算
        timing += deltaTime;
        if (timing >= changeTime)
        {
            timing = 0.0f;
            currentFrame = (currentFrame + 1) % 3;
            sprite.setTexture(textures[currentFrame]);
        }

        // 动画切换
        if (movement.x > 0.f)
        {
            // 向右
            sprite.setScale({-scale, scale});
        }
        else if (movement.x < 0.f)
        {
            // 向左
            sprite.setScale({scale, scale});
        }

        sprite.setPosition(position);
    }
    else
    {
        // 静止
        currentFrame = 0;
        sprite.setTexture(textures[1]);
    }
}

sf::Vector2f Player::getPosition() const
{
    return position;
}