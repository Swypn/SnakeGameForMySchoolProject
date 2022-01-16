#include "Snake.h"
#include "screen.h"
#include <time.h>  

Color snakeColor = { 50,255,50 };

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
	deathSound = p_screen.LoadSound("assets/deathOfTheSnake.ogg");
	deathSound.volume = 10;
}
void Snake::processInput(Screen& p_screen)// Here should the snakes input logic run
{
	
	if (p_screen.IsKeyDown(Key::Left) && holdingLeft)
	{
		head.speedX = -50;
		head.speedY = 0;
		holdingLeft = false;
		holdingRight = false;
		holdingUp = true;
		holdingDown = true;
	}
	if(p_screen.IsKeyDown(Key::Right) && holdingRight)
	{
		head.speedX = 50;
		head.speedY = 0;
		holdingLeft = false;
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
		holdingDown = false;
	}
	if(p_screen.IsKeyDown(Key::Down) && holdingDown)
	{
		holdingLeft = true;
		head.speedX = 0;
		head.speedY = 50;
		holdingRight = true;
		holdingUp = false;
		holdingDown = false;
	}
}
int counter = 0;
void Snake::Update(Screen& p_screen, bool& gameOver)// Here updates the snakes logic
{
	if(counter % 10 == 0)
	{
		
		
		int previousX = head.rectX;
		int previousY = head.rectY;
		int prev2X, prev2Y;

		for(int i = 0; i < body.size(); i++)// This follow body logic I took from this youtube https://www.youtube.com/watch?v=PSoLD9mVXTA 
		{
			prev2X = body[i].posX;
			prev2Y = body[i].posY;
			body[i].posX = previousX;
			body[i].posY = previousY;
			previousX = prev2X;
			previousY = prev2Y;
		}
		head.rectX += head.speedX;
		head.rectY += head.speedY;
		if (head.rectX <= -50 || head.rectX >= p_screen.GetWindowWidth())
		{
			gameOver = true;
			p_screen.PlaySound(deathSound);
		}
		if (head.rectY <= -50 || head.rectY >= p_screen.GetWindowHeight())
		{
			gameOver = true;
			p_screen.PlaySound(deathSound);
		}
		for (int i = 0; i < body.size(); i++)// This follow body logic I took from this youtube https://www.youtube.com/watch?v=PSoLD9mVXTA 
		{
			if(head.rectX == body[i].posX && head.rectY == body[i].posY)
			{
				gameOver = true;
				p_screen.PlaySound(deathSound);
			}
		}
		counter = 0;
	}
	counter++;
}

void Snake::Draw(Screen& p_screen)// here draws the snake
{
	int y = 0;
	p_screen.DrawRectangle(head.rectX, head.rectY, head.rectH, head.rectW, head.color);
	
	for (int i = 0; i < body.size(); i++)
	{
		p_screen.DrawRectangle(body[i].posX, body[i].posY, 50, 50, snakeColor);
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