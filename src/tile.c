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
    int buffer;

    file = fopen(src, "rb");

    fread(&tileMap->width, sizeof(int), 1, file);
    fread(&tileMap->height, sizeof(int), 1, file);
    
	tileMap->size = tileMap->width * tileMap->height;
    printf("Size: %u\n", tileMap->size);
	tileMap->tiles = malloc(sizeof(Tile) * tileMap->size);


    int i=0;
    while(fread(&buffer, sizeof(buffer), 1, file)) {
        tileMap->tiles[i].spriteID = buffer;
		tileMap->tiles[i].position.x = i%tileMap->width;
        tileMap->tiles[i].position.y = i/tileMap->width;
    	i++;
	}

    fclose(file);
}

void TileMapRender(TileMap *tileMap, Entity *camera, SDL_Renderer *renderer) {

    int cameraX = round(camera->transform->position.x),
        cameraY = round(camera->transform->position.y);
    for(int i=0;i<tileMap->size;i++) {
        if(tileMap->tiles[i].spriteID != 0) {
            SDL_Rect 
            tileSrc = {
				(tileMap->tiles[i].spriteID-1)*TILE_WIDTH, // subtract one to account for null value
				0,
                TILE_WIDTH,
                TILE_HEIGHT
            },
			tileDest = {
                tileMap->tiles[i].position.x*TILE_WIDTH-cameraX,
                tileMap->tiles[i].position.y*TILE_HEIGHT-cameraY,
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

void TileMapDestroy(TileMap *tileMap) {
    if(tileMap->spritesheet) {
        SDL_DestroyTexture(tileMap->spritesheet);
    }
    free(tileMap->tiles);
}
