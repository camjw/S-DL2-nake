#ifndef FOOD_TEST_H
#define FOOD_TEST_H
#include <gtest/gtest.h>
#include "../lib/food.h"
#include "../lib/mocks/mock_window.h"

class FoodTest : public ::testing::Test {
  public:
    FoodTest();
    Food subject;
    MockWindow mock_window;
};

#endif
