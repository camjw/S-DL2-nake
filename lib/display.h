#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
  int SCREEN_HEIGHT, SCREEN_WIDTH;
  SDL_Window* window;
  SDL_Surface* screenSurface;
  SDL_Surface* displayedImage;
  bool quit;
  SDL_Event e;

  public:
    Display(int width, int height);
    bool init();
    SDL_Surface* loadImage(const char* filename);
    void close();
    void run();
};

#endif
