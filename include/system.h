#ifndef SYSTEM_H
#define SYSTEM_H

#include "body.h"

typedef struct {
    Body* bodies;
    int16_t num_of_bodies;
    int16_t kinetic_energy;
} System;

System* create_system(int16_t n_bodies, int16_t win_width, int16_t win_height);
void render_system(SDL_Renderer* renderer, System* system);
void update_system(System* system);

#endif

