#ifndef SIM_H
#define SIM_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "body.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool is_running;
} Sim;

bool sim_init(Sim* sim, const char* title, int16_t width, int16_t height);
void sim_handle_events(Sim* sim);
void sim_render(Sim* sim);
void sim_clean(Sim* sim);
void sim_update();

#endif
