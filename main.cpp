#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/window.h"
#include "lib/ship.h"

void pollEvents(Window &window, Ship &ship) {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    window.pollEvents(event);
    ship.pollEvents(event);
  }
}

int main( int argc, char* args[] ) {
  Window window("Asteroids", 800, 600);
  Ship ship(window, 20, 20, 10, 10, 200, 0, 200, 255);

  while (!window.isClosed()) {
    pollEvents(window, ship);
    ship.draw();
    window.clear();
  }

  return 0;
}
