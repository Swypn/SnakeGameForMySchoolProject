#include "Game.h"
#include "screen.h"

Game::Game()
{
	gameOver = false;
	m_scoreString = std::to_string(m_score);
}
Game::~Game()
{

}
void Game::CheckCollision(Screen& p_screen)
{
	if (m_Apple.GetX() == m_snake.GetX() && (m_Apple.GetY() == m_snake.GetY()))
	{
		p_screen.PlaySound(eatingSound);
		m_score += 1;
		m_scoreString = std::to_string(m_score);
		m_snake.body.push_back({ -50,-50 });
		m_Apple.ReSetApple();
	}	
}

void Game::setUp(Screen& p_screen)// sets the propeties to the snake game
{
	m_score = 0;
	m_snake.setUp(p_screen);
	m_Apple.setUp(p_screen);
	eatingSound = p_screen.LoadSound("assets/SnakeEatingApple.ogg");
	eatingSound.volume = 10;
	eatingSound.looping = false;
}

void Game::processInput(Screen& p_screen)// should handle the inputs
{
	m_snake.processInput(p_screen);
}

void Game::Update(Screen &p_screen)// should hold the update logic
{
	if(!gameOver)
	{
	CheckCollision(p_screen);
	m_Apple.Update(p_screen);
	m_snake.Update(p_screen, gameOver);
	}
}

void Game::Draw(Screen &p_screen)// here should the game draw the characters and objects
{
	m_Apple.Draw(p_screen);
	m_snake.Draw(p_screen);
	p_screen.DrawText(0, 10, { 255,255,255,255 }, "Snake Game", 2);
	p_screen.DrawText(p_screen.GetWindowWidth()/5, 10, { 255,255,255,255 }, m_scoreString, 2);
	if(gameOver)
	{
		p_screen.DrawText((p_screen.GetWindowWidth()/2)-200, (p_screen.GetWindowHeight()/2)-200, {255,55,55,155}, "Game Over", 6);
	}
}