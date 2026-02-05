/*
 *@ 文件 ： music.cpp
 *@ 描述 ： 创建声源库
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "music.hpp"

// 构造函数
MusicLibrary::MusicLibrary() : backgroundMusic("game_main/music/background/rain.mp3"),
                               mouseClickBuffer("game_main/music/background/Mouseclick.mp3"),
                               mouseClickSound(mouseClickBuffer)
{
    // 播放背景音乐
    backgroundMusic.setVolume(50.f);
    backgroundMusic.setLooping(true);
    backgroundMusic.play();
    mouseClickSound.stop();
    mouseClickSound.setVolume(20.f);
}

// 创建音频库
MusicLibrary c_music;
