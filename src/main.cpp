
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

using namespace std;


int main(){
	const int SCREEN_WIDTH = 1000;
	const int SCREEN_HEIGHT = 800;

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		cout<<"SDL Failded!!"<<endl;

		return false;
	}
	// Initialize Windows
	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", 
	SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window==NULL){
		printf("Could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		return 2;
	}

	bool quit = false;
	SDL_Event event;

	while(!quit){
		// Update Particles
		//Draw Particles.
		//Check for messsages/events

		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				quit = true;
			}

		}
	}

	//After the program finished we need to destroy the window
	SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}