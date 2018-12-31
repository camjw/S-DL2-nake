#include "game_test.h"

GameTest::GameTest() : mock_window(), mock_snake(mock_window), mock_food(mock_window),
mock_fps_timer(), mock_cap_timer() {
};

void GameTest::SetUp() {
  pGame_ = new Game(&mock_window, &mock_snake, &mock_food, &mock_fps_timer, &mock_cap_timer, 10, 10, 10, 24);
}

void GameTest::TearDown() {
  delete pGame_;
}

TEST_F(GameTest, FakeTest) {
  EXPECT_EQ(1,1);
}
