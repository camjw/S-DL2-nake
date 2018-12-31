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

TEST_F(TimerTest, StoppedTest)
{
  pTimer_->start();
  pTimer_->stop();
  EXPECT_TRUE(!pTimer_->isStarted());
}

TEST_F(TimerTest, StoppedPausedTest)
{
  pTimer_->start();
  pTimer_->pause();
  pTimer_->stop();
  EXPECT_TRUE(!pTimer_->isPaused());
}

TEST_F(TimerTest, UnpausedTest)
{
  pTimer_->start();
  pTimer_->pause();
  pTimer_->unpause();
  EXPECT_TRUE(!pTimer_->isPaused());
}

TEST_F(TimerTest, TicksTest)
{
  pTimer_->start();
  EXPECT_EQ(pTimer_->getTicks(), 0);
}
