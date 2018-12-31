#include <vector>
#include "food_test.h"

using ::testing::ElementsAre;

FoodTest::FoodTest() : mock_window() {
};

void FoodTest::SetUp() {
  pFood_ = new Food(mock_window, 10, 10, 10, 10, 10, 10, 10, 0);
}

void FoodTest::TearDown() {
  delete pFood_;
}

TEST_F(FoodTest, LocationTest)
{
  EXPECT_THAT(pFood_->getLocation(), ElementsAre(0, 10));
}

TEST_F(FoodTest, ResetLocationTest)
{
  std::deque<std::vector<int>> fakeLocationHistory;
  fakeLocationHistory.push_back(std::vector<int> {0, 0});
  pFood_->resetLocation(fakeLocationHistory);
  EXPECT_THAT(pFood_->getLocation(), ElementsAre(50, 20));
}
