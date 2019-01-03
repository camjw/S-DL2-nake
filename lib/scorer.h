#ifndef SCORER_H
#define SCORER_H
#include <fstream>

class Scorer {
  public:
    Scorer();
    virtual ~Scorer() {};
    int getHighScore();
    void loadHighScore();
    void setHighScore();
    void checkHighScore();
    void increaseScore();
    int getScore();
    void resetScore();

  private:
    int currentHighScore, currentScore;
};

#endif
