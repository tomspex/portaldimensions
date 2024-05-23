#include <stdint.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>

#include "sprite.h"

Spritesheet SpritesheetCreate(const char *texture, const char *sprites, SDL_Renderer *renderer) {
    Spritesheet spritesheet;
    
    spritesheet.spritesheet = IMG_LoadTexture(renderer, texture);

    FILE *spritesfile;
    uint16_t size, buffer[8];

    spritesfile = fopen(sprites, "rb");

    fread(&size, sizeof(size), 1, spritesfile);
    spritesheet.sprites = malloc(sizeof(Sprite) * size);

    for(int i=0;i<size;i++) {
        for(int j=0;j<8;j++) {
            fread(&buffer[j], sizeof(buffer[j]), 1, spritesfile);
        }
        spritesheet.sprites[i].src.x = buffer[0];
        spritesheet.sprites[i].src.y = buffer[1];
        spritesheet.sprites[i].src.w = buffer[2];
        spritesheet.sprites[i].src.h = buffer[3];
        spritesheet.sprites[i].collision.x = buffer[4];
        spritesheet.sprites[i].collision.y = buffer[5];
        spritesheet.sprites[i].collision.w = buffer[6];
        spritesheet.sprites[i].collision.h = buffer[7];
    }
    
    fclose(spritesfile);

    return(spritesheet);
}

void SpritesheetDestroy(Spritesheet *spritesheet) {
    free(spritesheet->sprites);
    SDL_DestroyTexture(spritesheet->spritesheet);
}
