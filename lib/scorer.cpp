#include "scorer.h"
#include <iostream>

Scorer::Scorer() : currentScore(0), currentHighScore(0) {
  loadHighScore();
}

Scorer::Scorer(int highScore) : currentScore(0), currentHighScore(highScore) {
}

int Scorer::getHighScore() {
  return currentHighScore;
}

void Scorer::loadHighScore() {
  std::ifstream in(".assets/data/highscore.bin", std::ios::in | std::ios::binary);
  in.read((char*)&currentHighScore, sizeof(int));
}

void Scorer::setHighScore() {
  std::ofstream ofile(".assets/data/highscore.bin", std::ios::binary);
  ofile.write((char*) &currentScore, sizeof(int));
  currentHighScore = currentScore;
}

void Scorer::increaseScore() {
  currentScore += 10;
  if (currentScore > currentHighScore) {
    setHighScore();
  }
}

void Scorer::reset() {
  currentScore = 0;
}

int Scorer::getScore() {
  return currentScore;
}
