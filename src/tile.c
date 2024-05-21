#include <stdio.h>
#include <stdlib.h>

#include "tile.h"

TileMap TileMapCreate(SDL_Texture *spritesheet) {
    TileMap tileMap;
    tileMap.spritesheet = spritesheet;
    return(tileMap);
} // i think this will have more logic at some point probably maybe perhaps

void TileMapRead(TileMap *tileMap, const char *src) {
    FILE *file;
    Tile buffer;

    file = fopen(src, "rb");

    fseek(file, 0, SEEK_END);
    tileMap->size = ftell(file)-2;
    tileMap->map = malloc(sizeof(int) * tileMap->size); // subtract 2 for height and width values
    fseek(file, 0, SEEK_SET);

    fread(&tileMap->width, sizeof(int), 1, file);
    fread(&tileMap->height, sizeof(int), 1, file);

    printf("%u - %u\n", tileMap->width, tileMap->height);
    int i=0;
    while(fread(&buffer, sizeof(buffer), 1, file)) {
        tileMap->map[i++] = buffer;
    }

    fclose(file);
}

void TileMapRender(TileMap *tileMap, Entity *camera, SDL_Renderer *renderer) {

    int cameraX = round(camera->transform->position.x),
        cameraY = round(camera->transform->position.y);
    for(int i=0;i<tileMap->size;i++) {
        if(tileMap->map[i] != 0) {
            SDL_Rect 
            tileSrc = {
                (tileMap->map[i]-1)*TILE_WIDTH,
                0,
                TILE_WIDTH,
                TILE_HEIGHT
            },
            tileDest = {
                (i%tileMap->width)*TILE_WIDTH-cameraX,
                (i/tileMap->width)*TILE_HEIGHT-cameraY,
                TILE_WIDTH,
                TILE_HEIGHT
            };
            SDL_RenderCopy(
                renderer,
                tileMap->spritesheet,
                &tileSrc,
                &tileDest
            );
        }
    } 
}
