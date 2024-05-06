#include <stdlib.h>

#include "e_npc.h"

void E_NPCInput(E_Entity *npc, int clock) {
    if(!clock % E_NPC_WAIT) {
        vec2 input_dir;
        input_dir.x = rand()%3-1;
        input_dir.y = rand()%3-1;
        npc->velocity->x += input_dir.x * npc->stats->speed;
        npc->velocity->y += input_dir.y * npc->stats->speed;
    }
}
