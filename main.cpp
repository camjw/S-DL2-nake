#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/renderer.h"
#include "lib/background.h"
#include "lib/snake.h"
#include "lib/food.h"
#include "lib/timer.h"
#include "lib/game.h"

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int GRID_STRIDE = 20;
const int SCREEN_FPS = 24;

int main( int argc, char* args[] ) {
  Renderer renderer("Snake", GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE);
  Snake snake(renderer, GRID_STRIDE, 20, 20, 255, 255, 255, 255);
  Food food(renderer, GRID_HEIGHT, GRID_HEIGHT, GRID_STRIDE, 192, 192, 192, 255, time(0));
  Background background(renderer, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE);
  Timer fpsTimer;
  Timer capTimer;
  Game game(&renderer, &background, &snake, &food, &fpsTimer, &capTimer, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, SCREEN_FPS);
  game.run();
}
