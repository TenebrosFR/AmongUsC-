#include "Data.hpp"

Data::Data(){ 
    //clock = SDL_GetTicks64();
    clock_chrono = std::chrono::high_resolution_clock::now();
};

