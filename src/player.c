#include "util.h"
#include "input.h"
#include "active.h"
#include "player.h"

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
