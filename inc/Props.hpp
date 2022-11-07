#pragma once

#include "load_media.hpp"
#include "utils.h"
class Props
{
    public :
    virtual TextureWithSize GetCurrentTexture();
    virtual void UpdatePosition(direction dir);
    virtual ~Props();
};
