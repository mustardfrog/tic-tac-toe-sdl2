#include "Game.hpp"
#include "Tictactoe.hpp"
#include <cstdio>

SDL_Renderer *Game::renderer = nullptr;

Game::Game(){ };

void Game::init() {
    // if (IMG_Init(IMG_INIT_PNG) == 0) {
    //     printf("failed to initialize png");
    // };

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("cannot start sdl");
    }

    m_Window = SDL_CreateWindow(
        "Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (m_Window == NULL) {
        printf("m_Window is null");
        m_IsRunning = false;
    }

    renderer = SDL_CreateRenderer(m_Window, -1, 0);


    if (renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (renderer == NULL) {
        printf("renderer is null");
        m_IsRunning = false;
    }
    m_IsRunning = true;
}

void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        m_IsRunning = false;
        break;

    default:
        break;
    }
}

void Game::update() {}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 10);
    SDL_RenderClear(renderer);

    // render shits here
    tictactoe.drawGrid(renderer);

    // ------------------
    SDL_SetRenderDrawColor(renderer, 0, 100, 100, 10);

    SDL_RenderPresent(renderer);
}

Game::~Game() {
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
