#include <stdlib.h>

#include "util.h"
#include "e_active.h"
#include "e_npc.h"

void E_NPCInput(E_Entity *npc, int clock) {
    vec2 input_dir;
    if(clock % E_NPC_WAIT == 0) {
        npc->velocity->x = (rand()%3-1) * npc->stats->speed;
        npc->velocity->y = (rand()%3-1) * npc->stats->speed;
    }
    npc->velocity->x = lerp(
        npc->velocity->x, 0.0, E_DEFAULT_FRICTION);
    npc->velocity->y = lerp(
        npc->velocity->y, 0.0, E_DEFAULT_FRICTION);
}
