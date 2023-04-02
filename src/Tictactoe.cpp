#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "Tictactoe.hpp"
#include "Game.hpp"

void Tictactoe::drawGrid(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
    for (int i = -2; i < WINDOW_WIDTH; i += 301) {
        SDL_RenderDrawLine(renderer, i, 0, i, WINDOW_HEIGHT);
    }
    for (int i = -2; i < WINDOW_HEIGHT; i += 201) {
        SDL_RenderDrawLine(renderer, 0, i, WINDOW_WIDTH, i);
    }
    // SDL_RenderDrawLine(renderer, 0, 20, WINDOW_HEIGHT/3, 20);
}
