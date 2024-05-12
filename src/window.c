#include "window.h"

WIN_Viewport WIN_CreateViewport(char *name) {
    WIN_Viewport viewport;
    viewport.window = SDL_CreateWindow(
	name,
    	SDL_WINDOWPOS_CENTERED,
    	SDL_WINDOWPOS_CENTERED,
    	WIN_WIDTH*WIN_SCALE,
	WIN_HEIGHT*WIN_SCALE,
	0
    );
    viewport.renderer = SDL_CreateRenderer(
	viewport.window, -1, 0
    );
    SDL_RenderSetLogicalSize(viewport.renderer, WIN_WIDTH, WIN_HEIGHT);
    return(viewport);
}

bool WIN_CheckQuit() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                return(0);
        }
    }
    return(1);
}

void WIN_CapFramerate(float *lastTick) {
    float nowTick = SDL_GetTicks();
    float deltaTime = (nowTick - *lastTick);
    if(WIN_SPEED > deltaTime) { 
        SDL_Delay(WIN_SPEED - deltaTime); 
    }
    *lastTick = nowTick;
}
