#pragma once
#include <string>
#include "Apple.h"
#include "Snake.h"
#include "screen.h"
class Game
{
	Snake m_snake;
	Apple m_Apple;
	int m_score = 0;
	std::string m_scoreString;
	void CheckCollision(Screen& p_screen);
	Sound eatingSound;
public:
	
	Game();
	~Game();
	bool gameOver;
	void processInput(Screen& p_screen);
	void setUp(Screen& p_screen);
	void Update(Screen& p_screen);
	void Draw(Screen& p_screen);
};