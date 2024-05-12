#include <stdbool.h>
#include <SDL2/SDL.h>

// temp
#include <SDL2/SDL_image.h>
#include "e_entity.h"
#include "e_active.h"
#include "e_player.h"
#include "e_npc.h"
#include "e_camera.h"
// temp

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("Portal: Dimensions");
    
    E_Entity camera = E_CameraCreate();
    E_Entity player = E_PlayerCreate(viewport.renderer);
    E_Entity npc = E_PlayerCreate(viewport.renderer);

    float lastTick = 0.0;
    while(WIN_CheckQuit()) {
        SDL_RenderClear(viewport.renderer);
       
        E_NPCInput(&npc, SDL_GetTicks());
        E_PlayerInput(&player);
        E_MoveAndCollide(&player);
        E_MoveAndCollide(&npc);
        E_VelocityFlip(&player);
        E_VelocityFlip(&npc);

        E_CameraCenter(&camera, &player);

        E_CameraRender(&camera, &player, viewport.renderer);
        E_CameraRender(&camera, &npc, viewport.renderer);

        SDL_RenderPresent(viewport.renderer);
       
        WIN_CapFramerate(&lastTick);
    }

    E_DestroyEntity(&player);
    E_DestroyEntity(&npc);
    return(0);
}
