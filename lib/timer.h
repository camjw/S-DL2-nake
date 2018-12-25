#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>

class Timer {
  public:
    Timer();
    virtual void start();
    virtual void stop();
    virtual void pause();
    virtual void unpause();
    virtual Uint32 getTicks();
    virtual bool isStarted();
    virtual bool isPaused();
    virtual ~Timer() {};

  private:
    Uint32 _StartTicks;
    Uint32 _PausedTicks;
    bool _Paused;
    bool _Started;
};

#endif
