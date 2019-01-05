#include "speaker.h"

Speaker::Speaker() {
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
      printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  foodFX = Mix_LoadWAV(".assets/sounds/food.wav");
  deathFX = Mix_LoadWAV(".assets/sounds/death.wav");
  highScoreFX = Mix_LoadWAV(".assets/sounds/highScore.wav");
}

Speaker::~Speaker() {
  Mix_FreeChunk(foodFX);
  foodFX = NULL;
  Mix_Quit();
}

void Speaker::getFood() {
   Mix_PlayChannel(-1, foodFX, 0);
}

void Speaker::death() {
  if (!deathPlayed) {
    Mix_PlayChannel(-1, deathFX, 0);
    deathPlayed = true;
  }
}

void Speaker::highScore() {
  if (!highScorePlayed) {
    Mix_PlayChannel(-1, highScoreFX, 0);
    highScorePlayed = true;
  }
}

void Speaker::reset() {
  deathPlayed = false;
  highScorePlayed = false;
}
