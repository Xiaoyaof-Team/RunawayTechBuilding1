# RunawayDUT353  
逃离不存在的DUT353  

## 项目基本骨架
RunawayDUT353/
├── LICENSE
├── README.md
└── game_main/
    ├── CMakeLists.txt              # CMake 配置文件
    ├── main.cpp                    # 程序入口
    ├── main/                       # 核心逻辑模块
    │   ├── Application.cpp         # Application 类实现
    │   ├── Application.hpp         # Application 类头文件
    │   ├── Application_default.cpp # 默认初始化与配置
    │   ├── Application_Update.cpp  # 状态更新实现（含 UpdateCamera）
    │   └── GameStateMachine.hpp    # 游戏状态机定义
    ├── menu/                       # 菜单模块
    │   ├── menu.cpp                # 菜单逻辑
    │   ├── menu.hpp                # 菜单头文件
    │   ├── menu_default.cpp        # 菜单默认配置
    │   ├── menu_key.cpp            # 菜单按键处理
    │   ├── menu_mouse.cpp          # 菜单鼠标处理
    │   └── menuStateMachine.hpp    # 菜单状态机定义
    ├── music/                      # 音乐音效模块
    │   ├── music.cpp
    │   ├── music.hpp
    │   └── background/             # 背景音频资源
    │       ├── Mouseclick.mp3
    │       └── rain.mp3
    ├── Picture/                    # 图片资源目录（当前为空）
    │   ├── menu/                   # 菜单图片
    │   ├── player/                 # 玩家贴图
    │   └── scene/                  # 场景贴图
    └── typeface/                   # 字体模块
        ├── type.cpp
        ├── type.hpp
        └── HarmonyOS_Sans_SC/      # 鸿蒙字体库资源
            ├── HarmonyOS_Sans_SC_*.ttf
            └── LICENSE.txt

更新于2-1

2025-2026 DUT ELAB极创组寒假趣味任务
