#include "input.h"
#include "player.h"

vec2i S_PlayerInput(E_Entity *plaer) {
	uint8_t *input = SDL_GetKeyboardState(NULL);
	vec2i input_dir;
	input_dir.x = input[I_RIGHT] - input[I_LEFT];
	input_dir.y = input[I_DOWN] - input[I_UP];
	return(input_dir);
}
