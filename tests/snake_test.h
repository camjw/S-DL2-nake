#ifndef SNAKE_TEST_H
#define SNAKE_TEST_H
#include <gtest/gtest.h>
#include "../lib/snake.h"
#include "../lib/mocks/mock_renderer.h"

class SnakeTest : public ::testing::Test {
  public:
    SnakeTest();
    virtual void SetUp();
    virtual void TearDown();
    Snake * pSnake_;
    MockRenderer mock_renderer;
};

#endif
