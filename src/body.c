#include "body.h"

Body create_body() {
    Body body;
    body.pos.x = 100;
    body.pos.y = 100;
    body.velocity.x = 0;
    body.velocity.y = 0;
    body.mass = random() % MAX_MASS + 1;
    body.radius = DENSITY * body.mass;
    return body;
}

void render_body(SDL_Renderer* renderer, Body body) {
   //x² + y² = r²
    
    int dx, dy, radius = body.radius;
    for (dx = -radius; dx < radius; dx++) {
        dy = (int) sqrtf(radius*radius - dx*dx);
        int16_t x = body.pos.x + dx;     

        SDL_RenderDrawLine(renderer, x, (body.pos.y - dy), x, (body.pos.y + dy));   
    }
}
