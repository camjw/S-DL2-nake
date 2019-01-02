#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "window.h"
#include "snake.h"
#include "timer.h"
#include "food.h"

class Game {
  public:
    Game(Window *w, Snake *s, Food *f, Timer *fps, Timer *cap, int g_width, int g_height, int g_stride, int screen_fps);
    virtual ~Game() {};
    void pollEvents();
    void checkCollisions();
    void run();

  private:
    void redrawScreen();
    void showSnakeDeath();
    void adjustFrameRate(int countedFrames);
    int screen_fps, screen_ticks_per_frame, grid_height;
    Window *window;
    Snake *snake;
    Food *food;
    Timer *fpsTimer, *capTimer;
};
