#ifndef RENDERER_H
#define RENDERER_H
#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Renderer {
  public:
    Renderer(const std::string &title, int width, int height, int stride);
    virtual ~Renderer();
    void pollEvents(SDL_Event &event);
    inline bool isClosed() const { return _closed; }
    void renderRect(std::vector<int> rectCoords, int stride, int r, int g, int b, int a);

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
