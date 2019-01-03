#include <iostream>
#include <sstream>
#include "background.h"

Background::Background(const Renderer &renderer, int width, int height, int stride) :
Renderer(renderer), _width(width), _height(height), _stride(stride) {
  if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  } else {
    normalFont = TTF_OpenFont("assets/ARCADECLASSIC.ttf", 40);
    titleFont = TTF_OpenFont("assets/ARCADECLASSIC.ttf", 80);
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

char const * Background::getScoreChars(int score) {
  std::ostringstream buffer;
  buffer << score;
  return buffer.str().c_str();
}

void Background::drawScore(int score) {
  renderText("Current score", (_height) * _stride + _stride / 2, _stride * 5, 160, 30, false);
  renderText(getScoreChars(score), (_height) * _stride + _stride / 2, _stride * 6, 160, 160, true);
}

void Background::drawHighScore(int score) {
  renderText(" High score ", (_height) * _stride + _stride / 2, _stride * 14.5, 160, 30, false);
  renderText(getScoreChars(score), (_height) * _stride + _stride / 2, _stride * 15.5, 160, 160, true);
}

void Background::renderText(const char* text, int x, int y, int w, int h, bool title) {
  TTF_Font* renderedFont;
  if (title) {
    renderedFont = titleFont;
  } else {
    renderedFont = normalFont;
  }
  SDL_Surface* renderedSurface = TTF_RenderText_Solid(renderedFont, text, White);
  SDL_Texture* renderedTexture = SDL_CreateTextureFromSurface(_renderer, renderedSurface);
  SDL_Rect renderedRect { x, y, w, h };
  SDL_RenderCopy(_renderer, renderedTexture, NULL, &renderedRect);
}

void Background::drawTitle() {
  renderText("SNAKE", (_height) * _stride + _stride / 2 , _stride, 160, 60, true);
}

void Background::drawInstructions() {
  // should fix renderText function to allocate a certain width per character
  renderText("Arrows to move", (_height) * _stride + _stride / 2 , _stride * 24, 160, 30, false);
  renderText("Space to restart", (_height) * _stride + _stride / 2 , _stride * 25.5, 160, 30, false);
  renderText("Esc to quit", (_height) * _stride + _stride / 2 , _stride * 27, 160, 30, false);
}

void Background::draw(int score, int highScore) {
  drawBackground();
  drawBorder();
  drawTitle();
  drawInstructions();
  drawScore(score);
  drawHighScore(highScore);
}
