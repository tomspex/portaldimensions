#include <stdlib.h>
#include <SDL2/SDL.h>

#include "entity.h"

void e_CreateSprites(Entity *entity) {
    entity->sprites = malloc(sizeof(Sprites));
}

void e_CreateCollision(Entity *entity) {
    entity->collision = malloc(sizeof(Collision));
}

void e_CreateTransform(Entity *entity) {
    entity->transform = malloc(sizeof(Transform));
}

void e_CreateVelocity(Entity *entity) {
    entity->velocity = malloc(sizeof(Velocity));
}

void e_CreateStats(Entity *entity) {
    entity->stats = malloc(sizeof(Stats));
}

void e_DrawEntity(Entity *entity, SDL_Renderer *renderer) {
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

void e_DestroyEntity(Entity *entity) {
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
