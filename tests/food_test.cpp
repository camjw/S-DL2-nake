#include <vector>
#include "food_test.h"

using ::testing::ElementsAre;

FoodTest::FoodTest() : mock_renderer() {
};

void FoodTest::SetUp() {
  pFood_ = new Food(mock_renderer, 10, 10, 10, 10, 10, 10, 10, 0);
}

void FoodTest::TearDown() {
  delete pFood_;
}

TEST_F(FoodTest, LocationTest)
{
  EXPECT_THAT(pFood_->getLocation(), ElementsAre(30, 40));
}

TEST_F(FoodTest, ResetLocationTest)
{
  std::deque<std::vector<int>> fakeLocationHistory;
  fakeLocationHistory.push_back(std::vector<int> {30, 40});
  pFood_->resetLocation(fakeLocationHistory);
  EXPECT_THAT(pFood_->getLocation(), ElementsAre(80, 10));
}
