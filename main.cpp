#include "Screen.h"
#include "Game.h"

int screenWidth = 1000;
int screenHeight = 1000;

/* 
Willy Pettersson

Galba v1.6
Vector2				-> Turned into a class, added baseline Vector2 functionality (arithmetic, magnitude, dot, normalize, distance)

Galba v1.5.1
Scaling added to sprites

Galba v1.5
LoadSprite			-> loads a texture from the given path, returns a sprite
DrawSprite			-> draws a sprite sent as argument
DrawText			-> default argument for scale as last argument added, standard size 2
LoadSound			-> loads a sound from a given path, returns a sound
PlaySound			-> plays a sound sent as argument
StopSound			-> stops playing a sound send as argument

Galba v1.4
DrawPixelColor		-> renamed DrawPixel as an overloaded function
DrawCircleColor		-> renamed DrawCircle as an overloaded function
DrawRectangleColor	-> renamed DrawRectangle as an overloaded function

Info;
unsigned char a; for Alpha (255 = no transparency) added to the Color struct, draw functions taking unsigned char r,g,b now takes unsigned char r,g,b,a
*/

int main(int argc, char** argv)
{
	Screen screen(screenWidth, screenHeight, "Galba");
	Game game;
	game.setUp(screen);
	int counter = 0;
 	while (screen.IsOpen())
	{
		counter++;
		screen.Clear();
		game.processInput(screen);
		game.Update(screen);
		game.Draw(screen);
		screen.Display();
	}
	return 0;
}