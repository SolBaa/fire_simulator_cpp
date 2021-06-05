
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;


int main(){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		cout<<"SDL Failded!!"<<endl;

		return false;
	}

	cout<<"SDL Succeeded!!"<<endl;
    SDL_Quit();

	return 0;
}