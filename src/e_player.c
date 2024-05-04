#include "m_input.h"
#include "e_player.h"

vec2 E_PlayerInput(E_Entity *player) {
	const uint8_t *input = SDL_GetKeyboardState(NULL);
	vec2 input_dir;
	input_dir.x = input[I_RIGHT] - input[I_LEFT];
	input_dir.y = input[I_DOWN] - input[I_UP];
	return(input_dir);
}
