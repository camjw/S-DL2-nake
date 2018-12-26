#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Window {
  public:
    Window(const std::string &title, int width, int height, int stride);
    virtual ~Window();
    virtual void pollEvents(SDL_Event &event);
    virtual void draw() const;
    virtual inline bool isClosed() const { return _closed; }
    virtual void renderRect(std::vector<int> rectCoords, int stride, int r, int g, int b, int a);

  private:
    virtual bool init();
    std::string _title;
    int _width;
    int _height;
    int _stride;
    bool _closed = false;

    SDL_Window *_window = nullptr;

  protected:
    SDL_Renderer *_renderer = nullptr;
};

#endif
