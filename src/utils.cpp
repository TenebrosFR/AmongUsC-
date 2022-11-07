#include "utils.h"

TextureWithSize CreateTextureWithSizeFromMedia(std::string file_name, SDL_Renderer *renderer, bool color_key){
    TextureWithSize frame;
    frame.first = load_media_texture(file_name,renderer,true);
    SDL_QueryTexture(frame.first,NULL,NULL,&frame.TEXTURE_WIDTH,&frame.TEXTURE_HEIGHT);
    return frame;
}
//