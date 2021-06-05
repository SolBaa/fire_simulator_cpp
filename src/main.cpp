
#include <SDL2/SDL.h>
#include <iostream>
#include "Screen.h"

using namespace std;
using namespace scr;

int main(){

	Screen screen;
	
	if(screen.init()==false){
		cout<<"Error: Screen initialization"<<endl;
	}


	while(true){
		// Update Particles
		//Draw Particles.
		//Check for messsages/events
		if(screen.proccesEvents()== false){
			break;
		}

		
	}

	screen.close();

	return 0;
}