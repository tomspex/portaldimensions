#include "util.h"
#include "window.h"

#include "camera.h"

Entity CameraCreate() {
    Entity camera;
    e_CreateTransform(&camera);
    return(camera);
}

void CameraCenter(Entity *camera, Entity *entity) {
    camera->transform->position.x = lerp(
        camera->transform->position.x,
        entity->transform->position.x - (WIN_WIDTH >> 1) + 
        (entity->sprites->dest.w >> 1),
        CAMERA_LAG);
    camera->transform->position.y = lerp(
        camera->transform->position.y,
        entity->transform->position.y - (WIN_HEIGHT >> 1) +
        (entity->sprites->dest.h >> 1),
        CAMERA_LAG);
}

void CameraRender(Entity *camera, Entity *entity, SDL_Renderer *renderer) {
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
