#include "background.h"

Background::Background(const Renderer &renderer, int width, int height, int stride) :
Renderer(renderer), _width(width), _height(height), _stride(stride) {
  if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  } else {
    Sans = TTF_OpenFont("assets/lazy.ttf", 20);
  }
}

Background::~Background() {
  TTF_Quit();
}

void Background::drawBackground() {
  SDL_RenderPresent(_renderer);
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
}

void Background::drawBorder() {
  SDL_Rect border_1 { _stride, _stride, (_height - 2) * _stride, (_height - 2)* _stride };
  SDL_Rect border_2 { _stride - 1, _stride - 1, (_height - 2)* _stride + 2, (_height - 2)* _stride + 2 };
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(_renderer, &border_1);
  SDL_RenderDrawRect(_renderer, &border_2);
}

const char* Background::getScoreString(int score) {
  std::string score_string = "Current score: " + std::to_string(score);
  const char* output = score_string.c_str();
  return output;
}

void Background::drawScore(int score) {
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, getScoreString(score), White);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);

  SDL_Rect Message_rect;
  Message_rect.x = 610;
  Message_rect.y = 10;
  Message_rect.w = 100;
  Message_rect.h = 20;

  SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
  getScoreString(score);
}

void Background::draw(int score) {
  drawBackground();
  drawBorder();
  drawScore(score);
}
