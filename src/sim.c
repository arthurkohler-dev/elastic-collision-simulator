#include "sim.h"
#include <stdio.h>

bool sim_init(Sim* sim, const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro SDL: %s\n", SDL_GetError());
        return false;
    }

    sim->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!sim->window) return false;

    sim->renderer = SDL_CreateRenderer(sim->window, -1, SDL_RENDERER_ACCELERATED);
    if (!sim->renderer) return false;

    sim->is_running = true;
    return true;
}

void sim_handle_events(Sim* sim) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            sim->is_running = false;
        }
    }
}

void sim_render(Sim* sim) {
    SDL_SetRenderDrawColor(sim->renderer, 0, 0, 0, 255);
    SDL_RenderClear(sim->renderer);
    SDL_RenderPresent(sim->renderer);
}

void sim_clean(Sim* sim) {
    if (sim->renderer) SDL_DestroyRenderer(sim->renderer);
    if (sim->window) SDL_DestroyWindow(sim->window);
    SDL_Quit();
}

void sim_update() {

}
