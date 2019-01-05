#ifndef SPEAKER_H
#define SPEAKER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Speaker {
  public:
    Speaker();
    virtual ~Speaker();
    void highScore();
    void getFood();
    void death();
    void reset();

  private:
    Mix_Chunk *highScoreFX = NULL;
    Mix_Chunk *foodFX = NULL;
    Mix_Chunk *deathFX = NULL;
    bool deathPlayed = false;
    bool highScorePlayed = false;
};

#endif
