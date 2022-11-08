#include "GameManager.hpp"
#define FPS_INTERVAL 1 // seconds.

GameManager::GameManager()
{
    // If No error to load sdl
    if (!init_SDL(&window, &window_surface, &renderer, &screen_height, &screen_width))
        return;

    // set l'icon de la page
    SDL_Surface *icon = IMG_Load("./Assets/img/icon.png");
    SDL_SetWindowIcon(window, icon);

    // create current player
    CurrentPlayer = Player(renderer);
    // start game
    Start();
}

void GameManager::whilePlaying()
{
    while (!quit)
    {
        // time
        time = SDL_GetTicks64() - clock;
        shift = (double)CurrentPlayer.speed * (double)(time);

        clock = SDL_GetTicks64();
        newDirection = std::make_pair(NONE, NONE);
        // events
        SDL_PumpEvents();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        InputManager(state);
        //
        std::string sFps = std::to_string(time);
        SDL_SetWindowTitle(window, ("FPS = " + sFps).c_str());
        //
        updateWindow(rect);
    }
};
void GameManager::InputManager(const Uint8 *state)
{
    if (state[SDL_SCANCODE_ESCAPE])
        quit = true;
    // Choose horizontal direction
    if (state[SDL_SCANCODE_A])
        newDirection.HORIZONTAL_DIRECTION = LEFT;
    else if (state[SDL_SCANCODE_D])
        newDirection.HORIZONTAL_DIRECTION = RIGHT;
    // Choose vertical direction
    if (state[SDL_SCANCODE_S])
        newDirection.VERTICAL_DIRECTION = UP;
    else if (state[SDL_SCANCODE_W])
        newDirection.VERTICAL_DIRECTION = DOWN;
    // fullscreen
    if (state[SDL_SCANCODE_F])
    {
        (!isFullscreen ? SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN) : SDL_SetWindowFullscreen(window, 0));
        isFullscreen = !isFullscreen;
    }
};
void GameManager::updateWindow(SDL_Rect rect)
{
    // clear screen
    SDL_RenderClear(renderer);
    CurrentPlayer.UpdatePosition(newDirection,shift);
    rect = {(int)CurrentPlayer.currentPosition.X_COORDINATE, (int)CurrentPlayer.currentPosition.Y_COORDINATE, (CurrentPlayer.GetCurrentTexture().TEXTURE_WIDTH), (CurrentPlayer.GetCurrentTexture().TEXTURE_HEIGHT)};
    if(newDirection.HORIZONTAL_DIRECTION != NONE)   rotate =  newDirection.HORIZONTAL_DIRECTION == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, CurrentPlayer.GetCurrentTexture().first, NULL, &rect, 0, NULL, rotate);
    // update new frame
    SDL_RenderPresent(renderer);
}
int GameManager::Start()
{
    whilePlaying();
    close(window, NULL /*,texture*/);
    return 0;
}