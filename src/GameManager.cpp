#include "GameManager.hpp"
#define FPS_INTERVAL 1 // seconds.

GameManager::GameManager()
{
    std::cout << SDL_GetError() << std::endl;
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
        shift = (double)speed * (double)(time / 1000);
        clock = SDL_GetTicks64();
        //
        CurrentPlayer.speed = 0;
        newDirection = std::make_pair(NONE, NONE);
        //
        CurrentPlayer.speed = 10;
        const Uint8 *state = SDL_GetKeyboardState(NULL);
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
        // while (SDL_PollEvent(&e))
        // {
        //     if (e.type == SDL_QUIT) quit = true;
        //     if (e.type != SDL_KEYDOWN) continue;

        // }
        std::string sFps = std::to_string(time);
        SDL_SetWindowTitle(window, ("FPS = " + sFps).c_str());
        updateWindow(rect);
    }
}
void GameManager::updateWindow(SDL_Rect rect)
{
    // clear screen
    SDL_RenderClear(renderer);
    CurrentPlayer.UpdatePosition(newDirection);
    rect = {CurrentPlayer.currentPosition.X_COORDINATE, CurrentPlayer.currentPosition.Y_COORDINATE, (CurrentPlayer.GetCurrentTexture().TEXTURE_WIDTH), (CurrentPlayer.GetCurrentTexture().TEXTURE_HEIGHT)};
    SDL_RenderCopyEx(renderer, CurrentPlayer.GetCurrentTexture().first, NULL, &rect, 0, NULL, (newDirection.HORIZONTAL_DIRECTION == LEFT) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    // update new frame
    SDL_RenderPresent(renderer);
}
int GameManager::Start()
{
    whilePlaying();
    close(window, NULL /*,texture*/);
    return 0;
}