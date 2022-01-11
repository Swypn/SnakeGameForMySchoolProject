#pragma once
#include "screen.h"

class Apple
{
	int circleX, circleY, circleR;
	Color color;
public:
	void setUp(Screen& p_screen);
	void Update(Screen& p_screen);
	void Draw(Screen& p_screen);
	void ReSetApple();
	int GetX();
	int GetY();
	int GetR();
};