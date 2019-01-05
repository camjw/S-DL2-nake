#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/renderer.h"
#include "lib/background.h"
#include "lib/snake.h"
#include "lib/food.h"
#include "lib/timer.h"
#include "lib/game.h"
#include "lib/scorer.h"
#include "lib/speaker.h"

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int GRID_STRIDE = 20;
const int SCREEN_FPS = 48;

int main( int argc, char* args[] ) {
  Renderer renderer("Snake", GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE);
  Snake snake(renderer, GRID_HEIGHT, GRID_STRIDE, 255, 255, 255, 255, time(0) + 1);
  Food food(renderer, GRID_HEIGHT, GRID_HEIGHT, GRID_STRIDE, 192, 192, 192, 255, time(0));
  Background background(renderer, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE);
  Timer fpsTimer;
  Timer capTimer;
  Scorer scorer;
  Speaker speaker;
  Game game(&renderer, &background, &snake, &food, &fpsTimer, &capTimer, &scorer, &speaker, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, SCREEN_FPS);
  game.run();
}
