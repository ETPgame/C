#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#define N 100
#define NX 30
#define NY 30
#define EDGE 10
#define WX (NX+EDGE+2)*2
#define WY NY+2
#define SCORE_COLOR 0x2
#define BACK_COLOR 0x0
#define BRICK "■"
#define BRICK_COLOR 0xde
#define SNAKE_HEAD "◇"
#define SNAKE_HEAD_COLOR 0xa
#define SNAKE_BODY "●"
#define SNAKE_BODY_COLOR 0xb
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define PAUSE 'p'
#define ESC 27
#define FAST ' '
#define FOOD "☆"
#define FOOD_COLOR 0xc
#define INFO_COLOR 0x4A
typedef struct Snake{
	int x[N];
	int y[N];
	int len;
	int dir;
}Snake;
typedef struct Food{
	int x,y;
	int active;
}Food;
void GotoXY(short y,short x){
	HANDLE app=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD t;
	t.Y=y;
	t.X=x*2;
	SetConsoleCursorPosition(app,t);
}
Food food;
Snake snake;
int ny,nx;
int lasttime;
int movespeed=300;
int snakespeed=300;
int fastspeed=50;
int score=0;
void SetColor(int c){
	HANDLE app=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(app,c);
}
void GameInit(){
	HANDLE app=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ci;
	GetConsoleCursorInfo(app,&ci);
	ci.bVisible=false;
	SetConsoleCursorInfo(app,&ci);
	SetConsoleTitle("Snake");
	COORD size={WX,WY};
	SetConsoleScreenBufferSize(app,size);
	SMALL_RECT rc={0,0,WX-1,WY-1};
	SetConsoleWindowInfo(app,1,&rc);
	snake.len=2;
	snake.x[0]=NX/2;
	snake.y[0]=NY/2;
	snake.x[1]=snake.x[0];
	snake.y[1]=snake.y[0]+1;
	snake.dir=UP;
	srand(time(0));
	lasttime=clock();
}
void PrintScore(){
	GotoXY(NY/2,NX+5);
	printf("%d",score);
	score+=10;
	GotoXY(NY/2,NX+2);
	printf("score:");
}
void RenderMap(){
	char s[WX+1];
	for(int j=0;j<=NX+1;j++)
		sprintf(s+j*2,BRICK);
	s[2*NX+4]='\0';
	SetColor(BRICK_COLOR);
	GotoXY(0,0);
	printf("%s",s);
	GotoXY(NY+1,0);
	printf("%s",s);
	for(int j=1;j<=NY;j++){
		GotoXY(j,0);
		printf("%s",BRICK);
		GotoXY(j,NX+1);
		printf("%s",BRICK);
	}
	SetColor(SCORE_COLOR);
	GotoXY(NY/2-6,NX+2);
	printf("↑↓←→控制方向");
	GotoXY(NY/2-4,NX+2);
	printf("按P暂停游戏");
	GotoXY(NY/2-2,NX+2);
	printf("空格键加速");
	PrintScore();
	GotoXY(NY/2+2,NX+2);
	printf("按下任意键开始游戏");
}
void RenderSnake(){
	SetColor(SNAKE_HEAD_COLOR);
	GotoXY(snake.y[0],snake.x[0]);
	printf("%s",SNAKE_HEAD);
	SetColor(SNAKE_BODY_COLOR);
	for(int i=1;i<snake.len;i++){
		GotoXY(snake.y[i],snake.x[i]);
		printf("%s",SNAKE_BODY);
	}
}void RenderSnakeHead(){
	SetColor(SNAKE_HEAD_COLOR);
	GotoXY(snake.y[0],snake.x[0]);
	printf("%s",SNAKE_HEAD);
}
void RenderSnakeFirst(){
	SetColor(SNAKE_BODY_COLOR);
	GotoXY(snake.y[1],snake.x[1]);
	printf("%s",SNAKE_BODY);
}
void ClearSnakeTail(){
	int k=snake.len-1;
	GotoXY(snake.y[k],snake.x[k]);
	SetColor(BACK_COLOR);
	printf("  ");
}
void NewFood(){
	int i;
	food.active=1;
	while(1){
		food.x=rand()%NX+1;
		food.y=rand()%NY+1;
		for(i=0;i<snake.len;i++){
			if(snake.x[i]==food.x&&snake.y[i]==food.y){
				food.active=0;
			}
		}
		if(food.active==1)return ;
	}
}
void RenderFood(){
	SetColor(FOOD_COLOR);
	GotoXY(food.y,food.x);
	printf("%s",FOOD);
}
void NextPos(){
	ny=snake.y[0];
	nx=snake.x[0];
	switch (snake.dir) {
	case LEFT:
		nx--;
		break;
	case RIGHT:
		nx++;
		break;
	case UP:
		ny--;
		break;
	case DOWN:
		ny++;
		break;
	}
}
void MoveSnake(){
	if(nx==food.x&&ny==food.y){
		snake.len++;
		food.active=0;
	}
	else
		ClearSnakeTail();
	for(int i=snake.len-1;i>0;i--){
		snake.x[i]=snake.x[i-1];
		snake.y[i]=snake.y[i-1];
	}
	snake.x[0]=nx;
	snake.y[0]=ny;
	if(food.active==0){
		NewFood();
		RenderFood();
		PrintScore();
	}
	RenderSnakeHead();
	RenderSnakeFirst();
}
int GetCmd(){
	int c;
	c=getch();
	if(c==224)
		c=getch();
	return c;
}
void Pause(){
	GotoXY(NY/2,NX/2-3);
	SetColor(INFO_COLOR);
	printf("PAUSE...");
	getch();
	GotoXY(NY/2,NX/2-3);
	SetColor(BACK_COLOR);
	printf("        ");
	RenderFood();
	RenderSnake();
	PrintScore();
}
void ExeCmd(int cmd){
	switch (cmd) {
	case LEFT:
		if(snake.dir!=RIGHT)
			snake.dir=LEFT;
		break;
	case RIGHT:
		if(snake.dir!=LEFT)
			snake.dir=RIGHT;
		break;
	case UP:
		if(snake.dir!=DOWN)
			snake.dir=UP;
		break;
	case DOWN:
		if(snake.dir!=UP)
			snake.dir=DOWN;
		break;
	case PAUSE:
		Pause();
		break;
	case FAST:
		snakespeed=fastspeed;
		break;
	case ESC:
		exit(0);
	}
}
int GameOver(){
	int i;
	if(nx<1||nx>NX||ny<1||ny>NY){
		return 1;
	}
	for(i=2;i<snake.len;i++){
		if(nx==snake.x[i]&&ny==snake.y[i])
			return 1;
	}
	return 0;
}
void Firstrecv(){
	while(true){
		if(kbhit()){
			int c=GetCmd();
			ExeCmd(c);
			break;
		}
	}
}
void PlayGame(){
	int now;
	int c;
	while(1){
		snakespeed=movespeed;
		if(kbhit()){
			c=GetCmd();
			ExeCmd(c);
		}
		now=clock();
		if(now-lasttime>snakespeed){
			NextPos();
			if(GameOver()){
				GotoXY(NY/2,NX/2);
				SetColor(INFO_COLOR);
				printf("Game Over");
				return;
			}
			MoveSnake();
			lasttime=now;
		}
	}
}
int main(){
	GameInit();
	RenderMap();
	RenderSnake();
	NewFood();
	RenderFood();
	Firstrecv();
	PlayGame();
	getch();
	return 0;
}
