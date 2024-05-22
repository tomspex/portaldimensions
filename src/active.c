#include <SDL2/SDL_image.h>

#include "active.h"

Entity ActiveCreate(char *spritesheet, SDL_Renderer *renderer) {
    Entity active;
    EntityResetPointers(&active);
    CreateSprites(&active);
    CreateTransform(&active);
    CreateVelocity(&active);
    CreateStats(&active);

    active.sprites->spritesheet = IMG_LoadTexture(
        renderer,
        spritesheet
    );
    active.stats->speed = ACTIVE_SPEED;
    active.sprites->dest.w = ACTIVE_WIDTH;
    active.sprites->dest.h = ACTIVE_HEIGHT;
    active.sprites->src.w = ACTIVE_WIDTH;
    active.sprites->src.h = ACTIVE_HEIGHT;
    
    return(active);
}

void MoveAndCollide(Entity *entity) {
    Move(entity);
    // add collide part later
}

void Move(Entity *entity) {
    entity->transform->position.x += entity->velocity->x * entity->stats->speed;
    entity->transform->position.y += entity->velocity->y * entity->stats->speed;
    if(entity->sprites) {
        entity->sprites->dest.x = round(entity->transform->position.x);
        entity->sprites->dest.y = round(entity->transform->position.y);
    }
}

void VelocityFlip(Entity *entity) {
    if(entity->velocity->x > 0) {
        entity->sprites->flip = SDL_FLIP_HORIZONTAL;
    } else {
        entity->sprites->flip = SDL_FLIP_NONE;
    }
}
