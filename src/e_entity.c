#include <stdlib.h>
#include <SDL2/SDL.h>

#include "e_entity.h"

void E_CreateSprites(E_Entity *entity) {
    entity->sprites = malloc(sizeof(C_Sprites));
}

void E_CreateCollision(E_Entity *entity) {
    entity->collision = malloc(sizeof(C_Collision));
}

void E_CreateTransform(E_Entity *entity) {
    entity->transform = malloc(sizeof(C_Transform));
}

void E_CreateVelocity(E_Entity *entity) {
    entity->velocity = malloc(sizeof(C_Velocity));
}

void E_CreateStats(E_Entity *entity) {
    entity->stats = malloc(sizeof(C_Stats));
}

void E_DrawEntity(E_Entity *entity, SDL_Renderer *renderer) {
    SDL_RenderCopyEx(
        renderer,
        entity->sprites->spritesheet,
        &entity->sprites->src,
        &entity->sprites->dest,
        entity->transform->rotation,
        NULL,
        entity->sprites->flip
    );
}

void E_DestroyEntity(E_Entity *entity) {
    if(entity->sprites) {
        SDL_DestroyTexture(entity->sprites->spritesheet);
        free(entity->sprites);
    }
    if(entity->collision) {
        free(entity->collision);
    }
    if(entity->transform) {
        free(entity->transform);
    }
    if(entity->velocity) {
        free(entity->velocity);
    }
    if(entity->stats) {
        free(entity->stats);
    }
}
