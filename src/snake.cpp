#include "snake.h"
#include <cstdlib>
#include <ctime>

Snake::Snake(){
	srand((unsigned)time(NULL));
	Init();
}

void Snake::Init(){
	body.clear();
	body.push_back({8,8});
	dir=STOP;
	fail=false;
	score=0;
	CreateFood();
}

void Snake::CreateFood(){
	foodX=rand()%W;
	foodY=rand()%H;
}

void Snake::ChangeDir(Dir d){
	if((dir==UP&&d==DOWN)||(dir==DOWN&&d==UP))return;
	if((dir==LEFT&&d==RIGHT)||(dir==RIGHT&&d==LEFT))return;
	dir=d;
}

void Snake::Move(){
	if(dir==STOP||fail)return;
	auto head=body[0];
	int nx=head.first,ny=head.second;
	if(dir==UP)ny--;
	if(dir==DOWN)ny++;
	if(dir==LEFT)nx--;
	if(dir==RIGHT)nx++;
	
	if(nx<0||nx>=W||ny<0||ny>=H){fail=true;return;}
	for(auto &p:body)if(p.first==nx&&p.second==ny){fail=true;return;}
	
	body.insert(body.begin(),{nx,ny});
	if(nx==foodX&&ny==foodY){
		score+=10;
		CreateFood();
	}else{
		body.pop_back();
	}
}

bool Snake::GameOver(){return fail;}
int Snake::GetScore(){return score;}

Element Snake::DrawUI(){
	std::vector<std::string> grid(H,std::string(W,' '));
	grid[foodY][foodX]='●';
	for(size_t i=0;i<body.size();i++){
		int x=body[i].first,y=body[i].second;
		if(i==0)grid[y][x]='◆';
		else grid[y][x]='■';
	}
	Elements line;
	for(auto &s:grid) line.push_back(text(s));
	return vbox(line);
}
