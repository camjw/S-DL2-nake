#ifndef MOCK_SPEAKER_H
#define MOCK_SPEAKER_H
#include <gmock/gmock.h>
#include "../speaker.h"

class MockSpeaker : public Speaker {
  public:
    MockSpeaker();
    virtual ~MockSpeaker() {};
};

#endif
