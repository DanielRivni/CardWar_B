#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "deck.hpp"

#include <vector>

namespace ariel
{
    class Game
    {
    private:
        Player *p1;
        Player *p2;
        Deck *deck;
        std::vector<string> turns;

        // statistics
        float p1Wins;
        float p2Wins;
        float draws;

        string getWinner();

    public:
        Game(Player &player1, Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}

#endif