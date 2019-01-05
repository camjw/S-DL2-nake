#include "scorer_test.h"

ScorerTest::ScorerTest() {
};

void ScorerTest::SetUp() {
  pScorer_ = new Scorer(20);
}

void ScorerTest::TearDown() {
  delete pScorer_;
}

TEST_F(ScorerTest, IncreaseScore)
{
  pScorer_->increaseScore();
  EXPECT_EQ(pScorer_->getScore(), 10);
}

TEST_F(ScorerTest, IncreaseHighScore)
{
  for (int i = 0; i < 3; ++i) {
    pScorer_->increaseScore();
  }
  EXPECT_EQ(pScorer_->getHighScore(), 30);
}
