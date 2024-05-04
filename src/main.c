#include <stdbool.h>
#include <SDL2/SDL.h>

// temp
#include <SDL2/SDL_image.h>
#include "e_entity.h"
#include "e_active.h"
#include "e_player.h"
// temp

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("My Window");
    
    E_Entity player;
    E_CreateSprites(&player);
    E_CreateTransform(&player);
    E_CreateStats(&player);

    player.stats->speed = 5;
    player.transform->dest.x = 0;
    player.transform->dest.y = 0;
    player.transform->dest.w = 32;
    player.transform->dest.h = 32;
    player.sprites->spritesheet = IMG_LoadTexture(
        viewport.renderer,
        "playertemp.png"
    );
    player.sprites->src.w = 32;
    player.sprites->src.h = 32;
    player.sprites->src.x = 0;
    player.sprites->src.y = 0;

    while(WIN_CheckQuit()) {
        E_MoveAndCollide(&player, E_PlayerInput(&player));
        E_DrawEntity(&player, viewport.renderer);
    }

    E_DestroyEntity(&player);
    return(0);
}
