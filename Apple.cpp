#include "Apple.h"
#include "screen.h"
#include <cstdlib>
#include <time.h>

Apple::Apple()
{
	circleX = 0;
	circleY = 0;
	circleR = 0;
	color = {};
}

Apple::~Apple()
{

}

void Apple::setUp(Screen& p_screen)// sets the value to the apples propeties
{
	circleX = 500;
	circleY = 300; 
	circleR = 25;
	color = { 199, 55, 47 };
}

void Apple::Update(Screen& p_screen) // should update the apple logic
{
	GetX();
	GetY();
	GetR();
} 

void Apple::Draw(Screen& p_screen) // draw the apple
{
	p_screen.DrawCircle(circleX, circleY, circleR, color);
}

void Apple::ReSetApple()
{
	srand((int)time(0));
	circleX = 50 * (rand()% 15 + 1);
	circleY = 50 * (rand() % 15 + 1);
}

int Apple::GetX()// return the x positions
{
	return circleX;
}

int Apple::GetY()// return the y positions
{
	return circleY;
}
int Apple::GetR() 
{
	return circleR;
}