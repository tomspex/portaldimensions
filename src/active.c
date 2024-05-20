#include "active.h"

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
