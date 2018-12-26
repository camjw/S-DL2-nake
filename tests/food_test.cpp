#include <vector>
#include "food_test.h"

FoodTest::FoodTest() : mock_window(), subject(mock_window, 10, 10, 10, 10, 10, 10, 10, 0) {
};

TEST_F(FoodTest, LocationTest)
{
  std::vector<int> location = subject.getLocation();
  ASSERT_TRUE(location.at(0) == 0);
  ASSERT_TRUE(location.at(1) == 10);

}
