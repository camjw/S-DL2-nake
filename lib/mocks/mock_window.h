#ifndef MOCK_WINDOW_H
#define MOCK_WINDOW_H
#include <gmock/gmock.h>
#include <vector>
#include "../window.h"

class MockWindow : public Window {
  public:
    MockWindow();
    virtual ~MockWindow() {};
    MOCK_METHOD6(renderRect, void(std::vector<int> rectCoords, int stride, int r, int g, int b, int a));
};

#endif
