#include "food_test.h"

void FoodTest::SetUp() {
  testFood = Food();
};

TEST_F(FoodTest, OperatorTest)
{
  std::vector<int> expectedPos;
  expectedPos.push_back(10);
  expectedPos.push_back(10);
  ASSERT_TRUE(testFood.location == expectedPos);
}
