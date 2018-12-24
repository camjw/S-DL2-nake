#include "game.h"

Game::Game(int g_width, int g_height, int g_stride, int fps) :
grid_width(g_width), grid_height(g_height), grid_stride(g_stride), screen_fps(fps),
window("Snake", grid_width, grid_height, grid_stride),
snake(window, grid_stride, 20, 20, 255, 255, 255, 255),
food(window, grid_width, grid_height, grid_stride, 192, 192, 192, 255, time(0)),
fpsTimer(), capTimer(), screen_ticks_per_frame(1000/fps) {
}

void Game::pollEvents() {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    window.pollEvents(event);
    snake.pollEvents(event);
  }
}

void Game::checkCollisions() {
  std::vector<int> snakeLocation = snake.getLocation();
  std::vector<int> foodLocation = food.getLocation();
  std::deque<std::vector<int>> snakeLocationHistory = snake.getLocationHistory();

  if (foodLocation[0] == snakeLocation[0] && foodLocation[1] == snakeLocation[1]) {
    food.resetLocation(snakeLocationHistory);
    snake.grow();
  }
}

void Game::run() {
  int countedFrames = 0;
    fpsTimer.start();
    bool updateDisplay = true;
    while (!window.isClosed()) {
      capTimer.start();
      pollEvents();
      if (updateDisplay && !snake.isDead()) {
        window.draw();
        snake.draw();
        food.draw();
        checkCollisions();
        snake.checkSelfEat();
      }
      if (snake.isDead()) {
        window.draw();
        snake.showDeath();
      }
      float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
      ++countedFrames;
      int frameTicks = capTimer.getTicks();
      if(frameTicks < screen_ticks_per_frame) {
        SDL_Delay(screen_ticks_per_frame - frameTicks);
      }
      updateDisplay = !updateDisplay;
    }
};
