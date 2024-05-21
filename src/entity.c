#include <stdlib.h>
#include <SDL2/SDL.h>

#include "entity.h"

void CreateSprites(Entity *entity) {
    entity->sprites = malloc(sizeof(Sprites));
}

void CreateCollision(Entity *entity) {
    entity->collision = malloc(sizeof(Collision));
}

void CreateTransform(Entity *entity) {
    entity->transform = malloc(sizeof(Transform));
}

void CreateVelocity(Entity *entity) {
    entity->velocity = malloc(sizeof(Velocity));
}

void CreateStats(Entity *entity) {
    entity->stats = malloc(sizeof(Stats));
}

void EntityRender(Entity *entity, Entity *camera, SDL_Renderer *renderer) {
    SDL_Rect offsetPos = entity->sprites->dest;
    offsetPos.x -= round(camera->transform->position.x);
    offsetPos.y -= round(camera->transform->position.y);

    SDL_RenderCopyEx(
        renderer,
        entity->sprites->spritesheet,
        &entity->sprites->src,
        &offsetPos,
        entity->transform->rotation,
        NULL,
        entity->sprites->flip
    );
}

void EntityDestroy(Entity *entity) {
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
