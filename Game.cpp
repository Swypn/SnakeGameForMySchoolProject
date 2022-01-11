#include "Game.h"
#include "screen.h"

void Game::setUp(Screen& p_screen)// sets the propeties to the snake game
{
	m_score = 0;
	m_snake.setUp(p_screen);
	m_Apple.setUp(p_screen);
	
}

void Game::processInput(Screen& p_screen)// should handle the inputs
{
	m_snake.processInput(p_screen);
}

void Game::Update(Screen &p_screen)// should hold the update logic
{
	CheckCollision();
	m_Apple.Update(p_screen);
	m_snake.Update(p_screen);
}

void Game::Draw(Screen &p_screen)// here should the game draw the characters and objects
{
	m_Apple.Draw(p_screen);
	m_snake.Draw(p_screen);
	p_screen.DrawText(0, 0, { 255,255,255,255 }, "Snake Game", 2);
}