#include "SDL.h"
#include "Player.h"
#include <iostream>

Player* player = nullptr;
//test1
//test2
int main(int argc, char* argv[])
{
  player = new Player();
  player->init("Barca", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, false);
  while (player->running())
  {
    player->handleEvents();
    player->updater();
    player->render();

  }

  player->clean();
  /*SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("Barca", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);*/
  return 0;
};

