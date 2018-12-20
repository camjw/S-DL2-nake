#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include "lib/window.h"
#include "lib/snake.h"
#include "lib/timer.h"

void pollEvents(Window &window, Snake &snake) {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    window.pollEvents(event);
    snake.pollEvents(event);
  }
}

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 1;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main( int argc, char* args[] ) {
  Window window("Asteroids", SCREEN_WIDTH, SCREEN_HEIGHT);
  Snake snake(window, 20, 20, 10, 10, 255, 255, 255, 255);
  Timer fpsTimer;
  Timer capTimer;

  int countedFrames = 0;
  fpsTimer.start();

  while (!window.isClosed()) {
    capTimer.start();
    pollEvents(window, snake);
    snake.draw();
    window.draw();
    float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
    ++countedFrames;
    int frameTicks = capTimer.getTicks();
    if(frameTicks < SCREEN_TICKS_PER_FRAME) {
      SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
    }
  }

  return 0;
}
