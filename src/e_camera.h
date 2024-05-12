#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

#include "e_entity.h"

#define E_CAMERA_LAG 0.1

E_Entity E_CameraCreate();
void E_CameraCenter(E_Entity *camera, E_Entity *entity);
void E_CameraRender(E_Entity *camera, E_Entity *entity, SDL_Renderer *renderer);

#endif//CAMERA_H
