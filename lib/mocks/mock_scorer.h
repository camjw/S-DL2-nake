#ifndef MOCK_SCORER_H
#define MOCK_SCORER_H
#include <gmock/gmock.h>
#include "../scorer.h"

class MockScorer : public Scorer {
  public:
    MockScorer();
    virtual ~MockScorer() {};
};

#endif
