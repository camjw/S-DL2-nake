#ifndef SCORER_H
#define SCORER_H
#include <fstream>

class Scorer {
  public:
    Scorer();
    Scorer(int highScore);
    virtual ~Scorer() {};
    int getHighScore();
    void loadHighScore();
    void setHighScore();
    void checkHighScore();
    void increaseScore();
    int getScore();
    void reset();

  private:
    int currentHighScore, currentScore;
};

#endif
