#include "Turn.h"
#include <iostream>
#include <limits>

Turn::Turn() : m_turnCount(0), m_scoreThisTurn(0), m_turnOver(false), m_choice('\0'), m_myDie() {}

void Turn::roll() {
    m_myDie.rollDie();
    std::cout << "Die: " << m_myDie.getDieValue();

    if (m_myDie.getDieValue() == 1) {
        std::cout << std::endl;
        std::cout << "Turn over. No score." << std::endl;
        m_scoreThisTurn = 0;
        m_turnOver = true;
    } else {
        m_scoreThisTurn += m_myDie.getDieValue();
        std::cout << " - Running score this turn: " << m_scoreThisTurn << std::endl;
    }
}

void Turn::takeTurn() {
    ++m_turnCount;
    std::cout << " - TURN " << m_turnCount << std::endl;

    while (!m_turnOver) {
        std::cout << "roll or hold? (r/h): ";

        if (!(std::cin >> m_choice)) {
            if (std::cin.eof()) {
                m_scoreThisTurn = 0;
                m_turnOver = true;
                break;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter r or h." << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (m_choice == 'r' || m_choice == 'R') {
            roll();
        } else if (m_choice == 'h' || m_choice == 'H') {
            m_turnOver = true;
        } else {
            std::cout << "Invalid choice. Please enter r or h." << std::endl;
        }
    }

    std::cout << "Score Banked This Turn: " << m_scoreThisTurn << std::endl;
}

int Turn::getScoreThisTurn() const {
    return m_scoreThisTurn;
}

int Turn::getTurnCount() const {
    return m_turnCount;
}

void Turn::resetTurnOver() {
    m_turnOver = false;
}

void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}
