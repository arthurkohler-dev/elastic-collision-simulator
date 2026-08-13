#include "body.h"

#include "config.h"
#include 

Body create_body() {
    Body body;
    

    return body;
}

void render_body(SDL_Renderer* renderer, Body body) {
    int dx, dy, radius = body.radius;
    for (dx = -radius; dx < radius; dx++) {
        dy = (int) sqrtf(radius*radius - dx*dx);
        int16_t x = body.pos.x + dx;     

        SDL_RenderDrawLine(renderer, x, (body.pos.y - dy), x, (body.pos.y + dy));   
    }
}
 



