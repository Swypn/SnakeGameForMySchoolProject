#pragma once
#include "screen.h"
#include <vector> 
const int partsNummer = 5;
class Snake
{
	struct Body // This should hold the propeties to the head and body part of the game
	{
		int speedX = 0, speedY = 0;
		int rectX = 0, rectY = 0, rectW = 0, rectH = 0;
		Color color = {};
	};
	std::vector<Body> body;
	Body head; // this should be the steering wheel of the snake
	Body BodyParts[partsNummer]{}; // this should be the parts that adds on the snake
	bool holdingLeft, holdingRight, holdingDown, holdingUp;
	enum directions { Left, Right, Up, Down};
public:
	Snake();
	~Snake();

	void processInput(Screen& p_screen);
	void setUp(Screen& p_screen);
	void Update(Screen& p_screen);
	void Draw(Screen& p_screen);
	int GetX();
	int GetY();
	int GetW();
	int GetH();
};