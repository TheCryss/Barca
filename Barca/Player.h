#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
class Player
{
public:
  Player();
  ~Player();
  void test();
  void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
  void handleEvents();
  void updater();
  void render();
  void clean();
  bool running() { return isRunning; };
private:
  bool isRunning;
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif // !PLAYER_H



