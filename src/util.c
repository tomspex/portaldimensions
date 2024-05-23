#include "util.h"

float lerp(float start, float end, float value) {
    return(start + (end - start)*value);
}

int iclamp(int val, int min, int max) {
    if(val < min) return(min);
    if(val > max) return(max);
    return(val);
}
