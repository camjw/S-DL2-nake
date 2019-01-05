#ifndef SCORER_TEST_H
#define SCORER_TEST_H
#include <gtest/gtest.h>
#include "../lib/scorer.h"

class ScorerTest : public ::testing::Test {
  public:
    ScorerTest();
    virtual void SetUp();
    virtual void TearDown();
    Scorer * pScorer_;
};

#endif
