
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "Screen.h"
#include "Particle.h"

using namespace std;
using namespace scr;

int main()
{

	srand(time(NULL));
	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error: Screen initialization" << endl;
	}

	Swarm swarm;


	while (true)
	{
		// Update Particles
		
		
		//Draw Particles.
		int elapsed = SDL_GetTicks();
		screen.clear();
		swarm.update(elapsed); 

		unsigned char green =(1 + sin(elapsed * 0.0002)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;


		const Particle * const Particles = swarm.getParticles();
		for (int i = 0; i <Swarm::NPARTICLES; i++) {
			Particle particle = Particles[i];

			int x = (particle.m_x +1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 +  Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x,y,red,green,blue );

		}

		// Draw the screen.
		screen.update();

		//Check for messsages/events
		if (screen.proccesEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}