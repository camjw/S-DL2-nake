#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/window.h"
#include "lib/snake.h"
#include "lib/food.h"
#include "lib/timer.h"
#include "lib/game.h"

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int GRID_STRIDE = 20;
const int SCREEN_FPS = 24;

int main( int argc, char* args[] ) {
  Window window("Snake", GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE);
  Snake snake(window, GRID_STRIDE, 20, 20, 255, 255, 255, 255);
  Food food(window, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, 192, 192, 192, 255, time(0));
  Timer fpsTimer;
  Timer capTimer;
  Game game(&window, &snake, &food, &fpsTimer, &capTimer, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, SCREEN_FPS);
  game.run();
}
