#ifndef PDGAMEV2_H
#define PDGAMEV2_H

#include "PDGame.h"
#include <string>

class PDGameV2 : public PDGame {
private:
    std::string m_playerName;

public:
    explicit PDGameV2(const std::string& playerName);

    std::string getPlayerName() const;
    void playGame() override;
    void displayRules() const override;
};

#endif
