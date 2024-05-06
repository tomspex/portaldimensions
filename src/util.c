#include "util.h"

float lerp(float start, float end, float value) {
    return(start + (end - start)*value);
}
