#include "Player.h"
#include <iostream>
using namespace std;
Player::Player()
{}

Player::~Player()
{}

void Player::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  int flags = 0;
  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    cout << "Subsystems Initialiased.." << endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window)
    {
      cout << "Window created.." << endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);

      cout << "Render created.." << endl;
    }
    isRunning = true;

  }
  else
  {
    isRunning = false;
  }

}

void Player::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  //Permite usar el boton de cerrar ventana.
  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
  default:
    break;
  }
}
void Player::updater()
{}

void Player::render()
{
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

}

void Player::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  cout << "Game Cleaned.." << endl;
}

void Player::test()
{

}
