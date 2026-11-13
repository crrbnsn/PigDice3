#include "PDGame.h"
#include <iostream>

PDGame::PDGame() : m_myTurn(), m_gameOver(false), m_gameScore(0) {}

int PDGame::getGameScore() const {
    return m_gameScore;
}

void PDGame::displayRules() const {
    std::cout << "Let's Play PIG Dice!" << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score." << std::endl;
}

void PDGame::playGame() {
    displayRules();

    while (!m_gameOver) {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();

        if (m_gameScore >= 20) {
            m_gameOver = true;
        } else {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }

    std::cout << std::endl;
    std::cout << "You finished with a final score of " << m_gameScore
              << " in " << m_myTurn.getTurnCount() << " turns!" << std::endl;
    std::cout << "Thanks for playing PIG Dice!" << std::endl;
}
