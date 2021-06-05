
#ifndef SCREEN_H
#define SCREEN_H
#include <SDL2/SDL.h>

namespace scr
{

    class Screen
    {
    public:
        const static int SCREEN_WIDTH = 1000;
        const static int SCREEN_HEIGHT = 800;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;

    public:
        Screen();
        bool init();
        bool proccesEvents();
        void close();
    };
} //End of namespace

#endif