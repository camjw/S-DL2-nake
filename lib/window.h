#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <SDL2/SDL.h>

class Window {
  public:
    Window(const std::string &title, int width, int height);
    virtual ~Window();

    virtual void pollEvents(SDL_Event &event);
    virtual void draw() const;
    virtual inline bool isClosed() const { return _closed; }

  private:
    virtual bool init();
    std::string _title;
    int _width = 800;
    int _height = 600;
    bool _closed = false;

    SDL_Window *_window = nullptr;

  protected:
    SDL_Renderer *_renderer = nullptr;
};

#endif
