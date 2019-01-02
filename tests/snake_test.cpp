#include "snake_test.h"

using ::testing::ElementsAre;

SnakeTest::SnakeTest() : mock_renderer() {
};

void SnakeTest::SetUp() {
  pSnake_ = new Snake(mock_renderer, 10, 10, 10, 10, 10, 10, 10);
}

void SnakeTest::TearDown() {
  delete pSnake_;
}

TEST_F(SnakeTest, InitialLocationTest)
{
  EXPECT_THAT(pSnake_->getLocation(), ElementsAre(10, 10));
}

TEST_F(SnakeTest, AfterMoveLocationTest)
{
  pSnake_->move();
  EXPECT_THAT(pSnake_->getLocation(), ElementsAre(20, 10));
}
