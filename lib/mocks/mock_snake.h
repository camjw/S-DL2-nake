#ifndef MOCK_SNAKE_H
#define MOCK_SNAKE_H
#include <gmock/gmock.h>
#include "../snake.h"

class MockSnake : public Snake {
  public:
    MockSnake(MockWindow &mock_window);
    virtual ~MockSnake() {};
};

#endif
