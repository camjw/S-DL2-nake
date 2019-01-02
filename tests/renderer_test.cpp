#include "renderer_test.h"

void RendererTest::SetUp() {
  pRenderer_ = new Renderer("Test", 100, 100, 10);
}

void RendererTest::TearDown() {
  delete pRenderer_;
}

TEST_F(RendererTest, PollingTest)
{
  SDL_Event event;
  pRenderer_->pollEvents(event);
  EXPECT_TRUE(!pRenderer_->isClosed());
}
