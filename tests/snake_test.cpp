#include "snake_test.h"

using ::testing::ElementsAre;

SnakeTest::SnakeTest() : mock_renderer() {
};

void SnakeTest::SetUp() {
  pSnake_ = new Snake(mock_renderer, 10, 10, 10, 10, 10, 10, 0);
}

void SnakeTest::TearDown() {
  delete pSnake_;
}

TEST_F(SnakeTest, InitialLocationTest)
{
  EXPECT_THAT(pSnake_->getLocation(), ElementsAre(30, 40));
}

TEST_F(SnakeTest, AfterMoveLocationTest)
{
  pSnake_->move();
  EXPECT_THAT(pSnake_->getLocation(), ElementsAre(40, 40));
}
