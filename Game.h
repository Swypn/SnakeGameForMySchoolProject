#pragma once
#include <iostream>
#include "Apple.h"
#include "Snake.h"
#include "screen.h"
class Game
{
	Snake m_snake;
	Apple m_Apple;
	int m_score = 0;
	void CheckCollision() // checking if the snake and apple is on same position
	{
		if (m_Apple.GetX() * m_Apple.GetY() == (m_snake.GetX() * m_snake.GetY()))
		{
			m_score += 1;
			std::cout << "collision with apple adn the score is " << m_score << std::endl;
			m_Apple.ReSetApple();
		}
	};
public:
	void delay(int milliseconds);
	void processInput(Screen& p_screen);
	void setUp(Screen& p_screen);
	void Update(Screen& p_screen);
	void Draw(Screen& p_screen);
};