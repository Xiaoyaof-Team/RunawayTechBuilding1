/*
 *@ 文件 ： music.hpp
 *@ 描述 ： 声源库类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include "SFML/Audio.hpp"

class MusicLibrary
{
public:
    // 背景音乐
    sf::Music backgroundMusic;

    // 鼠标点击音效
    sf::SoundBuffer mouseClickBuffer;
    sf::Sound mouseClickSound;

public:
    MusicLibrary();
};

extern MusicLibrary c_music;