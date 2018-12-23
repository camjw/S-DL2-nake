#ifndef FOOD_TEST_H
#define FOOD_TEST_H
#include <gtest/gtest.h>
#include <vector>
#include "../lib/food.h"

class FoodTest : public ::testing::Test {
  protected:
    Food testFood;
    void SetUp() override;
};

#endif
