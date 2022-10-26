#include "load_media.hpp"
#include "utils.h"
#include "Props.cpp"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <string> 

class Player : Props
{
    public :
        SDL_Texture* idle;
        std::vector<SDL_Texture *> movement;
        direction currentDirection = RIGHT;

        Player(SDL_Renderer *renderer){
            idle = load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/idle.png",renderer,true);
            for(int i = 1;i<=12;i++){
                movement.push_back(load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor000"+std::to_string(i)+".png",renderer,true));
            }
        };
        Player(){};
        void UpdateTexture() override {
        };
};