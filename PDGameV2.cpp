#include "PDGameV2.h"
#include <iostream>

PDGameV2::PDGameV2(const std::string& playerName)
    : PDGame(), m_playerName(playerName) {}

std::string PDGameV2::getPlayerName() const {
    return m_playerName;
}

void PDGameV2::playGame() {
    // Each call represents exactly one player's turn in the multiplayer game.
    m_myTurn.takeTurn();
    m_gameScore += m_myTurn.getScoreThisTurn();

    // The multiplayer controller checks this player's banked score immediately
    // after the turn and ends the game as soon as the first player reaches 50.
    m_gameOver = (m_gameScore >= 50);

    m_myTurn.resetTurnOver();
    m_myTurn.resetScoreThisTurn();
}

void PDGameV2::displayRules() const {
    std::cout << std::endl;
    std::cout << "Let's Play PIG Dice!" << std::endl;
    std::cout << std::endl;
    std::cout << "* See which player will reach 50 points in the fewest turns." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1" << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you save all points for the turn." << std::endl;
}
