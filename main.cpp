#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/window.h"
#include "lib/ship.h"

int main( int argc, char* args[] ) {
  Window window("Asteroids", 800, 600);
  Ship ship(window, 120, 120, 100, 100, 200, 0, 200, 255);

  while (!window.isClosed()) {
    ship.draw();
    window.pollEvents();
    window.clear();
  }

  return 0;
}
