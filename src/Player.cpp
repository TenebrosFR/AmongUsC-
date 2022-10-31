#include "Player.hpp"

Player::Player(SDL_Renderer *renderer){
    idle.first = load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/idle.png",renderer,true);
    SDL_QueryTexture(idle.first,NULL,NULL,getTextureWidth(&idle),getTextureHeight(&idle));
    for(int i = 1;i<=12;i++){
        TextureWithSize movementFrame = CreateTextureWithSizeFromMedia("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor000"+std::to_string(i)+".png",renderer,true);
        movement.push_back(movementFrame);
    }
};
Player::Player(){};
void Player::UpdateTexture() {};