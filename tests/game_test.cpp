#include "game_test.h"

using ::testing::Return;
using ::testing::AtLeast;
using ::testing::_;

GameTest::GameTest() : mock_renderer(), mock_background(mock_renderer), mock_snake(mock_renderer), mock_food(mock_renderer),
mock_fps_timer(), mock_cap_timer(), mock_scorer(), mock_speaker() {
};

void GameTest::SetUp() {
  pGame_ = new Game(&mock_renderer, &mock_background, &mock_snake, &mock_food, &mock_fps_timer, &mock_cap_timer, &mock_scorer, &mock_speaker, 10, 10, 10, 24);
  ON_CALL(mock_snake, getLocation()).WillByDefault(Return(std::vector<int> {10, 10}));
  std::deque<std::vector<int>> fakeHistory;
  fakeHistory.push_back(std::vector<int> {10, 10});
  ON_CALL(mock_snake, getLocationHistory()).WillByDefault(Return(fakeHistory));

}

void GameTest::TearDown() {
  delete pGame_;
}

TEST_F(GameTest, NoEventPollEventsTest) {
  EXPECT_CALL(mock_snake, pollEvents(_)).Times(0);
  EXPECT_CALL(mock_renderer, pollEvents(_)).Times(0);
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

TEST_F(GameTest, CheckCollisionsTest) {
  ON_CALL(mock_food, getLocation()).WillByDefault(Return(std::vector<int> {10, 10}));
  EXPECT_CALL(mock_snake, grow()).Times(1);
  EXPECT_CALL(mock_food, resetLocation(_)).Times(AtLeast(1));
  pGame_->checkCollisions();
}
