#ifndef MOCK_FOOD_H
#define MOCK_FOOD_H
#include <gmock/gmock.h>
#include "../food.h"
#include "mock_window.h"

class MockFood : public Food {
  public:
    MockFood(MockWindow &mock_window);
    virtual ~MockFood() {};
};

#endif
