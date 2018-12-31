#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>

class Timer {
  public:
    Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    Uint32 getTicks();
    bool isStarted();
    bool isPaused();
    virtual ~Timer() {};

  private:
    Uint32 _StartTicks;
    Uint32 _PausedTicks;
    bool _Paused;
    bool _Started;
};

#endif
