#include "Player.hpp"

Player::Player(SDL_Renderer *renderer)
{
    idle.first = load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/idle.png", renderer, true);
    SDL_QueryTexture(idle.first, NULL, NULL, &idle.TEXTURE_WIDTH, &idle.TEXTURE_HEIGHT);
    currentSprite = 0;
    speed = 0.5;
    for (int i = 1; i <= 12; i++)
    {
        std::string remplacement = std::to_string(i);
        if (i < 10)
            remplacement = "0" + std::to_string(i);
        TextureWithSize movementFrame = CreateTextureWithSizeFromMedia("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor00" + remplacement + ".png", renderer, true);
        movement.push_back(movementFrame);
    }
};

Player::Player(){};

void Player::UpdatePosition(DoubleDirection givenDirection,double deltaSpeed)
{
    //
    static Uint64 clock = SDL_GetTicks64(); 
    //
    currentDirection = givenDirection;
    //
    if((SDL_GetTicks64()-clock) > 50) {
        currentSprite++;
        clock = SDL_GetTicks64(); 
    }
    //
    if (currentDirection.HORIZONTAL_DIRECTION == NONE && currentDirection.VERTICAL_DIRECTION == NONE )
        currentSprite = 13;
    else if (currentSprite >= movement.size() )
        currentSprite = 0;
    // Choose horizontal direction
    if (currentDirection.HORIZONTAL_DIRECTION == LEFT)
        currentPosition.X_COORDINATE += -deltaSpeed;
    else if (currentDirection.HORIZONTAL_DIRECTION == RIGHT)
        currentPosition.X_COORDINATE += deltaSpeed;
    // Choose vertical direction
    if (currentDirection.VERTICAL_DIRECTION == UP)
        currentPosition.Y_COORDINATE += deltaSpeed;
    else if (currentDirection.VERTICAL_DIRECTION == DOWN)
        currentPosition.Y_COORDINATE += -deltaSpeed;
};

TextureWithSize Player::GetCurrentTexture()
{
    return (currentSprite == 13) ? idle : movement.at(currentSprite) ;
};