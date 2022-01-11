#include "Snake.h"
#include "screen.h"
#include <iostream>
#include <time.h>  

Snake::Snake()
{
	holdingDown = true;
	holdingUp = true;
	holdingLeft = true;
	holdingRight = true;
}

Snake::~Snake()
{

}

void Snake::setUp(Screen& p_screen)// setup the snakes propeties
{
	head.color = { 50,175,50 };
	head.speedX = 50;
	head.speedY = 0;
	head.rectX = 100;
	head.rectY = 200;
	head.rectW = 50;
	head.rectH = 50;
	holdingLeft = true;
	holdingRight = true;
	for(int i = 0; i < partsNummer; i++)
	{
		BodyParts[i].color = { 50,255,50 };
		BodyParts[i].speedX = 0;
		BodyParts[i].speedY = 0;
		BodyParts[i].rectX = 100;
		BodyParts[i].rectY = 400;
		BodyParts[i].rectW = 50;
		BodyParts[i].rectH = 50;
	}
}

void Snake::processInput(Screen& p_screen)// Here should the snakes input logic run
{
	if (p_screen.IsKeyDown(Key::Left) && holdingLeft)
	{
		head.speedX = -50;
		head.speedY = 0;
		holdingLeft = false;
		holdingRight = true;
		holdingUp = true;
		holdingDown = true;
	}
	if(p_screen.IsKeyDown(Key::Right) && holdingRight)
	{
		head.speedX = 50;
		head.speedY = 0;
		holdingLeft = true;
		holdingRight = false;
		holdingUp = true;
		holdingDown = true;
	}
	if (p_screen.IsKeyDown(Key::Up) && holdingUp)
	{
		head.speedX = 0;
		head.speedY = -50;
		holdingLeft = true;
		holdingRight = true;
		holdingUp = false;
		holdingDown = true;
	}
	if(p_screen.IsKeyDown(Key::Down) && holdingDown)
	{
		head.speedX = 0;
		head.speedY = 50;
		holdingLeft = true;
		holdingRight = true;
		holdingUp = true;
		holdingDown = false;
	}
}
int counter = 0;
void Snake::Update(Screen& p_screen)// Here updates the snakes logic
{
	if(counter % 10 == 0)
	{
	head.rectX += head.speedX;
	head.rectY += head.speedY;
	if (head.rectX <= 0 || head.rectX >= p_screen.GetWindowWidth())
	{
		std::cout << " touching the wall" << std::endl;
	}
	if (head.rectY <= 0 || head.rectY >= p_screen.GetWindowHeight())
	{
		std::cout << " touching the wall" << std::endl;
	}
	counter = 0;
	}
	counter++;
}

void Snake::Draw(Screen& p_screen)// here draws the snake
{
	int y = 0;
	p_screen.DrawRectangle(head.rectX, head.rectY, head.rectH, head.rectW, head.color);
	for (int i = 0; i < partsNummer; i++)
	{
		p_screen.DrawRectangle(BodyParts[i].rectX + y, BodyParts[i].rectY, BodyParts[i].rectH, BodyParts[i].rectW, BodyParts[i].color);
		y += 50;
	}
}

int Snake::GetX()
{
	return head.rectX;
}

int Snake::GetY()
{
	return head.rectY;
}

int Snake::GetW()
{
	return head.rectW;
}
int Snake::GetH()
{
	return head.rectH;
}