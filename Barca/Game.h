/*
Este ifndef y define sirve para evitar probelmas con el compilado. Es decir, si en varios sitios incluimos la misma clase, el compilador de C lo que hara es incluirlo en esos ficheros y nos dara error de que ya se ha includo ese fichero (Para evitar este error hacemos el define)

Si ya no esta includo => incluyelo
Si ya esta incluido => no lo incluyas
*/

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
using namespace std;

class Game
{
public:

  Game();

  ~Game();

  void test();

  void init();

  void handleEvents();

  void update();

  void render();

  void release();

  bool isRunning();

private:
    void initSDL();

    void createWindowAndRender();

private:
    bool _isRunning;

    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif // !Game_H



