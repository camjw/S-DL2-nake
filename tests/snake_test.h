#ifndef SNAKE_TEST_H
#define SNAKE_TEST_H
#include <gtest/gtest.h>
#include "../lib/snake.h"
#include "../lib/mocks/mock_window.h"

class SnakeTest : public ::testing::Test {
  public:
    SnakeTest();
    Snake subject;
    MockWindow mock_window;
};

#endif
