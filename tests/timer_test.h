#ifndef TIMER_TEST_H
#define TIMER_TEST_H
#include <gtest/gtest.h>
#include "../lib/timer.h"

class TimerTest : public ::testing::Test {
  public:
    virtual void SetUp();
    virtual void TearDown();
    Timer * pTimer_;
};

#endif
