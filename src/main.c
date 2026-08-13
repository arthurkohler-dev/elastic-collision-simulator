#include "sim.h"
#include <stdlib.h>
#include <time.h>
#include "config.h"

int main(int argc, char* argv[]) {
    Sim sim;
    srand(time(NULL));

    if (!sim_init(&sim, "Elastic Collision Simulator", WIN_WIDTH, WIN_HEIGHT)) {
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
