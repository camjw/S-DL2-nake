#include "game.h"

Game::Game(Renderer *r, Background *b, Snake *s, Food *f, Timer *fps, Timer *cap, Scorer *sc, Speaker *sp, int g_width, int g_height, int g_stride, int screen_fps) :
renderer(r), background(b), snake(s), food(f), fpsTimer(fps), capTimer(cap), screen_fps(screen_fps), scorer(sc), speaker(sp), screen_ticks_per_frame(1000/screen_fps), grid_height(g_height) {
}

void Game::pollEvents() {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    renderer->pollEvents(event);
    snake->pollEvents(event);
    pollReset(event);
  }
}

void Game::pollReset(SDL_Event &event) {
  if (snake->isDead()) {
    if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_SPACE:
        reset();
        break;
      }
    }
  }
}

void Game::checkCollisions() {
  std::vector<int> snakeLocation = snake->getLocation();
  std::vector<int> foodLocation = food->getLocation();
  std::deque<std::vector<int>> snakeLocationHistory = snake->getLocationHistory();

  if (foodLocation[0] == snakeLocation[0] && foodLocation[1] == snakeLocation[1]) {
    food->resetLocation(snakeLocationHistory);
    snake->grow();
    scorer->increaseScore();
    speaker->getFood();
  }
}

void Game::playHighScore() {
  int currentScore = scorer->getScore();
  int highScore = scorer->getHighScore();
  if (currentScore >= highScore) {
    speaker->highScore();
  }
}

void Game::redrawScreen() {
  background->draw(scorer->getScore(), scorer->getHighScore());
  snake->draw();
  food->draw();
  checkCollisions();
  snake->checkDeath(grid_height);
  playHighScore();
}

void Game::showSnakeDeath() {
  background->draw(scorer->getScore(), scorer->getHighScore());
  snake->showDeath();
  speaker->death();
}

void Game::adjustFrameRate(int countedFrames) {
  float avgFPS = countedFrames / (fpsTimer->getTicks() / 1000.f);
  ++countedFrames;
  int frameTicks = capTimer->getTicks();
  if(frameTicks < screen_ticks_per_frame) {
    SDL_Delay(screen_ticks_per_frame - frameTicks);
  }
}

void Game::run() {
  int countedFrames = 0;
  fpsTimer->start();
  int updateDisplay = 0;
  while (!renderer->isClosed()) {
    capTimer->start();
    pollEvents();
    if ((updateDisplay == 0) && !snake->isDead()) {
      redrawScreen();
    }
    if (snake->isDead()) {
      showSnakeDeath();
    }
    adjustFrameRate(countedFrames);
    updateDisplay = (updateDisplay + 1) % 4;
  }
};

void Game::reset() {
  snake->reset();
  food->reset();
  scorer->reset();
  speaker->reset();
}
