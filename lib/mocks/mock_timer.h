#ifndef MOCK_TIMER_H
#define MOCK_TIMER_H
#include <gmock/gmock.h>
#include "../timer.h"

class MockTimer : public Timer {
  public:
    MockTimer();
    virtual ~MockTimer() {};
    MOCK_METHOD0(start, void());
};

#endif
