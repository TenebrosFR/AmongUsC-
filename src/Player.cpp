#include "Player.hpp"

Player::Player(SDL_Renderer *renderer)
{
    idle.first = load_media_texture("./Assets/img/Player-AmongUs/IndividualSprites/Walk/walkcolor0001.png", renderer, true);
    SDL_QueryTexture(idle.first, NULL, NULL, &idle.TEXTURE_WIDTH, &idle.TEXTURE_HEIGHT);
    currentSprite = 0;
    speed = 1;
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

void Player::UpdatePosition(DoubleDirection givenDirection)
{
    currentDirection = givenDirection;
    currentSprite++;
    if (currentSprite >= movement.size())
        currentSprite = 0;
    // Choose horizontal direction
    if (currentDirection.HORIZONTAL_DIRECTION == LEFT)
        currentPosition.X_COORDINATE += -1 * speed;
    else if (currentDirection.HORIZONTAL_DIRECTION == RIGHT)
        currentPosition.X_COORDINATE += 1 * speed;
    // Choose vertical direction
    if (currentDirection.VERTICAL_DIRECTION == UP)
        currentPosition.Y_COORDINATE += 1 * speed;
    else if (currentDirection.VERTICAL_DIRECTION == DOWN)
        currentPosition.Y_COORDINATE += -1 * speed;
};

TextureWithSize Player::GetCurrentTexture()
{
    return movement.at(currentSprite);
};