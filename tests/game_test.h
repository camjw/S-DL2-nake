#ifndef GAME_TEST_H
#define GAME_TEST_H
#include <gtest/gtest.h>
#include "../lib/game.h"
#include "../lib/mocks/mock_renderer.h"
#include "../lib/mocks/mock_background.h"
#include "../lib/mocks/mock_snake.h"
#include "../lib/mocks/mock_food.h"
#include "../lib/mocks/mock_timer.h"
#include "../lib/mocks/mock_scorer.h"

class GameTest : public ::testing::Test {
  public:
    GameTest();
    virtual void SetUp();
    virtual void TearDown();
    Game * pGame_;
    MockRenderer mock_renderer;
    MockSnake mock_snake;
    MockFood mock_food;
    MockBackground mock_background;
    MockTimer mock_fps_timer, mock_cap_timer;
    MockScorer mock_scorer;
};

#endif
