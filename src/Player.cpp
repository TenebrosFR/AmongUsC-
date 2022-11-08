#include "Player.hpp"

Player::Player(SDL_Renderer *renderer){
    idle.first = load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor0001.png",renderer,true);
    SDL_QueryTexture(idle.first,NULL,NULL,&idle.TEXTURE_WIDTH,&idle.TEXTURE_HEIGHT);
    currentSprite = 0;
    speed = 10;
    for(int i = 1;i<=12;i++){
        std::string remplacement = std::to_string(i);
        if(i<10) remplacement = "0"+std::to_string(i);
        TextureWithSize movementFrame = CreateTextureWithSizeFromMedia("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor00"+remplacement+".png",renderer,true);
        movement.push_back(movementFrame);
    }
};

Player::Player(){
    currentSprite = 0;
    speed = 10;
};

void Player::UpdatePosition(direction dir) {
    // if(Player::currentDirection != dir && Player::currentDirection != DOWN && Player::currentDirection != UP){
        // currentSprite = 0;
        currentDirection = dir;
    // } 
    // else {
        currentSprite++;
        if(currentSprite>=movement.size()) currentSprite = 0;
    // }
    switch(dir){
        case DOWN:
            currentPosition.Y_COORDINATE += -1 * speed ;
            break;
        case UP:
            currentPosition.Y_COORDINATE += 1 * speed ;
            break;
        case LEFT:
            currentPosition.X_COORDINATE += -1 * speed ;
            break;
        case RIGHT:
            currentPosition.X_COORDINATE += 1 * speed ;
            break;
    }
};

TextureWithSize Player::GetCurrentTexture(){
    return movement.at(currentSprite);
};