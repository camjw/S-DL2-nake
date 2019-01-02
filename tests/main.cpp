#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "food_test.h"
#include "snake_test.h"
#include "timer_test.h"
#include "game_test.h"
#include "renderer_test.h"

int main(int argc, char **argv) {
  testing::InitGoogleMock(&argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
