#include "game_test.h"

using ::testing::Return;

GameTest::GameTest() : mock_window(), mock_snake(mock_window), mock_food(mock_window),
mock_fps_timer(), mock_cap_timer() {
};

void GameTest::SetUp() {
  pGame_ = new Game(&mock_window, &mock_snake, &mock_food, &mock_fps_timer, &mock_cap_timer, 10, 10, 10, 24);
  ON_CALL(mock_snake, getLocation()).WillByDefault(Return(std::vector<int> {10, 10}));
  std::deque<std::vector<int>> fakeHistory;
  fakeHistory.push_back(std::vector<int> {10, 10});
  ON_CALL(mock_snake, getLocationHistory()).WillByDefault(Return(fakeHistory));
}

void GameTest::TearDown() {
  delete pGame_;
}

TEST_F(GameTest, NoEventPollEventsTest) {
  EXPECT_CALL(mock_snake, pollEvents(testing::_)).Times(0);
  EXPECT_CALL(mock_window, pollEvents(testing::_)).Times(0);
  pGame_->pollEvents();
}

TEST_F(GameTest, CheckNoCollisionsTest) {
  ON_CALL(mock_food, getLocation()).WillByDefault(Return(std::vector<int> {20, 20}));
  EXPECT_CALL(mock_snake, getLocation()).Times(1);
  EXPECT_CALL(mock_snake, getLocationHistory()).Times(1);
  EXPECT_CALL(mock_food, getLocation()).Times(1);
  EXPECT_CALL(mock_snake, grow()).Times(0);
  pGame_->checkCollisions();
}
