#include "Multiplayer.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

Multiplayer::Multiplayer() : m_gameOver(false) {
    int playerCount = 0;

    while (playerCount < 1) {
        std::cout << "How many people are playing? ";
        if (!(std::cin >> playerCount)) {
            if (std::cin.eof()) {
                m_gameOver = true;
                return;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            playerCount = 0;
            std::cout << "Please enter a whole number greater than 0." << std::endl;
        } else if (playerCount < 1) {
            std::cout << "Please enter a whole number greater than 0." << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int anonymousCount = 0;
    for (int i = 1; i <= playerCount; ++i) {
        std::string name;
        std::cout << "Enter player " << i << "'s name: ";

        if (!std::getline(std::cin, name)) {
            if (std::cin.eof()) {
                m_gameOver = true;
                return;
            }
        }

        if (name.empty()) {
            ++anonymousCount;
            name = "Anonymous Player " + std::to_string(anonymousCount);
        }

        m_players.emplace_back(name);
    }

    m_players.front().displayRules();
}

void Multiplayer::mpPlayGame() {
    while (!m_gameOver) {
        // Check for a winner immediately after each player's turn. The first
        // player to bank 50 or more points wins; later players do not take
        // another turn once that happens.
        for (PDGameV2& player : m_players) {
            std::cout << std::endl;
            std::cout << player.getPlayerName() << " (Score:" << player.getGameScore() << ")";
            player.playGame();

            if (std::cin.eof()) {
                m_gameOver = true;
                return;
            }

            displayScoreboard();
            checkForWinner();
            if (m_gameOver) {
                return;
            }
        }
    }
}

void Multiplayer::checkForWinner() {
    if (m_players.empty()) {
        m_gameOver = true;
        return;
    }

    // This function is called immediately after one player's turn, so the
    // first player found at 50+ is the player who just reached the target.
    for (const PDGameV2& player : m_players) {
        if (player.getGameScore() >= 50) {
            m_gameOver = true;
            std::cout << std::endl;
            std::cout << "Congratulations! " << player.getPlayerName()
                      << " you win with a score of " << player.getGameScore() << std::endl;
            return;
        }
    }
}

void Multiplayer::displayScoreboard() const {
    std::cout << std::endl;

    for (const PDGameV2& player : m_players) {
        std::cout << player.getPlayerName() << " (Score:" << player.getGameScore() << ") | ";
    }

    std::cout << std::endl;
}
