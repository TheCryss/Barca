#include "Game.h"
#include "SDL_Exception.h"
using namespace std;

Game::Game()
{}

Game::~Game()
{}


void Game::init() {
    initSDL();
    createWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 0, 255, 255);

    _isRunning = true;
}

void Game::initSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }
}

void Game::createWindowAndRender() {
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);

    if (_window == NULL || _renderer == NULL) {
        throw SDL_Exception(SDL_GetError());
    }
}


void Game::handleEvents() {
    /*SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        }
    }*/

    SDL_Event event;
    SDL_PollEvent(&event);
    //Permite usar el boton de cerrar ventana.
    switch (event.type)
    {
    case SDL_QUIT:
        _isRunning = false;
    default:
        break;
    }
}

void Game::update() {

}

void Game::render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.

    SDL_RenderPresent(_renderer);
}

void Game::release() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Game::isRunning() {
    return _isRunning;
}


void Game::test()
{

}
