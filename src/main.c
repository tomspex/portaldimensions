#include <stdbool.h>
#include <SDL2/SDL.h>

// temp
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "active.h"
#include "player.h"
#include "npc.h"
#include "camera.h"
#include "tile.h"
// temp

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("Portal: Dimensions");
    
    SDL_Texture *tileMapTexture = IMG_LoadTexture(viewport.renderer, "tilemap.png");

    TileMap tileMap = TileMapCreate(tileMapTexture);
    TileMapRead(&tileMap, "tile.bin");

    Entity camera = CameraCreate();
    Entity player = PlayerCreate(viewport.renderer);
    Entity npc = PlayerCreate(viewport.renderer);

    float lastTick = 0.0;
    while(WIN_CheckQuit()) {
        SDL_RenderClear(viewport.renderer);
       
        NPCInput(&npc, SDL_GetTicks());
        PlayerInput(&player);
        MoveAndCollide(&player);
        MoveAndCollide(&npc);
        VelocityFlip(&player);
        VelocityFlip(&npc);

        CameraCenter(&camera, &player);

        TileMapRender(&tileMap, &camera, viewport.renderer);
        EntityRender(&player, &camera, viewport.renderer);
        EntityRender(&npc, &camera, viewport.renderer);

        SDL_RenderPresent(viewport.renderer);
       
        WIN_CapFramerate(&lastTick);
    }

    EntityDestroy(&player);
    EntityDestroy(&npc);
    return(0);
}
