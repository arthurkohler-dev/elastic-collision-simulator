#ifndef BODY_H
#define BODY_H

#define MAX_MASS 20
#define DENSITY 10

#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

typedef struct {
    int16_t x;
    int16_t y;
} Vector2;

typedef struct {
    int16_t kinetic_energy;
    int16_t linear_momentum;
    Vector2 pos;
    Vector2 velocity;
    int8_t radius;
    int16_t mass;
} Body;

Body create_body();
void destroy_body();
void render_body(SDL_Renderer* renderer, Body body);

#endif

