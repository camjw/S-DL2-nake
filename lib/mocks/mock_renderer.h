#ifndef MOCK_WINDOW_H
#define MOCK_WINDOW_H
#include <gmock/gmock.h>
#include "../renderer.h"

class MockRenderer : public Renderer {
  public:
    MockRenderer();
    virtual ~MockRenderer() {};
    MOCK_METHOD1(pollEvents, void(SDL_Event &event));
};

#endif
