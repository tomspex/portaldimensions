#ifndef WINDOW_H
#define WINDOW_H

#define WIN_SPEED   16.6666f
#define WIN_WIDTH   640
#define WIN_HEIGHT  480

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct WIN_Viewport {
    SDL_Window      *window;
    SDL_Renderer    *renderer;
} WIN_Viewport;

WIN_Viewport WIN_CreateViewport(char *name);
bool WIN_CheckQuit();
void WIN_CapFramerate(float *lastTick);

#endif//WINDOW_H
