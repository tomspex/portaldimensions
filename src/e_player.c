#include <SDL2/SDL_image.h>

#include "util.h"
#include "m_input.h"
#include "e_player.h"

E_Entity E_PlayerCreate(SDL_Renderer *renderer) {
    E_Entity player;
    E_CreateSprites(&player);
    E_CreateTransform(&player);
    E_CreateVelocity(&player);
    E_CreateStats(&player);

    player.sprites->spritesheet = IMG_LoadTexture(
        renderer,
        "playertemp.png"
    );
    player.stats->speed = E_PLAYER_SPEED;
    player.sprites->dest.w = E_PLAYER_WIDTH;
    player.sprites->dest.h = E_PLAYER_HEIGHT;
    player.sprites->src.w = E_PLAYER_WIDTH;
    player.sprites->src.h = E_PLAYER_HEIGHT;
    
    return(player);
}

void E_PlayerInput(E_Entity *player) {
	const uint8_t *input = SDL_GetKeyboardState(NULL);
	vec2 input_dir;
	input_dir.x = input[I_RIGHT] - input[I_LEFT];
	input_dir.y = input[I_DOWN] - input[I_UP];
        player->velocity->x = lerp(
            player->velocity->x, 
            input_dir.x * player->stats->speed, 
            E_PLAYER_FRICTION
        );
        player->velocity->y = lerp(
            player->velocity->y, 
            input_dir.y * player->stats->speed, 
            E_PLAYER_FRICTION
        );
}
