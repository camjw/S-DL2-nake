#ifndef MOCK_TIMER_H
#define MOCK_TIMER_H
#include <gmock/gmock.h>
#include "../timer.h"

class MockTimer : public Timer {
  public:
    MockTimer();
    virtual ~MockTimer() {};
    MOCK_METHOD0(start, void());
    MOCK_METHOD0(stop, void());
    MOCK_METHOD0(pause, void());
    MOCK_METHOD0(unpause, void());
    MOCK_METHOD0(getTicks, Uint32());
    MOCK_METHOD0(isStarted, bool());
    MOCK_METHOD0(isPaused, bool());
};

#endif
