#include "Camera.hpp"

Camera::Camera(SDL_Renderer *renderer)
{
};
Camera::Camera(){};
Camera::~Camera(){};
TextureWithSize Camera::GetCurrentTexture(){ return img;};
void Camera::UpdatePosition(DoubleDirection givenDirection,double deltaSpeed,Position cameraPosition)
{
    if (givenDirection.HORIZONTAL_DIRECTION == LEFT)
        currentPosition.X_COORDINATE -= deltaSpeed;
    else if (givenDirection.HORIZONTAL_DIRECTION == RIGHT)
        currentPosition.X_COORDINATE += deltaSpeed;
    // Choose vertical direction
    if (givenDirection.VERTICAL_DIRECTION == UP)
        currentPosition.Y_COORDINATE += deltaSpeed;
    else if (givenDirection.VERTICAL_DIRECTION == DOWN)
        currentPosition.Y_COORDINATE -= deltaSpeed;
};
