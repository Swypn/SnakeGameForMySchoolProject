#pragma once
#include "screen.h"
#include <vector> 

class Snake
{
	struct Body // This should hold the propeties to the head and body part of the game
	{
		int speedX = 0, speedY = 0;
		int rectX = 0, rectY = 0, rectW = 0, rectH = 0;
		Color color = {};
	};
	struct TailPos
	{
		int posX, posY;    
	};
	Body head; // this should be the steering wheel of the snake
	Sound deathSound;
	bool holdingLeft, holdingRight, holdingDown, holdingUp;
	enum directions { Left, Right, Up, Down};
public:
	std::vector<TailPos> body;
	Snake();
	~Snake();
	void processInput(Screen& p_screen);
	void setUp(Screen& p_screen);
	void Update(Screen& p_screen, bool& gameOver);
	void Draw(Screen& p_screen);
	int GetX();
	int GetY();
	int GetW();
	int GetH();
};