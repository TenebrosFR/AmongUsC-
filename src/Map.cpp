#include "Map.hpp"

Map::Map(SDL_Renderer *renderer)
{
    img.first = load_media_texture("./Assets/img/map.png", renderer, true);
    SDL_QueryTexture(img.first, NULL, NULL, &img.TEXTURE_WIDTH, &img.TEXTURE_HEIGHT);
    img.TEXTURE_WIDTH *=2;
    img.TEXTURE_HEIGHT *=2;
};
Map::Map(){};
Map::~Map(){};
TextureWithSize Map::GetCurrentTexture(){ return img;};
void Map::UpdatePosition(DoubleDirection givenDirection,double deltaSpeed,Position cameraPosition)
{
    currentPosition.X_COORDINATE -= cameraPosition.X_COORDINATE;
    currentPosition.Y_COORDINATE -= cameraPosition.Y_COORDINATE;
};
