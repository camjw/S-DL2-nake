#include "scorer.h"
#include <iostream>

Scorer::Scorer() : currentScore(0), currentHighScore(30) {
  loadHighScore();
}

int Scorer::getHighScore() {
  return currentHighScore;
}

void Scorer::loadHighScore() {
  std::ifstream in(".assets/highscore.bin", std::ios::in | std::ios::binary);
  in.read((char*)&currentHighScore, sizeof(int));
  std::cout << currentHighScore;
}

void Scorer::setHighScore() {
  std::ofstream ofile(".assets/highscore.bin", std::ios::binary);
  ofile.write((char*) &currentScore, sizeof(int));
  currentHighScore = currentScore;
}

void Scorer::increaseScore() {
  currentScore += 10;
  if (currentScore > currentHighScore) {
    setHighScore();
  }
}

void Scorer::resetScore() {
  currentScore = 0;
}

int Scorer::getScore() {
  return currentScore;
}
