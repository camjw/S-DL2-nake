#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/window.h"
#include "lib/snake.h"

void pollEvents(Window &window, Snake &snake) {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    window.pollEvents(event);
    snake.pollEvents(event);
  }
}

int main( int argc, char* args[] ) {
  Window window("Asteroids", 800, 600);
  Snake snake(window, 20, 20, 10, 10, 255, 255, 255, 255);

  while (!window.isClosed()) {
    pollEvents(window, snake);
    snake.draw();
    window.clear();
  }

  return 0;
}
