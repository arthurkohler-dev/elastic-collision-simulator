#include "body.h"

Body create_body(Vector2 position, Vector2 velocity) {
    Body body;
    body.pos = position;
    body.velocity = velocity;
    body.mass = random() % MAX_MASS + 1;
    body.radius = 25;
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
 
Body* gen_bodies(int16_t n_bodies, int16_t win_width, int16_t win_height) {
    Body* bodies = (Body*) malloc(sizeof(Body) * n_bodies);

    int16_t i;
    for (i = 0; i < n_bodies; i++) {
        Vector2 pos, velocity;
        //this function needs to be changed entirely
        Body body = create_body(pos, velocity);
        bodies[i] = body;
        bodies[i].pos.x = (random() % (win_width - body.radius)) + body.radius;
        bodies[i].pos.y = (random() % (win_height - body.radius)) + body.radius;
    }

    return bodies;
}

void render_bodies(SDL_Renderer* renderer, Body* bodies, int16_t n_bodies) {
    int16_t i;

    for (i = 0; i < n_bodies; i++) render_body(renderer, bodies[i]);
}
