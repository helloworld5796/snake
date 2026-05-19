#include "snake.h"
#include <ftxui/component/screen_interactive.hpp>
#include <thread>

using namespace ftxui;

int main(){
	auto screen=ScreenInteractive::TerminalOutput();
	Snake game;
	
	auto game_ui=Renderer([&](){
		return hbox({
		game.DrawUI()|border,
		vbox({
			text(" 贪吃蛇游戏 ")|bold|center,
			text("分数："+std::to_string(game.GetScore()))|center,
			text("↑↓←→控制方向")|center,
			text("ESC退出游戏")|center
		})|border
	});
	});
	
	game_ui |= CatchEvent([&](Event e){
		if(e==Event::ArrowUp)game.ChangeDir(UP);
		else if(e==Event::ArrowDown)game.ChangeDir(DOWN);
		else if(e==Event::ArrowLeft)game.ChangeDir(LEFT);
		else if(e==Event::ArrowRight)game.ChangeDir(RIGHT);
		else if(e==Event::Escape)screen.Exit();
		return true;
	});
	
	std::thread t([&](){
		while(!game.GameOver()){
			std::this_thread::sleep_for(std::chrono::milliseconds(180));
			game.Move();
		}
	});
	
	screen.Loop(game_ui);
	t.join();
	return 0;
}
