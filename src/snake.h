#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

const int W = 16;
const int H = 16;

enum Dir{STOP,UP,DOWN,LEFT,RIGHT};

class Snake{
public:
	Snake();
	void Init();
	void Move();
	void ChangeDir(Dir d);
	bool GameOver();
	void CreateFood();
	Element DrawUI();
	int GetScore();
	
private:
	std::vector<std::pair<int,int>> body;
	Dir dir;
	int foodX,foodY;
	bool fail;
	int score;
};

#endif
