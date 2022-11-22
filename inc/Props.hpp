#pragma once

#include "load_media.hpp"
#include "utils.h"
class Props
{
    public :
    virtual ~Props();

    virtual TextureWithSize GetCurrentTexture()=0;
    virtual void UpdatePosition(DoubleDirection givenDirection,double deltaSpeed,Position cameraPosition)=0;
};
