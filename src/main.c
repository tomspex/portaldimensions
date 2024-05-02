#include <stdbool.h>
#include <SDL2/SDL.h>

#include "window.h"

int main(int argc, char *argv[]) {
    WIN_Viewport viewport = WIN_CreateViewport("My Window");
    
    while(WIN_CheckQuit()) {
    }
    return(0);
}
