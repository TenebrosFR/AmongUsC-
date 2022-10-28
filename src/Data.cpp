#include "Data.hpp"

Data::Data(){
    // texture = std::vector<SDL_Texture *>(4,NULL);
        SDL_GetCurrentDisplayMode(0, &DM); 
        screen_width = DM.w;
        screen_height = DM.h;
}
