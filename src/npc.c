#include <stdlib.h>

#include "util.h"
#include "active.h"
#include "npc.h"

void NPCInput(Entity *npc, int clock) {
    vec2 input_dir;
    if(clock % NPC_WAIT == 0) {
        npc->velocity->x = (rand()%3-1) * npc->stats->speed;
        npc->velocity->y = (rand()%3-1) * npc->stats->speed;
    }
    npc->velocity->x = lerp(
        npc->velocity->x, 0.0, DEFAULT_FRICTION);
    npc->velocity->y = lerp(
        npc->velocity->y, 0.0, DEFAULT_FRICTION);
}
