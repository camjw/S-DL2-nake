#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "renderer.h"
#include "background.h"
#include "snake.h"
#include "timer.h"
#include "food.h"
#include "scorer.h"

class Game {
  public:
    Game(Renderer *w, Background *b, Snake *s, Food *f, Timer *fps, Timer *cap, Scorer *sc, int g_width, int g_height, int g_stride, int screen_fps);
    void pollEvents();
    void checkCollisions();
    void run();
    void reset();
    virtual ~Game() {};

  private:
    void redrawScreen();
    void pollReset(SDL_Event &event);
    void showSnakeDeath();
    void adjustFrameRate(int countedFrames);
    int screen_fps, screen_ticks_per_frame, grid_height;
    Renderer *renderer;
    Background *background;
    Snake *snake;
    Food *food;
    Timer *fpsTimer, *capTimer;
    Scorer *scorer;
};
