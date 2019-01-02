#ifndef MOCK_BACKGROUND_H
#define MOCK_BACKGROUND_H
#include <gmock/gmock.h>
#include "../background.h"
#include "mock_renderer.h"

class MockBackground : public Background {
  public:
    MockBackground(MockRenderer &mock_renderer);
    virtual ~MockBackground() {};
    MOCK_METHOD0(draw, void());
};

#endif
