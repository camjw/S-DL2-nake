#ifndef RENDERER_TEST_H
#define RENDERER_TEST_H
#include <gtest/gtest.h>
#include "../lib/renderer.h"

class RendererTest : public ::testing::Test {
  public:
    virtual void SetUp();
    virtual void TearDown();
    Renderer * pRenderer_;
};

#endif
