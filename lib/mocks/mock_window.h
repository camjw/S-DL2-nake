#ifndef MOCK_WINDOW_H
#define MOCK_WINDOW_H
#include <gmock/gmock.h>
#include "../window.h"

class MockWindow : public Window {
  public:
    MockWindow();
    virtual ~MockWindow() {};
};

#endif
