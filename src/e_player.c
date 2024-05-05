#include <SDL2/SDL_image.h>

#include "m_input.h"
#include "e_player.h"

E_Entity E_PlayerCreate(SDL_Renderer *renderer) {
    E_Entity player;
    E_CreateSprites(&player);
    E_CreateTransform(&player);
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

vec2 E_PlayerInput(E_Entity *player) {
	const uint8_t *input = SDL_GetKeyboardState(NULL);
	vec2 input_dir;
	input_dir.x = input[I_RIGHT] - input[I_LEFT];
	input_dir.y = input[I_DOWN] - input[I_UP];
	return(input_dir);
}
