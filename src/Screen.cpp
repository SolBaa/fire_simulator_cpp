#include <stdio.h>
#include "Screen.h"

namespace scr
{

    Screen::Screen() : m_window(NULL),
                       m_renderer(NULL),
                       m_texture(NULL),
                       m_buffer(NULL)
    {
    }

    bool Screen::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {

            return false;
        }
        // Initialize Windows
        m_window = SDL_CreateWindow("Particle Fire Explosion",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (m_window == NULL)
        {
            printf("Could not create window: %s\n", SDL_GetError());
            SDL_Quit();
            return 2;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (m_renderer == NULL)
        {
            SDL_DestroyWindow(m_window);

            SDL_Quit();

            return false;
        }

        if (m_texture == NULL)
        {
            SDL_DestroyRenderer(m_renderer);

            SDL_Quit();

            return false;
        }

        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        memset(m_buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    


        return true;
    }

    bool Screen::proccesEvents()
    {
	    SDL_Event event;
        while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				return false;
			}

		}
        return true;
    }
    void Screen::update(){
                SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);


    }
    void Screen::setPixel(int x , int y, Uint8 red, Uint8 green, Uint8 blue){
        Uint32 color = 0;
        color += red;
        color<<=8;
        color += green;
        color <<=8;
         color += blue;
        color <<=8;
        color += 0xFF;

        m_buffer[(y *SCREEN_WIDTH) + x] = color;

    }
    void Screen::close()
    {
        //After the program finished we need to destroy the window
        delete[] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

} //End of namespace