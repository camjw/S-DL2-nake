#include "timer_test.h"

void TimerTest::SetUp() {
  pTimer_ = new Timer();
}

void TimerTest::TearDown() {
  delete pTimer_;
}


TEST_F(TimerTest, StartedTest)
{
  pTimer_->start();
  EXPECT_TRUE(pTimer_->isStarted());
}

TEST_F(TimerTest, PausedTest)
{
  pTimer_->start();
  pTimer_->pause();
  EXPECT_TRUE(pTimer_->isPaused());
}
