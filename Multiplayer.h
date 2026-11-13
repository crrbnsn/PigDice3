#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include "PDGameV2.h"
#include <vector>

class Multiplayer {
private:
    std::vector<PDGameV2> m_players;
    bool m_gameOver;

    void checkForWinner();
    void displayScoreboard() const;

public:
    Multiplayer();
    void mpPlayGame();
};

#endif
