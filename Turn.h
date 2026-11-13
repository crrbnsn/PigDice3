#ifndef TURN_H
#define TURN_H

#include "Die.h"

class Turn {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;

    void roll();

public:
    Turn();
    void takeTurn();
    int getScoreThisTurn() const;
    int getTurnCount() const;
    void resetTurnOver();
    void resetScoreThisTurn();
};

#endif
