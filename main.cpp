#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include "lib/window.h"
#include "lib/snake.h"
#include "lib/timer.h"
#include "lib/food.h"
// #include "lib/game.h"

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int GRID_STRIDE = 20;
const int SCREEN_FPS = 24;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

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

int main( int argc, char* args[] ) {
  Window window("Snake", GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE);
  Snake snake(window, GRID_STRIDE, 20, 20, 255, 255, 255, 255);
  Food food(window, GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, 192, 192, 192, 255, time(0));
  // Game(GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, SCREEN_FPS);
  Timer fpsTimer;
  Timer capTimer;

  int countedFrames = 0;
  fpsTimer.start();
  bool updateDisplay = true;
  while (!window.isClosed()) {
    capTimer.start();
    pollEvents(window, snake);
    if (updateDisplay && !snake.isDead()) {
      window.draw();
      snake.draw();
      food.draw();
      checkCollisions(snake, food);
      snake.checkSelfEat();
    }
    if (snake.isDead()) {
      window.draw();
      snake.showDeath();
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
