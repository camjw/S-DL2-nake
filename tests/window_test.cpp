#include "window_test.h"

void WindowTest::SetUp() {
  pWindow_ = new Window("Test", 100, 100, 10);
}

void WindowTest::TearDown() {
  delete pWindow_;
}

TEST_F(WindowTest, PollingTest)
{
  SDL_Event event;
  pWindow_->pollEvents(event);
  EXPECT_TRUE(!pWindow_->isClosed());
}
