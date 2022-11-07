#include "utils.h"

int* getTextureWidth(TextureWithSize *texture){
    return &( (*texture).second.first );
};
int* getTextureHeight(TextureWithSize *texture){
    return &( (*texture).second.second );
};
TextureWithSize CreateTextureWithSizeFromMedia(std::string file_name, SDL_Renderer *renderer, bool color_key){
    TextureWithSize frame;
    frame.first = load_media_texture(file_name,renderer,true);
    SDL_QueryTexture(frame.first,NULL,NULL,getTextureWidth(&frame),getTextureHeight(&frame));
    return frame;
}