#include <vector>
#include "food_test.h"

using ::testing::AtLeast;
using ::testing::ElementsAre;

FoodTest::FoodTest() : mock_window(), subject(mock_window, 10, 10, 10, 10, 10, 10, 10, 0) {
};

TEST_F(FoodTest, LocationTest)
{
  EXPECT_THAT(subject.getLocation(), ElementsAre(0, 10));
}

TEST_F(FoodTest, DrawTest)
{
  subject.draw();
  EXPECT_CALL(mock_window, renderRect(subject.getLocation(), 1, 1, 1, 1, 1)).Times(AtLeast(1));
}

TEST_F(FoodTest, ResetLocationTest)
{
  std::deque<std::vector<int>> fakeLocationHistory;
  fakeLocationHistory.push_back(std::vector<int> {0, 0});
  subject.resetLocation(fakeLocationHistory);
  EXPECT_THAT(subject.getLocation(), ElementsAre(50, 20));
}
