#include <stdbool.h>
#include <SDL2/SDL.h>

// temp
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "active.h"
#include "player.h"
#include "npc.h"
#include "camera.h"
// temp

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("Portal: Dimensions");
    
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

        CameraRender(&camera, &player, viewport.renderer);
        CameraRender(&camera, &npc, viewport.renderer);

        SDL_RenderPresent(viewport.renderer);
       
        WIN_CapFramerate(&lastTick);
    }

    e_DestroyEntity(&player);
    e_DestroyEntity(&npc);
    return(0);
}
