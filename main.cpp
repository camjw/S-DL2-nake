#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include "lib/window.h"
#include "lib/snake.h"
#include "lib/timer.h"
#include "lib/food.h"

void pollEvents(Window &window, Snake &snake) {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    window.pollEvents(event);
    snake.pollEvents(event);
  }
}

void checkCollisions(Snake &snake, Food &food) {
  std::vector<int> snakeLocation = snake.getLocation();
  std::vector<int> foodLocation = food.getLocation();
  std::deque<std::vector<int>> snakeLocationHistory = snake.getLocationHistory();

  if (foodLocation[0] == snakeLocation[0] && foodLocation[1] == snakeLocation[1]) {
    food.resetLocation(snakeLocationHistory);
    snake.grow();
  }
}

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int GRID_STRIDE = 20;
const int SCREEN_FPS = 24;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main( int argc, char* args[] ) {
  Window window("Snake", GRID_WIDTH * GRID_STRIDE, GRID_HEIGHT * GRID_STRIDE);
  Snake snake(window, 20, 20, 20, 20, 255, 255, 255, 255);
  Food food(window, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, 192, 192, 192, 255, time(0));
  Timer fpsTimer;
  Timer capTimer;

  int countedFrames = 0;
  fpsTimer.start();
  bool updateDisplay = true;
  while (!window.isClosed()) {
    capTimer.start();
    pollEvents(window, snake);
    if (updateDisplay) {
      snake.draw();
      window.draw();
      food.draw();
      checkCollisions(snake, food);
    }
    float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
    ++countedFrames;
    int frameTicks = capTimer.getTicks();
    if(frameTicks < SCREEN_TICKS_PER_FRAME) {
      SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
    }
    updateDisplay = !updateDisplay;
  }

  return 0;
}
