#include "sim.h"

int main(int argc, char* argv[]) {
    Sim sim;

    if (!sim_init(&sim, "Elastic Collision Simulator", 800, 600)) {
        return 1;
    }

    while (sim.is_running) {
        sim_handle_events(&sim);
        sim_render(&sim);
        SDL_Delay(16);
    }

    sim_clean(&sim);
    return 0;
}
