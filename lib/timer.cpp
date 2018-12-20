#include "timer.h"

Timer::Timer() :
_StartTicks(0), _PausedTicks(0), _Paused(false), _Started(false)
{
}

void Timer::start() {
  _Started = true;
  _Paused = false;
  _StartTicks = SDL_GetTicks();
  _PausedTicks = 0;
}

void Timer::stop() {
  _Started = false;
  _Paused = false;
  _StartTicks = 0;
  _PausedTicks = 0;
}

void Timer::pause() {
  if(_Started && !_Paused) {
    _Paused = true;
    _PausedTicks = SDL_GetTicks() - _StartTicks;
    _StartTicks = 0;
  }
}

void Timer::unpause() {
  if(_Started && _Paused) {
    _Paused = false;
    _StartTicks = SDL_GetTicks() - _PausedTicks;
    _PausedTicks = 0;
  }
}

Uint32 Timer::getTicks() {
  Uint32 time = 0;
  if (_Started) {
    if (_Paused) {
      time = _PausedTicks;
    } else {
      time = SDL_GetTicks() - _StartTicks;
    }
  }
  return time;
}

bool Timer::isStarted() {
  return _Started;
}

bool Timer::isPaused() {
  return _Paused && _Started;
}
