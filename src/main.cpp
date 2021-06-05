
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

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


	if(renderer == NULL){
		cout<<"Couldn't create renderer"<<endl;
		SDL_DestroyWindow(window);

		SDL_Quit();

		return 2;
	}

	if(texture == NULL){
		cout<<"Couldn't create texture"<<endl;
		SDL_DestroyRenderer(renderer);

		SDL_Quit();

	return 2;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	memset(buffer, 255, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer,SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer,texture,NULL, NULL);
	SDL_RenderPresent(renderer);
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
	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}