#include "util.h"

float lerp(float start, float end, float value) {
    return(start + (end - start)*value);
}

int imin(int val, int min) {
    if(val < min) return(min);
    return(val);
}
