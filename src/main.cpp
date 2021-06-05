
#include <SDL2/SDL.h>
#include <iostream>
#include "Screen.h"

using namespace std;
using namespace scr;

int main()
{

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error: Screen initialization" << endl;
	}

	while (true)
	{
		// Update Particles
		//Draw Particles.

		// Draw Particles.
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
			{
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);
		// Draw the screen.
		screen.update();

		//Check for messsages/events
		if (screen.proccesEvents() == false)
		{
			break;
		}
		// for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		//     {
		//         m_buffer[i] = 0x00FFFFFF;
		//     }
	}

	screen.close();

	return 0;
}