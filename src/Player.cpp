#include "Player.hpp"

Player::Player(SDL_Renderer *renderer){
    idle.first = load_media_texture("./Assets/img/Sprites/01.png",renderer,true);
    SDL_QueryTexture(idle.first,NULL,NULL,&idle.TEXTURE_WIDTH,&idle.TEXTURE_HEIGHT);
    for(int i = 1;i<=12;i++){
        TextureWithSize movementFrame = CreateTextureWithSizeFromMedia("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor000"+std::to_string(i)+".png",renderer,true);
        movement.push_back(movementFrame);
    }
};

Player::Player(){};

void Player::UpdatePosition(direction dir) {
    // if(Player::currentDirection != dir && Player::currentDirection != DOWN && Player::currentDirection != UP){
        // currentSprite = 0;
        currentDirection = dir;
    // } 
    // else {
        currentSprite++;
        if(currentSprite>movement.size()) currentSprite = 0;
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
    return Player::movement[currentSprite];
}