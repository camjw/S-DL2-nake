#ifndef MOCK_SNAKE_H
#define MOCK_SNAKE_H
#include <gmock/gmock.h>
#include <vector>
#include <deque>
#include "../snake.h"
#include "mock_window.h"

class MockSnake : public Snake {
  public:
    MockSnake(MockWindow &mock_window);
    virtual ~MockSnake() {};
    MOCK_METHOD1(pollEvents, void(SDL_Event &event));
    MOCK_METHOD0(getLocation, std::vector<int>());
    MOCK_METHOD0(getLocationHistory, std::deque<std::vector<int>>());
    MOCK_METHOD0(grow, void());
};

#endif
