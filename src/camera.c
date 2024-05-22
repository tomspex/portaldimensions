#include "util.h"
#include "window.h"

#include "camera.h"

Entity CameraCreate() {
    Entity camera;
    CreateCollision(&camera);
    camera.collision->w = WIN_WIDTH;
    camera.collision->h = WIN_HEIGHT;
    camera.collision->x = 0;
    camera.collision->y = 0;
    return(camera);
}

void CameraCenter(Entity *camera, Entity *entity) {
    camera->collision->x = lerp(
        camera->collision->x,
        entity->transform->position.x - (camera->collision->w >> 1) + 
        (entity->sprites->dest.w >> 1),
        CAMERA_LAG);
    camera->collision->y = lerp(
        camera->collision->y,
        entity->transform->position.y - (camera->collision->h >> 1) +
        (entity->sprites->dest.h >> 1),
        CAMERA_LAG);
}
