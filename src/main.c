#include <stdbool.h>
#include <SDL2/SDL.h>

// temp
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "active.h"
#include "player.h"
#include "npc.h"
#include "camera.h"
#include "sprite.h"
#include "tile.h"
// temp

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("Portal: Dimensions");
    
    Spritesheet spritesheet = SpritesheetCreate("spritesheet.png", "tilesheet.sap", viewport.renderer);
    TileMap tileMap = TileMapCreate(&spritesheet);
    TileMapRead(&tileMap, "tiles.tap");

    Entity camera = CameraCreate();
    Entity player = ActiveCreate("player.png", viewport.renderer);
    Entity npc = ActiveCreate("npc.png", viewport.renderer);

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

    SpritesheetDestroy(&spritesheet);
    TileMapDestroy(&tileMap);
    EntityDestroy(&player);
    EntityDestroy(&npc);
    EntityDestroy(&camera);

    SDL_Quit();
    return(0);
}
