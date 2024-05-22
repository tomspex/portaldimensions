#include <SDL2/SDL_image.h>

#include "util.h"
#include "input.h"
#include "active.h"
#include "player.h"

Entity PlayerCreate(SDL_Renderer *renderer) {
    Entity player;
    EntityResetPointers(&player);
    CreateSprites(&player);
    CreateTransform(&player);
    CreateVelocity(&player);
    CreateStats(&player);

    player.sprites->spritesheet = IMG_LoadTexture(
        renderer,
        "playertemp.png"
    );
    player.stats->speed = PLAYER_SPEED;
    player.sprites->dest.w = PLAYER_WIDTH;
    player.sprites->dest.h = PLAYER_HEIGHT;
    player.sprites->src.w = PLAYER_WIDTH;
    player.sprites->src.h = PLAYER_HEIGHT;
    
    return(player);
}

void PlayerInput(Entity *player) {
	const uint8_t *input = SDL_GetKeyboardState(NULL);
	vec2 input_dir;
	input_dir.x = input[I_RIGHT] - input[I_LEFT];
	input_dir.y = input[I_DOWN] - input[I_UP];
        player->velocity->x = lerp(
            player->velocity->x, 
            input_dir.x * player->stats->speed, 
            DEFAULT_FRICTION
        );
        player->velocity->y = lerp(
            player->velocity->y, 
            input_dir.y * player->stats->speed, 
            DEFAULT_FRICTION
        );
}
