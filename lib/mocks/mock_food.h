#ifndef MOCK_FOOD_H
#define MOCK_FOOD_H
#include <gmock/gmock.h>
#include "../food.h"
#include "mock_renderer.h"

class MockFood : public Food {
  public:
    MockFood(MockRenderer &mock_renderer);
    virtual ~MockFood() {};
    MOCK_METHOD0(getLocation, std::vector<int>());
    MOCK_METHOD1(resetLocation, void(std::deque<std::vector<int>>));
    MOCK_METHOD0(draw, void());
};

#endif
