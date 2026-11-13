#ifndef PDGAME_H
#define PDGAME_H

#include "Turn.h"

class PDGame {
protected:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;
    virtual void displayRules() const;

public:
    PDGame();
    virtual ~PDGame() = default;

    int getGameScore() const;
    virtual void playGame();
};

#endif
