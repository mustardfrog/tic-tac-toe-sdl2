#pragma once
#include <SDL2/SDL.h>
#include <cstdio>

#include "Tictactoe.hpp"

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

class Game {
  public:
    static SDL_Renderer *renderer;

    Game();
    ~Game();

    void init();
    void handleEvent();
    void update();
    void render();
    void clean();
    bool running() { return m_IsRunning; };
    Tictactoe tictactoe;

  private:
    bool m_IsRunning = false;
    SDL_Window *m_Window;
};
