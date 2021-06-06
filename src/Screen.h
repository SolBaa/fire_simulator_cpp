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
        ~Screen(){};

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;

    public:
        Screen();
        bool init();
        bool proccesEvents();
        void update();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void clear();
        void close();
        void boxBlur();
    };
} //End of namespace

#endif