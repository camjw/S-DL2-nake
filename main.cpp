#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/window.h"
#include "lib/ship.h"

void pollEvents(Window window, Ship ship) {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    ship.pollEvents(event);
    window.pollEvents(event);
  }
}

int main( int argc, char* args[] ) {
  Window window("Asteroids", 800, 600);
  Ship ship(window, 120, 120, 100, 100, 200, 0, 200, 255);

  while (!window.isClosed()) {
    pollEvents(window, ship);
    ship.draw();
    window.clear();
  }

  return 0;
}
