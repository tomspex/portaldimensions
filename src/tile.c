#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "tile.h"

TileMap TileMapCreate(Spritesheet *spritesheet) {
    TileMap tileMap;
    tileMap.spritesheet = spritesheet;
    return(tileMap);
} // i think this will have more logic at some point probably maybe perhaps

void TileMapRead(TileMap *tileMap, const char *src) {
    FILE *file;
    int buffer;

    file = fopen(src, "rb");

    fread(&tileMap->width, sizeof(int), 1, file);
    fread(&tileMap->height, sizeof(int), 1, file);
    
	tileMap->size = tileMap->width * tileMap->height;
    printf("Size: %u\n", tileMap->size);
	tileMap->tiles = malloc(sizeof(Tile) * tileMap->size);

    for(int i=0;i<tileMap->size;i++) {
        fread(&buffer, sizeof(buffer), 1, file);
        tileMap->tiles[i].spriteID = buffer;
	tileMap->tiles[i].position.x = i%tileMap->width;
        tileMap->tiles[i].position.y = i/tileMap->width;
    }

    fclose(file);
}

void TileMapRender(TileMap *tileMap, Entity *camera, SDL_Renderer *renderer) {
    
    int cameraX = round(camera->collision->x),
        cameraY = round(camera->collision->y),
        cameraMapW = camera->collision->w/TILE_WIDTH,
        cameraMapH = camera->collision->h/TILE_HEIGHT+1;
    int cameraMapX = iclamp(cameraX/TILE_WIDTH, 0, tileMap->width-cameraMapW),
        cameraMapY = iclamp(cameraY/TILE_HEIGHT, 0, tileMap->height-cameraMapH);
    SDL_Rect 
        tileSrc = {0, 0, TILE_WIDTH, TILE_HEIGHT},
        tileDest = {0, 0, TILE_WIDTH, TILE_HEIGHT};
    
    for(int i=0;i<=cameraMapH;i++) {
        for(int j=0;j<=cameraMapW;j++) {
            int index = cameraMapX+j+(cameraMapY+i)*tileMap->width;
            if(tileMap->tiles[index].spriteID != 0) {
                tileDest.x = tileMap->tiles[index].position.x*TILE_WIDTH-cameraX;
                tileDest.y = tileMap->tiles[index].position.y*TILE_HEIGHT-cameraY;
                
                SDL_RenderCopy(
                    renderer,
                    tileMap->spritesheet->spritesheet,
                    &tileMap->spritesheet->sprites[tileMap->tiles[index].spriteID-1].src,
                    &tileDest
                );
            }
        }
    } 
}

void TileMapDestroy(TileMap *tileMap) {
    free(tileMap->tiles);
}
