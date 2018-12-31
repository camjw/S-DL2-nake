#include <vector>
#include "snake_test.h"

using ::testing::ElementsAre;

SnakeTest::SnakeTest() : mock_window() {
};

void SnakeTest::SetUp() {
  pSnake_ = new Snake(mock_window, 10, 10, 10, 10, 10, 10, 10);
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
