#ifndef FOOD_TEST_H
#define FOOD_TEST_H
#include <gtest/gtest.h>
#include "../lib/food.h"
#include "../lib/mocks/mock_renderer.h"

class FoodTest : public ::testing::Test {
  public:
    FoodTest();
    virtual void SetUp();
    virtual void TearDown();
    Food * pFood_;
    MockRenderer mock_renderer;
};

#endif
