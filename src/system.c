#include "system.h"

System* create_system(int16_t n_bodies, int16_t win_width, int16_t win_height) {
    System* system = (System*) malloc(sizeof(System));
    system.num_of_bodies = n_bodies;
    system.kinetic_energy = 0;
    
    //the actual list of bodies need to be a linked list, makes more sense...

    return system;
}

void render_system(SDL_Renderer* renderer, System* system) {

}
