#include "Props.hpp"
#include "Player.hpp"

Player::Player(SDL_Renderer *renderer){
    idle = load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/idle.png",renderer,true);
    for(int i = 1;i<=12;i++){
        movement.push_back(load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor000"+std::to_string(i)+".png",renderer,true));
    }
};
void Player::UpdateTexture() {
};