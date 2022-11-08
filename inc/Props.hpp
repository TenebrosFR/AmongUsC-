#pragma once

#include "load_media.hpp"
#include "utils.h"
class Props
{
    public :
    virtual ~Props();

    virtual TextureWithSize GetCurrentTexture()=0;
    virtual void UpdatePosition(direction dir)=0;
};
