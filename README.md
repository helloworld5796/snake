# 终端贪吃蛇游戏（FTXUI版）

## 项目介绍
基于C++和FTXUI终端UI库开发的经典贪吃蛇游戏，支持键盘控制、分数统计和游戏结束判断。

## 构建与运行
### 环境要求
- CMake 3.15+
- C++17 编译器（MinGW GCC）

### 构建步骤
```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
./snake.exe