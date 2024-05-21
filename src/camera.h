#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

#include "entity.h"

#define CAMERA_LAG 0.1

Entity CameraCreate();
void CameraCenter(Entity *camera, Entity *entity);

#endif//CAMERA_H
