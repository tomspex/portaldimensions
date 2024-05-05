#include <stdbool.h>
#include <SDL2/SDL.h>

// temp
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "e_entity.h"
#include "e_active.h"
#include "e_player.h"
// temp

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("My Window");
    
    E_Entity player = E_PlayerCreate(viewport.renderer);

    float lastTick = 0.0;
    while(WIN_CheckQuit()) {
        SDL_RenderClear(viewport.renderer);
        
        E_MoveAndCollide(&player, E_PlayerInput(&player));
        E_DrawEntity(&player, viewport.renderer);
        
        SDL_RenderPresent(viewport.renderer);
       
        WIN_CapFramerate(&lastTick);
    }

    E_DestroyEntity(&player);
    return(0);
}
