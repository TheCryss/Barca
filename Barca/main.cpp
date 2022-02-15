#include "SDL.h"
#include "Game.h"
#include <iostream>

Game* game = nullptr;
//test1
//test2
int main(int argc, char* args[]) {
    //Creamos nuestra clase game
    auto game = Game();
    try {
        game.init();

        //Bucle Principal|
        while (game.isRunning()) {
            // Gestion de eventos (Leer inputs por ejemplo)
            game.handleEvents();

            // Actualiza (Fisica y Logica del juego, actualiza en funcion del input)
            game.update();

            //Renderiza (Una vez actualizado se renderiza)
            game.render();
        }

        game.release();
    }
    catch (std::exception& exception) {
        fprintf(stderr, exception.what());
        SDL_Quit();
        return -1;
    }

    return 0;
}

