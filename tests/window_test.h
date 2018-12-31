#ifndef WINDOW_TEST_H
#define WINDOW_TEST_H
#include <gtest/gtest.h>
#include "../lib/window.h"

class WindowTest : public ::testing::Test {
  public:
    virtual void SetUp();
    virtual void TearDown();
    Window * pWindow_;
};

#endif
