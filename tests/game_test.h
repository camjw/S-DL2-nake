#ifndef GAME_TEST_H
#define GAME_TEST_H
#include <gtest/gtest.h>
#include "../lib/game.h"
#include "../lib/mocks/mock_window.h"
#include "../lib/mocks/mock_snake.h"
#include "../lib/mocks/mock_food.h"
#include "../lib/mocks/mock_timer.h"

class GameTest : public ::testing::Test {
  public:
    GameTest();
    virtual void SetUp();
    virtual void TearDown();
    Game * pGame_;
    MockWindow mock_window;
    MockSnake mock_snake;
    MockFood mock_food;
    MockTimer mock_fps_timer, mock_cap_timer;
};

#endif
