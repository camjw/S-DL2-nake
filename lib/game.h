#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "window.h"
#include "snake.h"
#include "timer.h"
#include "food.h"

class Game {
  public:
    Game(int g_width, int g_height, int g_stride, int fps);
    virtual ~Game() {};
    void pollEvents();
    void checkCollisions();
    void run();

  private:
    void redrawScreen();
    void showSnakeDeath();
    void adjustFrameRate();
    int grid_width, grid_height, grid_stride, screen_fps, screen_ticks_per_frame;
    Window window;
    Snake snake;
    Food food;
    Timer fpsTimer, capTimer;
};
