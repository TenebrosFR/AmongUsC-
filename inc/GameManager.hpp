#include "Initializer.hpp"
#include "load_media.hpp"
#include "Data.hpp"
#include <vector>
#include <string>

class GameManager : Data,Initializer
{
public:
    

    GameManager();

    void whilePlaying();

    void updateWindow(SDL_Rect rect);
    
    int Start();
};